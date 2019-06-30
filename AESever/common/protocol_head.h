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
    uint32_t len;
    uint32_t msgid;

    //打包的时候使用
    inline void SetLen(uint32_t l)
    {
        len = htonl(l);
    }
    inline void SetMsgid(uint32_t mid)
    {
        msgid = htonl(mid);
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

};

#pragma pack ()




#endif