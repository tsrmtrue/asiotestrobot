// Copyright 2018 PingCAP, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// See the License for the specific language governing permissions and
// limitations under the License.

package reader

import (
	"go-common/library/log"

	"github.com/Shopify/sarama"
	pb "github.com/pingcap/tidb-tools/tidb_binlog/slave_binlog_proto/go-binlog"
	pkgerr "github.com/pkg/errors"
)

// KafkaSeeker seeks offset in kafka topics by given condition
type KafkaSeeker struct {
	consumer sarama.Consumer
	client   sarama.Client
}

// NewKafkaSeeker creates an instance of KafkaSeeker
func NewKafkaSeeker(addr []string, config *sarama.Config) (*KafkaSeeker, error) {
	client, err := sarama.NewClient(addr, config)
	if err != nil {
		return nil, pkgerr.WithStack(err)
	}

	consumer, err := sarama.NewConsumerFromClient(client)
	if err != nil {
		return nil, pkgerr.WithStack(err)
	}

	s := &KafkaSeeker{
		client:   client,
		consumer: consumer,
	}

	return s, nil
}

// Close releases resources of KafkaSeeker
func (ks *KafkaSeeker) Close() {
	ks.consumer.Close()
	ks.client.Close()
}

// Seek seeks the first offset which binlog CommitTs bigger than ts
func (ks *KafkaSeeker) Seek(topic string, ts int64, partitions []int32) (offsets []int64, err error) {
	if len(partitions) == 0 {
		partitions, err = ks.consumer.Partitions(topic)
		if err != nil {
			log.Error("tidb get partitions from topic %s error %v", topic, err)
			return nil, pkgerr.WithStack(err)
		}
	}

	offsets, err = ks.seekOffsets(topic, partitions, ts)
	if err != nil {
		err = pkgerr.WithStack(err)
		log.Error("tidb seek offsets error %v", err)
	}
	return
}

func (ks *KafkaSeeker) getTSFromMSG(msg *sarama.ConsumerMessage) (ts int64, err error) {
	binlog := new(pb.Binlog)
	err = binlog.Unmarshal(msg.Value)
	if err != nil {
		err = pkgerr.WithStack(err)
		return
	}

	return binlog.CommitTs, nil
}

// seekOffsets returns all valid offsets in partitions
func (ks *KafkaSeeker) seekOffsets(topic string, partitions []int32, pos int64) ([]int64, error) {
	offsets := make([]int64, len(partitions))
	for _, partition := range partitions {
		start, err := ks.client.GetOffset(topic, partition, sarama.OffsetOldest)
		if err != nil {
			err = pkgerr.WithStack(err)
			return nil, err
		}

		end, err := ks.client.GetOffset(topic, partition, sarama.OffsetNewest)
		if err != nil {
			err = pkgerr.WithStack(err)
			return nil, err
		}

		offset, err := ks.seekOffset(topic, partition, start, end-1, pos)
		if err != nil {
			err = pkgerr.WithStack(err)
			return nil, err
		}
		offsets[partition] = offset
	}

	return offsets, nil
}

func (ks *KafkaSeeker) seekOffset(topic string, partition int32, start int64, end int64, ts int64) (offset int64, err error) {
	startTS, err := ks.getTSAtOffset(topic, partition, start)
	if err != nil {
		err = pkgerr.WithStack(err)
		return
	}

	if ts < startTS {
		log.Warn("given ts %v is smaller than oldest message's ts %v, some binlogs may lose", ts, startTS)
		offset = start
		return
	} else if ts == startTS {
		offset = start + 1
		return
	}

	for start < end {
		mid := (end-start)/2 + start
		var midTS int64
		midTS, err = ks.getTSAtOffset(topic, partition, mid)
		if err != nil {
			err = pkgerr.WithStack(err)
			return
		}

		if midTS <= ts {
			start = mid + 1
		} else {
			end = mid
		}
	}

	var endTS int64
	endTS, err = ks.getTSAtOffset(topic, partition, end)
	if err != nil {
		err = pkgerr.WithStack(err)
		return
	}

	if endTS <= ts {
		return sarama.OffsetNewest, nil
	}

	return end, nil
}

func (ks *KafkaSeeker) getTSAtOffset(topic string, partition int32, offset int64) (ts int64, err error) {
	pc, err := ks.consumer.ConsumePartition(topic, partition, offset)
	if err != nil {
		err = pkgerr.WithStack(err)
		return
	}
	defer pc.Close()

	for msg := range pc.Messages() {
		ts, err = ks.getTSFromMSG(msg)
		err = pkgerr.WithStack(err)
		return
	}

	panic("unreachable")
}
