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
    char * bytes{ nullptr };

    SMessageFromClient()=delete;
    SMessageFromClient(SMessageFromClient& other) = delete;


    SMessageFromClient(uint64_t id, uint32_t len, char * b)
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
            if(head->len == length)
            {
                return head->msgid;
            }
        }
        return AE_INVALID_MESSAGE_ID;
    }
};

class MessageHandler
{
    public:
    virtual void Handle(const SMessageFromClient & msg) = 0;
};

using MessageList = std::list<struct SMessageFromClient>;
using MessangerManager = std::unordered_map<uint32_t , MessageHandler*>;//消息id-》处理者指针

class MessageCenter:public AETimer
{
public:
    MessageCenter(){};
    ~MessageCenter(){};
    DECLARE_SINGLETON(MessageCenter);

public:
    //添加msg
    virtual void AddMessage(SMessageFromClient &&  msg);

    //注册处理者
    virtual void RegisterHandler(uint32_t msgid, MessageHandler* hlder);

    //一个timer来驱动
    void OnProcess();

    void OnTimer(const asio::error_code& error, asio::steady_timer * timer, uint32_t mselapse) override 
    {
        OnProcess();
        AETimer::OnTimer(error, timer, mselapse);
    }

private:
    MessageList msg_list_;
    MessangerManager msg_handler_;
};



#endif