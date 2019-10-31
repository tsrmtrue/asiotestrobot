#include "network_connector.h"
#include <iostream>
#include <utility>
#include "network_peer.h"

INSTANCE_SINGLETON(AsioConnector);


bool AsioConnector::Init(asio::io_service 
& ioservice)
{
    //tcp::endpoint endpoint(asio::ip::address::from_string(ip), port);
    ioservice_ = &ioservice;
    //acceptor_  = new tcp::acceptor(ioservice, endpoint);
    //std::cout<<"the local port is "<<acceptor_->local_endpoint().port();

    //socket_ = new tcp::socket(ioservice);
    //DoAccept();
    return true;
}

void AsioConnector::UnInit()
{
    
}

void AsioConnector::DoConnector(std::string ip, std::string  port, uint32_t count)
{   
    for (auto i=0; i < count; ++i)
    {
        auto * peer = new AsioPeer(*ioservice_, tcp::socket(*ioservice_));
        if (peer)
        {
            peer->TryConnect(ip, port);
        }

    }
    
}