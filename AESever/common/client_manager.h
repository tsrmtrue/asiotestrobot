#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__


#include <list>
#include <unordered_map>
#include "singleton.h"
#include "protocol_head.h"
#include "ae_timer.h"
#include "network_peer.h"


class ClientManager:public AETimer
{
public:
    ClientManager(){};
    ~ClientManager()
    {
        Release();
    };
    DECLARE_SINGLETON(ClientManager);

public:
    //添加msg
    //virtual void AddMessage(SMessageFromClient &&  msg);
    virtual void AddClient(AsioPeer* peer);

    //一个timer来驱动
    void OnProcess();

    void OnTimer(const asio::error_code& error, asio::steady_timer * timer, uint32_t mselapse) override 
    {
        OnProcess();
        AETimer::OnTimer(error, timer, mselapse);
    }

    void Release()
    {
        for(auto & iter : peer_list_)
        {
            delete iter;
        }
        peer_list_.clear();
    }

private:
    using ClientList = std::list<AsioPeer*>;
    ClientList peer_list_;
};


#endif