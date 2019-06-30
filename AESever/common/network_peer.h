#ifndef __NETWORK_PEER_H__
#define __NETWORK_PEER_H__
#include "asio.hpp"
#include <list>
#include <utility>
#include "protocol_head.h"
using asio::ip::tcp;

#define MAX_RECV_BUFF_SIZE (1024*512 )
#define MAX_SEND_BUFF_SIZE (1024*16)

//客户端发过来最多认为1k长度，否则认为受到攻击
#define MAX_MESSAGE_SIZE_FROM_CLIENT 1024 

//500毫秒处理一次消息
#define MESSAGE_HANDLER_TIMER_MILLISECOND 10 

//10秒更新一次profile
#define DO_PROFILE_TIMER_MILLISECOND 5000


struct SWriteMessage
{
    unsigned char buff_[MAX_SEND_BUFF_SIZE]{ 0 };
    std::size_t index_{ 0 };//起始坐标
    std::size_t count_{ 0 };//总的大小

    //投递使用
    void * Data2send()
    {
        return buff_ + index_;
    }
    std::size_t Length2Send()
    {
        return (count_ > index_) ? (count_ - index_) : 0;
    }
    bool CheckSendOver(std::size_t sent)
    {
        index_ += sent;
        return index_ >= count_;
    }
    //打包使用
    unsigned char* GetBuffer2Pack()
    {
        return buff_ + sizeof(ClientProtocolHead);
    }
    uint32_t GetLen2Pack()
    {
        return MAX_SEND_BUFF_SIZE - sizeof(ClientProtocolHead);
    }
    void SetPacket(uint32_t len, uint32_t msgid)
    {
        ClientProtocolHead* head = (ClientProtocolHead*)buff_;
        head->SetLen(len + sizeof(ClientProtocolHead));
        head->SetMsgid(msgid);
        count_ = len + sizeof(ClientProtocolHead);
    }
};

struct SReadMessageBig
{
    char buff_[MAX_RECV_BUFF_SIZE]{ 0 };
    size_t start_index_{ 0 };

     uint32_t GetLen()
     {
         ClientProtocolHead& head = *(ClientProtocolHead *)(buff_ + start_index_);
         return head.GetLen();
     }
     void Reset()
     {
         start_index_ = 0;
         current_length_ = 0;
     }

    uint32_t current_length_{ 0 };//每次缓冲区过半就memmove,自紧

    char * GetFreeBuff()
    {
        return buff_  + start_index_ + current_length_;
    };
    uint32_t GetLeftLength()
    {
        return (MAX_RECV_BUFF_SIZE > current_length_ + start_index_) ? (MAX_RECV_BUFF_SIZE - current_length_ + start_index_) : 0;
    }
};

using WriteMessageQueue = std::list<SWriteMessage*>;

class AsioPeer
{
public:
    AsioPeer(asio::io_service &sr, tcp::socket s) :io_service_(sr) ,socket_(std::move(s))
    {
        session_ = BuildSession();
    };
    virtual ~AsioPeer();

    void TryConnect(std::string ip, std::string port);
    void CloseConnection();    
    inline uint64_t GetSession()
    {
        return session_;
    }
    void OnConnected()
    {
        TryRead();
    } 
    void TryWrite(SWriteMessage* msg);
    bool IsSocketBroken()
    {
        return !socket_.is_open();
    }

private:
    void TryConnect(const tcp::resolver::iterator & endpoint_iterator);
    void TryRead();

    void DoWrite();

    void Close();
    bool IsCloseNetworkFinished();
    void OnNetworkClose();

    inline  uint64_t BuildSession()
    {
        global_idx_ ++;
        return (global_idx_ << 32) + socket_.native_handle();
    }

private:
    //asio封装
    asio::io_service &io_service_;
    tcp::socket socket_;
    WriteMessageQueue write_msgs_;
    SReadMessageBig read_msg_big_;//读大包,自己做解析
    static uint64_t global_idx_;
    uint64_t session_{ 0 };
};


#endif