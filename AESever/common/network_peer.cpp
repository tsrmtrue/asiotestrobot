#include "network_peer.h"
#include "message_center.h"
#include <iostream>
uint64_t AsioPeer::global_idx_ = 0;

AsioPeer::~AsioPeer()
{

}

void AsioPeer::TryConnect(std::string ip, std::string port)
{
    tcp::resolver resolver_(io_service_);

    auto endpoint_iterator = resolver_.resolve({ ip.c_str(), port.c_str() });

    TryConnect(endpoint_iterator);
}

void AsioPeer::TryConnect(const tcp::resolver::iterator & endpoint_iterator)
{
    asio::async_connect(socket_, endpoint_iterator,
        [this, &endpoint_iterator](std::error_code ec, tcp::resolver::iterator)
    {
        if (!ec)
        {
            //投递监听
            TryRead();
        }
        else
        {
            //持续投递
            TryConnect(endpoint_iterator);
        }
    });

}

void AsioPeer::TryRead()
{
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
                //尝试解包

                //根据长度判断是否报文已经收满
                size_t packet_length = read_msg_big_.GetLen() ;
                if (packet_length > read_msg_big_.current_length_)
                {
                    break;
                }

                //报文已经足够解析
                char* _td_buff_ = new char[packet_length];
                memcpy(_td_buff_, read_msg_big_.buff_ + read_msg_big_.start_index_, packet_length);

                MessageCenter::Instance()->AddMessage(GetSession(), packet_length, (unsigned char *)_td_buff_);

                //todo 解压缩操作

                //指针投递到上层去处理，这个简单了，肯定要加上peerid信息

                //整理收缓冲区.
                read_msg_big_.current_length_ -= packet_length;
                read_msg_big_.start_index_ += packet_length;
            }

            if (read_msg_big_.start_index_ > MAX_RECV_BUFF_SIZE / 2)
            {
                //自紧操作
                memmove(read_msg_big_.buff_, read_msg_big_.buff_ + read_msg_big_.start_index_, read_msg_big_.current_length_);

                read_msg_big_.start_index_ = 0;
                std::cout << "memory move " << std::endl;
            }
            TryRead();
        }
        else
        {
            OnNetworkClose();
            socket_.close();
        }
    });
}

void AsioPeer::TryWrite(SWriteMessage* msg)
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

    io_service_.post(
        [this, msg]()
    {
        if (!this->IsSocketBroken())
        {
            bool write_in_progress = !this->write_msgs_.empty();

            this->write_msgs_.push_back(msg);
            if (!write_in_progress)
            {
                //防止反复投递
                this->DoWrite();
            }
        }
        else
        {
            delete msg;
        }
    });
}

void AsioPeer::DoWrite()
{
    if (write_msgs_.empty())
    {
        return;
    }
    //看看有么有乱序的情况
    asio::async_write(socket_,
        asio::buffer(write_msgs_.front()->Data2send(),
            write_msgs_.front()->Length2Send()),
        [this](asio::error_code ec, std::size_t length)
    {
        if (!ec || ec.value() == asio::error::would_block)
        {
            if (!write_msgs_.empty())
            {
                if (write_msgs_.front()->CheckSendOver(length))
                {
                    //全部发送完毕
                    auto * p = write_msgs_.front();
                    write_msgs_.pop_front();
                    delete p;
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
        }
    });
}

void AsioPeer::Close()
{
    if (IsSocketBroken())
    {
        OnNetworkClose();
        socket_.close();
        return;
    }
    try
    {
        //立即关闭套接字的收发,
        socket_.shutdown(tcp::socket::shutdown_both);
        //套接字的异步回调会立即回调
        socket_.cancel();

    }
    catch (const asio::system_error& e)
    {
    }
    io_service_.post([this]()
    {
        //逻辑关闭处理,清理缓冲区
        OnNetworkClose();
        //套接字本身关闭.
        socket_.close();
    });
}

void AsioPeer::CloseConnection()
{
    Close();
}

bool AsioPeer::IsCloseNetworkFinished()
{
    return IsSocketBroken();
}

void AsioPeer::OnNetworkClose()
{
    //缓冲区置零
    for (auto * msg : write_msgs_)
    {
        delete msg;
    }
    write_msgs_.clear();
}
