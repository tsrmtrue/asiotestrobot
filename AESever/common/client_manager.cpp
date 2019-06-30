#include "client_manager.h"
#include "login_system.h"
#include "ptl_login.h"
INSTANCE_SINGLETON(ClientManager);

void ClientManager::OnProcess()
{
    static int32_t i = 0;
    //遍历客户端发送
    for(auto *peer : peer_list_)
    {
        if (peer->IsSocketBroken())
        {

        }
        else
        {
            LoginMsgSender msg;
            msg.login.id = ++i;

            SWriteMessage * m = new SWriteMessage;
            if (m)
            {
                auto len = msg.Pack(m->GetBuffer2Pack(), m->GetLen2Pack());
                if (len)
                {
                    m->SetPacket((uint32_t)len, (uint32_t)EMessage::Msg_Login );
                    peer->TryWrite(m);
                }
            }

        }
    }
}

void ClientManager::AddClient(AsioPeer* peer)
{
    peer_list_.push_back(peer);
}


