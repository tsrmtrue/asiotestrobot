#include <iostream>
#include "login_system.h"
#include "ptl_login_decode4cpp.h"
#include "ptl_login_encode4cpp.h"
#include "network_peer.h"
#include "client_manager.h"

/*
------------------------------------
��¼ҵ��

1.�ͻ��˷���
2.����ת��
3.�˺����Ĵ�������

*/


bool LoginMsgHdl::Handle(const SMessageFromProtocol & msg)
{
    auto *bytes = msg.GetBody();
    auto len = msg.GetBodyLen();
    if (bytes && len)
    {
        SLogin s;
        if (decode_SLogin(s, bytes, len))
        {
            //��ӡ 
            std::cout << "message " << msg.session << " msg " << s.id<<std::endl;


			//����ȥ
				//�������
			LoginRspMsgSender rsp;
			rsp.login_rsp.id = s.id;
			rsp.login_rsp.result = 0x99;
			rsp.rpcid = msg.GetRpcId();//ҵ���߼��Լ������Ƿ���Ҫrpc

			auto * peer = PeerManager::Instance()->GetPeer(msg.session);
			//����
			SWriteMessage * m = new SWriteMessage;
			if (m && rsp.Pack(m))
			{
				peer->TryWrite(m);
			}
			else
			{
				return false;
			}


            return true;
        }
    }
    return false;
}

bool LoginRspMsgHdl::Handle(const SMessageFromProtocol & msg)
{
	auto *bytes = msg.GetBody();
	auto len = msg.GetBodyLen();
	if (bytes && len)
	{
		SLoginRsp s;
		if (decode_SLoginRsp(s, bytes, len))
		{
			//��ӡ 
			std::cout << "LoginRspMsgHdl message [" << msg.session << "] id [" << s.id <<"] login result ["<<s.result <<"]"<< std::endl;

			return true;
		}
	}
	return false;
}



int32_t LoginMsgSender::Pack(SWriteMessage * message)
{
	if (!message)
	{
		return -1;
	}
	auto len = encode_SLogin(login, message->GetBuffer2Pack(), message->GetLen2Pack());
	if (len)
	{
		message->SetPacket((uint32_t)len, (uint32_t)EMessage::MSG_LOGIN, rpcid);
	}
    return  len;
}

int32_t LoginRspMsgSender::Pack(SWriteMessage * message)
{
	if (!message)
	{
		return -1;
	}
	auto len = encode_SLoginRsp(login_rsp, message->GetBuffer2Pack(), message->GetLen2Pack());
	if (len)
	{
		message->SetPacket((uint32_t)len, (uint32_t)EMessage::MSG_LOGIN_RSP, rpcid);
	}
	return  len;
}


void DoLogin(AsioPeer* peer, int32_t id, int32_t passwd)
{
	if (!peer)
	{
		return;
	}

	//�������
	LoginMsgSender msg;
	msg.login.id = id;
	msg.login.password = passwd;
	msg.rpcid = MessageCenter::Instance()->GenerateRpcId();//ҵ���߼��Լ������Ƿ���Ҫrpc

	//����
	SWriteMessage * m = new SWriteMessage;
	if (m && msg.Pack(m))
	{
		peer->TryWrite(m);
	}
	else
	{
		if (m)
		{
			delete m;
		}
		return;
	}
	//����rpc�ص�����
	int magic = 0x332;
	MessageCenter::Instance()->AddRpcCallback(msg.rpcid, [magic](const SMessageFromProtocol & msg)
	{

		auto *bytes = msg.GetBody();
		auto len = msg.GetBodyLen();
		if (bytes && len)
		{
			SLoginRsp s;
			if (decode_SLoginRsp(s, bytes, len))
			{
				//��ӡ 
				std::cout << "magic number[" << magic << "]rpc callback message [" << msg.session << "] id [" << s.id<<"] result ["<<s.result<<"]" << std::endl;
			}
			
		}
	});

	//����rpc��ʱ����
}










