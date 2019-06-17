#include "robot_io_com.h"


CIO::CIO(CRobotClient &client, asio::io_service &io_service)
    : robot_client_(client), io_service_(io_service), socket_(io_service)
{
}

CIO::~CIO()
{
}


void CIO::TryWrite(SWriteMessage* msg)
{
    if (!msg)
    {
        return;
    }
    if (IsSocketBroken())
    {
        delete msg;
        return;
    }

    //if (msg->GetHeadLen() > 10000)
    //{
    //    RobotConfig::Instance()->AddLog(" msg size large than 10000 "  + std::to_string(msg->GetHeadLen()) );
    //}
    io_service_.post(
        [this, msg]()
    {
        if (!this->IsSocketBroken())
        {
            bool write_in_progress = !this->write_msgs_.empty();

            this->write_msgs_.push_back(msg);
            if (!write_in_progress)
            {
                //��ֹ����Ͷ��
                this->DoWrite();
            }
        }
        else
        {
            delete msg;
        }
    });
}


void CIO::DoWrite()
{
    //is_post_write_ = true;
    if (write_msgs_.empty())
    {
        return;
    }

    if (write_msgs_.front()->GetHeadLen() > 10000 || write_msgs_.front()->GetHeadLen() == 0)
    {
        assert(false);
    }

    //������ô����������

    if (current_write_msg_id_ > write_msgs_.front()->id_)
    {//��������
        assert(false);
    }
    else if (current_write_msg_id_ == write_msgs_.front()->id_ && current_write_msg_index_ > write_msgs_.front()->index_)
    {//��������
        assert(false);
    }


    current_write_msg_id_ = write_msgs_.front()->id_;
    current_write_msg_index_ = write_msgs_.front()->index_;



    asio::async_write(socket_,
        asio::buffer(write_msgs_.front()->Data2send(),
            write_msgs_.front()->Length2Send()),
        [this](asio::error_code ec, std::size_t length)
    {
        //is_post_write_ = false;
        if (!ec || ec.value() == asio::error::would_block)
        {
            if (!write_msgs_.empty())
            {
                if (write_msgs_.front()->CheckSendOver(length))
                {
                    //ȫ���������
                    auto * p = write_msgs_.front();
                    write_msgs_.pop_front();
                    delete p;

                    //ͳ�Ʒ�������,ȷʵ���ͳɹ�֮��
#ifdef WIN32
#else
                    WetestHttpHandler::Instance()->statistic_robot.send_pkg_total_num++;
#endif

                }

            }
            if (!write_msgs_.empty())
            {
                DoWrite();
            }
        }
        else
        {
            OnNetworkClose();
            socket_.close();
            //��Ϊ��״̬������
            robot_client_.ResetBtStatus(false);
            //�ϱ�
            WetestHttpHandler::Instance()->StartAndCommitTransInfo(robot_client_.GetRobotId(), "KickedByServer", 1, WETEST_SUCCESS);
        }
    });
}

void CIO::OnNetworkClose()
{
    //����������
    read_msg_.Reset();
    for (auto * msg : write_msgs_)
    {
        delete msg;
    }
    write_msgs_.clear();
    for (auto & msg : read_msgs)
    {
        msg.Release();
    }
    read_msgs.clear();
    //wetest�¼��ر�
    WetestHttpHandler::Instance()->CloseTransOnNetworkFailed(robot_client_.GetRobotId());

}

void CIO::Close()
{
    robot_client_.PushActionName(__func__);
    if (IsSocketBroken())
    {
        //��Ϊ����ʼ����ʱ�����һ���ղ���,Ϊ�������������������.
        OnNetworkClose();
        socket_.close();
        return;
    }
    try
    {
        //�����ر��׽��ֵ��շ�,
        socket_.shutdown(tcp::socket::shutdown_both);
        //�׽��ֵ��첽�ص��������ص�
        socket_.cancel();
        
    }
    catch (const asio::system_error& e)
    {
    }
    io_service_.post([this]()
    {
        //�߼��رմ���,��������
        OnNetworkClose();
        //�׽��ֱ���ر�.
        socket_.close();
    });
}


void CIO::TryConnect(std::string ip, std::string port, int targetState)
{
    robot_client_.PushActionName(__func__);

    tcp::resolver resolver_(io_service_);

    auto endpoint_iterator = resolver_.resolve({ ip.c_str(), port.c_str() });

    TryConnect(endpoint_iterator, targetState);
}

void CIO::CloseConnection()
{
    //�ж���Ϊ��
    Close();
}

bool CIO::IsCloseNetworkFinished()
{
    robot_client_.PushActionName(__func__);

    return IsSocketBroken();
    //return !is_post_read_ && !is_post_write_;
}

bool CIO::WaitReadMsgs(uint32_t protocal_id)
{
    while (!read_msgs.empty())
    {
        auto & msg = read_msgs.front();
        if (msg.GetType() == protocal_id)
        {
            return true;
        }
        read_msgs.pop_front();
    }

    return false;
}

