#ifndef __NETWORK_LISTENER_H__
#define __NETWORK_LISTENER_H__
#include <string>
#include "singleton.h"
#include "asio.hpp"
using asio::ip::tcp;

class AsioListener
{
public:
    AsioListener() {};
    ~AsioListener() { UnInit(); };
    DECLARE_SINGLETON(AsioListener);

public:
    bool Init(asio::io_service & ioservice, std::string ip, uint16_t port);
    void UnInit();


private:
    void DoAccept();
private:
    tcp::acceptor* acceptor_{nullptr};
    asio::io_service * ioservice_{ nullptr };
    tcp::socket *socket_{nullptr};

};

#endif // !__NETWORK_LISTENER_H__
