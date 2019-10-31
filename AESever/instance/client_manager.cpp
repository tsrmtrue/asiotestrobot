#include "client_manager.h"
#include "login_system.h"
#include "ptl_login.h"
INSTANCE_SINGLETON(PeerManager);

void PeerManager::OnProcess()
{
    static int32_t i = 0;
    //遍历客户端发送
    //for(auto *peer : map_all_peer_)
    //{
    //    if (peer->IsSocketBroken())
    //    {

    //    }
    //    else
    //    {
    //        LoginMsgSender msg;
    //        msg.login.id = ++i;

    //        SWriteMessage * m = new SWriteMessage;
    //        if (m)
    //        {
    //            int32_t len = msg.Pack(m);
    //            if (len)
    //            {
    //                m->SetPacket((uint32_t)len, (uint32_t)EMessage::MSG_LOGIN, 0 );
    //                peer->TryWrite(m);
    //            }
    //        }

    //    }
    //}
}

void PeerManager::AddClient(AsioPeer* peer)
{
    map_all_peer_[peer->GetSession()] = peer;
}


