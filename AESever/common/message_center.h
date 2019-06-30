#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <list>
#include <unordered_map>
#include "singleton.h"
#include "protocol_head.h"
#include "ae_timer.h"

struct SMessageFromClient    
{
    uint64_t session{ 0 };
    uint32_t length{ 0 };
    unsigned char * bytes{ nullptr };

    SMessageFromClient()=delete;
    SMessageFromClient(SMessageFromClient& other) = delete;


    SMessageFromClient(uint64_t id, uint32_t len, unsigned char * b)
    {
        session = id;
        bytes = b;
        length = len;
    }

    ~SMessageFromClient()
    {
        Release();
    }
    void Release()
    {
        if (bytes)
        {
            delete bytes;
            length = 0;
            bytes = nullptr;
        }
    }

    SMessageFromClient(SMessageFromClient&& other)
    {
        session = other.session;
        Release();
        bytes = other.bytes;
        length = other.length;

        other.bytes = nullptr;
        other.length = 0;
    }

    uint32_t GetMsgId() const 
    {
        if(length >= sizeof(ClientProtocolHead))
        {
            auto * head = (ClientProtocolHead*)bytes;
            if(head->GetLen() == length)
            {
                return head->GetMsgid();
            }
        }
        return AE_INVALID_MESSAGE_ID;
    }
    unsigned char* GetBody() const
    {
        if (bytes && GetBodyLen() > 0)
        {
            return bytes + sizeof(ClientProtocolHead);
        }
        return nullptr;
    }
    uint32_t GetBodyLen() const
    {
        return length - sizeof(ClientProtocolHead);
    }
};

class MessageHandler
{
    public:
    virtual bool Handle(const SMessageFromClient & msg) = 0;
};

class MessagePacker
{
    public:
    virtual int32_t Pack(unsigned char * buf, uint32_t buflen) = 0;
};



using MessageList = std::list< SMessageFromClient>;
using MessangerManager = std::unordered_map<uint32_t , MessageHandler*>;//消息id-》处理者指针

class MessageCenter:public AETimer
{
public:
    MessageCenter(){};
    ~MessageCenter()
    {
        Release();
    };
    DECLARE_SINGLETON(MessageCenter);

public:
    //添加msg
    //virtual void AddMessage(SMessageFromClient &&  msg);
    virtual void AddMessage(uint64_t id, uint32_t len, unsigned char * b);
    //注册处理者
    virtual void RegisterHandler(uint32_t msgid, MessageHandler* hlder);

    //一个timer来驱动
    void OnProcess();

    void OnTimer(const asio::error_code& error, asio::steady_timer * timer, uint32_t mselapse) override 
    {
        OnProcess();
        AETimer::OnTimer(error, timer, mselapse);
    }

    void Release()
    {
        for(auto & iter : msg_handler_)
        {
            delete iter.second;
        }
        msg_handler_.clear();
    }

private:
    MessageList msg_list_;
    MessangerManager msg_handler_;
};



#endif