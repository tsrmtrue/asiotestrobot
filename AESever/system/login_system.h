#ifndef __LOGIN_SYSTEM__H__
#define __LOGIN_SYSTEM__H__
#include "ptl_login.h"
#include "message_center.h"
#include "network_peer.h"

class LoginMsgHdl:public MessageHandler
{
public :
    bool Handle(const SMessageFromProtocol & msg) override;
};

class LoginRspMsgHdl :public MessageHandler
{
public:
	bool Handle(const SMessageFromProtocol & msg) override;
};



class LoginMsgSender:public MessagePacker
{
public:
    int32_t Pack(SWriteMessage * message) override;

public:
    SLogin login;
	uint64_t rpcid{ 0 };
};

class LoginRspMsgSender :public MessagePacker
{
public:
	int32_t Pack(SWriteMessage * message) override;

public:
	SLoginRsp login_rsp;
	uint64_t rpcid{ 0 };
};

//µÇÂ¼¹ý³Ì
void DoLogin(AsioPeer* peer, int32_t id, int32_t passwd);



#endif
