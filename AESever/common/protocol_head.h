#ifndef __PROTOCOL_HEAD_H__
#define __PROTOCOL_HEAD_H__

#define AE_INVALID_MESSAGE_ID 0xffffffff
#pragma pack (4)
struct ClientProtocolHead
{
    uint32_t len;
    uint32_t msgid;
};

#pragma pack ()




#endif