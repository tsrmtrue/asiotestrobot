#ifndef __PROTOCOL_HEAD_H__
#define __PROTOCOL_HEAD_H__
#ifdef WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h> 
#endif

#define AE_INVALID_MESSAGE_ID 0xffffffff
#pragma pack (4)
struct ClientProtocolHead
{
	uint32_t len{ 0 };
	uint32_t msgid{ 0 };
	uint64_t rpcid{ 0 };

    //打包的时候使用
    inline void SetLen(uint32_t l)
    {
        len = htonl(l);
    }
	inline void SetMsgid(uint32_t mid)
	{
		msgid = htonl(mid);
	}
	inline void SetRpcid(uint64_t rid)
	{
		rpcid = rid;
	}
	//收包的时候使用
    inline uint32_t GetLen()
    {
        return ntohl(len);
    }
	inline uint32_t GetMsgid()
	{
		return ntohl(msgid);
	}
	inline uint64_t GetRpcid()
	{
		//return ntohll(rpcid);
		return rpcid;
	}

};

#pragma pack ()




#endif