void CIO::TryConnect(tcp::resolver::iterator endpoint_iterator, int targetState)
{
    asio::async_connect(socket_, endpoint_iterator,
        [this, targetState/*, start*/](std::error_code ec, tcp::resolver::iterator)
    {
        if (!ec)
        {
            //���ӳɹ�,��ʼ����һ������ģ��
            robot_client_.SetState(targetState);
            //Ͷ�ݼ���
            TryRead();
        }
        else
        {
            //���Ӳ���,����������,��rpc���ƿ��Ʒ���.
        }
    });
}


void CIO::TryRead()
{
    //std::cout << " ---------------try read body " << std::endl;
    if (IsSocketBroken())
    {
        return;
    }

    //is_post_read_ = true;
    asio::async_read(socket_
        , asio::buffer(read_msg_big_.GetFreeBuff(), read_msg_big_.GetLeftLength())
        , asio::transfer_at_least(1)
        , [this](std::error_code ec, std::size_t length)
    {
        //is_post_read_ = false;

        if (!ec)
        {
            read_msg_big_.current_length_ += length;
            while (read_msg_big_.current_length_ >= sizeof(ClientProtocolHead))
            {
                //std::cout << " ---------------read body " << length << std::endl;
                //���Խ��

                //����һ����ʱ��
                size_t packet_length = read_msg_big_.msg.GetLen() + sizeof(UINT32);
                if (packet_length > read_msg_big_.current_length_)
                {
                    break;
                }
                SReadMessage _t;
                memcpy(_t.buff_, read_msg_big_.msg.buff_ + read_msg_big_.msg.start_index_, packet_length);

                //�����ջ�����.
                read_msg_big_.current_length_ -= packet_length;
                //��������,һ�ֲ���
                //memmove(read_msg_big_.msg.buff_, read_msg_big_.msg.buff_ + packet_length, read_msg_big_.current_length_);
                //�����������
                read_msg_big_.msg.start_index_ += packet_length;
                if (_t.GetType() == RPCC2G_DOENTERSCENE_TYPE)
                {
                    int i = 0;
                }

                //�����¼�����
                if ((_t.GetFlag() & PTC_TYPE_COMPRESS) > 0)
                {
                    ZlibTool *pZlib = ZlibTool::Get();
                    pZlib->Clear();
                    if ((_t.GetFlag() & RPC_TYPE_FLAG) > 0)
                    {
                        if (pZlib->DeCompress(_t.GetRpcBody(), _t.GetRpcLength()))
                        {
                            _t.SetLen(pZlib->GetLength() + sizeof(ClientRpcHead) - sizeof(UINT32));
                            if ((uint32_t)pZlib->GetLength() > sizeof(_t))
                            {
                                assert(false);
                            }
                            memcpy(_t.GetRpcBody(), pZlib->GetBuffer(), pZlib->GetLength());
                        }
                        else
                        {//��ѹ��ʧ��.
                        }
                    }
                    else
                    {
                        if (pZlib->DeCompress(_t.GetPtcBody(), _t.GetPtcLength()))
                        {
                            _t.SetLen(pZlib->GetLength() + sizeof(ClientProtocolHead) - sizeof(UINT32));
                            if ((uint32_t)pZlib->GetLength() > sizeof(_t))
                            {
                                assert(false);
                            }
                            memcpy(_t.GetPtcBody(), pZlib->GetBuffer(), pZlib->GetLength());
                        }
                        else
                        {//��ѹ��ʧ��.
                        }

                    }

                }

                //������Ϣ
                //std::cout << "type: " << _t.GetType() << " " << PTCM2C_SYNCARENAROOMBRIEFINFONTF_TYPE << std::endl;
#ifdef WIN32
#else
                WetestHttpHandler::Instance()->statistic_robot.recv_pkg_total_num++;
#endif
                if (robot_client_.HandleBasicNtf(_t))
                {
                    //����notify���ٶ�����Ϊ������
                }
                else
                {
                    char* _td_buff_ = new char[_t.GetLen() + 4];
                    memcpy(_td_buff_, _t.buff_, _t.GetLen() + 4);
                    read_msgs.emplace_back(_td_buff_);


                }
            }

            if (read_msg_big_.msg.start_index_ > MAX_RECV_BUFF_SIZE / 2)
            {
                memmove(read_msg_big_.msg.buff_, read_msg_big_.msg.buff_ + read_msg_big_.msg.start_index_, read_msg_big_.current_length_);

                read_msg_big_.msg.start_index_ = 0;

            }

            TryRead();
        }
        else
        {
            OnNetworkClose();
            socket_.close();
            //��Ϊ��״̬������
            robot_client_.ResetBtStatus(false);
            //�ϱ�
            WetestHttpHandler::Instance()->StartAndCommitTransInfo(robot_client_.GetRobotId(), "KickedByServer", 1, WETEST_SUCCESS);
        }
    });
}


void CIO::ClearLastNetMessage()
{
    //PushActionName(__func__);

    read_msgs.clear();
}
