#ifndef __NETWORK_CONNECTOR_H__
#define __NETWORK_CONNECTOR_H__
#include <string>
#include "singleton.h"
#include "asio.hpp"

using asio::ip::tcp;

class AsioConnector
{
public:
    AsioConnector() {};
    ~AsioConnector() { UnInit(); };
    DECLARE_SINGLETON(AsioConnector);

public:
    bool Init(asio::io_service & ioservice);
    void UnInit();
    void DoConnector(std::string ip, std::string port, uint32_t count);

private:
private:
    asio::io_service * ioservice_{ nullptr };
};

#endif // !__NETWORK_LISTENER_H__
