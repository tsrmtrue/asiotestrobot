#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__


#include <list>
#include <unordered_map>
#include "singleton.h"
#include "protocol_head.h"
#include "ae_timer.h"
#include "network_peer.h"


class PeerManager:public AETimer
{
public:
    PeerManager(){};
    ~PeerManager()
    {
        Release();
    };
    DECLARE_SINGLETON(PeerManager);

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
        for(auto & iter : map_all_peer_)
        {
            delete iter.second;
        }
        map_all_peer_.clear();
    }
	AsioPeer* GetPeer(uint64_t session_id)
	{
		auto iter = map_all_peer_.find(session_id);
		if (iter != map_all_peer_.end())
		{
			return iter->second;
		}
		return nullptr;
	}


private:
    using AllPeer = std::unordered_map< uint64_t, AsioPeer*>;
    AllPeer map_all_peer_;
};


#endif