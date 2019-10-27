//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
//#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <thread>
#include <chrono>
#include "asio.hpp"
#include "network_listener.h"
#include "message_center.h"
#include "ae_timer.h"
#include "ae_log.h"
#include "ptl_login.h"
#include "login_system.h"
#include "client_manager.h"

using asio::ip::tcp;

volatile bool main_threawd_exit = false;

void signal_handler(int sig)
{
    std::cout << "++++++signal handler" << std::endl;
    main_threawd_exit = true;

}

void asio_signal_handler(const asio::error_code & err, int sig)
{
    signal_handler(sig);
}

int main(int argc, char* argv[])
{
	try
	{
        //启动asio
        asio::io_service *pio_main_service = new asio::io_service();
        asio::io_service *pio_network_service = new asio::io_service();

        //设置关闭信号响应
        asio::signal_set sigset(*pio_main_service, SIGINT, SIGTERM);
        sigset.async_wait(asio_signal_handler);

        //单体创建
		AELogger::CreateInstance();
		AETimer::StartTimer(pio_main_service, AELogger::Instance(), 1000);
		AELogger::Instance()->InitStart();


		PeerManager::CreateInstance();
		AETimer::StartTimer(pio_main_service, PeerManager::Instance(), 100);

        //消息中心,创建timer
        MessageCenter::CreateInstance();

        AETimer::StartTimer(pio_main_service, MessageCenter::Instance(), 100);

        MessageCenter::Instance()->RegisterHandler((uint32_t )EMessage::MSG_LOGIN, new LoginMsgHdl );

        //网路
        AsioListener::CreateInstance();
        AsioListener::Instance()->Init(*pio_network_service,"127.0.0.1", 50000);

        //网络线程必须独立,消息通过枷锁传递.
        std::thread* network_thread = new std::thread([pio_network_service]() 
            {
                try
                {
                    while (1)
                    {
                        pio_network_service->run();
						auto i = 0;
						auto j = i + 1;
                    }
                }
                catch (std::exception& e)
                {
                    std::printf("Exception: %s\n", e.what());
                }

            } 
        );
        //逻辑线程
        std::thread* main_thread = new std::thread([pio_main_service]()
            {
                try
                {
                    while (1)
                    {
                        pio_main_service->run(); 
                    }
                }
                catch (std::exception& e)
                {
                    std::printf("Exception: %s\n", e.what());
                }
                int i = 0;
            } 
        );

        while(!main_threawd_exit)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        pio_network_service->stop();
		network_thread->join();

        pio_main_service->stop();
		main_thread->join();

        //关闭单体
        AsioListener::DestroyInstance();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
