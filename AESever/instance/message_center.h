#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <list>
#include <unordered_map>
#include <functional>
#include "singleton.h"
#include "protocol_head.h"
#include "ae_timer.h"
#include "ae_lock.h"
#include "network_peer.h"

struct SMessageFromProtocol    
{
    uint64_t session{ 0 };
    uint32_t length{ 0 };
    unsigned char * bytes{ nullptr };

    SMessageFromProtocol()=delete;
    SMessageFromProtocol(SMessageFromProtocol& other) = delete;


    SMessageFromProtocol(uint64_t id, uint32_t len, unsigned char * b)
    {
        session = id;
        bytes = b;
        length = len;
    }

    ~SMessageFromProtocol()
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

    SMessageFromProtocol(SMessageFromProtocol&& other)
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
	uint32_t GetRpcId() const
	{
		if (length >= sizeof(ClientProtocolHead))
		{
			auto * head = (ClientProtocolHead*)bytes;
			if (head->GetLen() == length)
			{
				return head->GetRpcid();
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
    virtual bool Handle(const SMessageFromProtocol & msg) = 0;
};

class MessagePacker
{
    public:
    virtual int32_t Pack(SWriteMessage* ) = 0;
};



using MessageList = std::list< SMessageFromProtocol>;
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
	
	inline uint64_t GenerateRpcId()
	{
		return ++rpc_id_generator_;
	}

	//rpc机制
	void AddRpcCallback(uint64_t rpcid, std::function<void (const SMessageFromProtocol&)> cb)
	{
		rpc_backcall[rpcid] = cb;
	}

	bool RunRpcCb(const SMessageFromProtocol& mp)
	{
		auto rpcid = mp.GetRpcId();
		auto iter = rpc_backcall.find(rpcid);
		if (iter != rpc_backcall.end())
		{
			iter->second(mp);
			//动态回调,用完就删掉.
			rpc_backcall.erase(rpcid);
			return true;
		}
		return false;
	}

private:
    MessageList msg_list_;
    MessageList msg_list_back_;
    MessangerManager msg_handler_;
    EasySpinLock spin_lock_;

	//rpc机制
	std::unordered_map<uint64_t, std::function<void (const SMessageFromProtocol&)> > rpc_backcall;
	uint64_t rpc_id_generator_{ 0 };
};



#endif