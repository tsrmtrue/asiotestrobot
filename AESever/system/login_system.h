#ifndef __LOGIN_SYSTEM__H__
#define __LOGIN_SYSTEM__H__
#include "ptl_login.h"
#include "message_center.h"

class LoginMsgHdl:public MessageHandler
{
public :
    bool Handle(const SMessageFromClient & msg) override;
};

class LoginMsgSender:public MessagePacker
{
public:
    int32_t Pack(unsigned char * buf, uint32_t buflen) override;

public:
    SLogin login;
};


#endif
