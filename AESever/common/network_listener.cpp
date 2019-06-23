#include "network_listener.h"
#include <iostream>
#include <utility>
#include "network_peer.h"

INSTANCE_SINGLETON(AsioListener);


bool AsioListener::Init(asio::io_service 
& ioservice, std::string ip, uint16_t port)
{
    tcp::endpoint endpoint(asio::ip::address::from_string(ip), port);
    ioservice_ = &ioservice;
    acceptor_  = new tcp::acceptor(ioservice, endpoint);
    std::cout<<"the local port is "<<acceptor_->local_endpoint().port();

    socket_ = new tcp::socket(ioservice);
    DoAccept();
    return true;
}

void AsioListener::UnInit()
{
    
}

void AsioListener::DoAccept()
{   
	acceptor_->async_accept(*socket_,
			[this](std::error_code ec)
		{
			if (!ec)
			{
                auto * peer = new AsioPeer(*ioservice_, std::move(*socket_));
                peer->OnConnected();
                std::cout<<" accept success "<<std::endl;
			}
            DoAccept();
		});
}