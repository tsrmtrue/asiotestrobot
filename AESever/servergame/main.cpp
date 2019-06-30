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
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <thread>
#include "asio.hpp"
#include "network_listener.h"
#include "message_center.h"
#include "ae_timer.h"
#include "ptl_login.h"
#include "login_system.h"

using asio::ip::tcp;

volatile bool main_threawd_exit = false;

void signal_handler(int sig)
{
    std::cout << "++++++signal handler" << std::endl;
    main_threawd_exit = true;
}

void asio_signal_handler(const asio::error_code & err, int sig)
{
#ifdef WIN32
#else
    signal_handler(sig);
#endif // WIN32

}

int main(int argc, char* argv[])
{
	try
	{
        //启动asio
        asio::io_service *pio_service = new asio::io_service();

        //设置关闭信号响应
        asio::signal_set sigset(*pio_service, SIGINT, SIGTERM);
        sigset.async_wait(asio_signal_handler);

        //单体创建
        //消息中心,创建timer
        MessageCenter::CreateInstance();

        AETimer::StartTimer(pio_service, MessageCenter::Instance(), 100);

        MessageCenter::Instance()->RegisterHandler((uint32_t )EMessage::Msg_Login, new LoginMsgHdl );

        //网路
        AsioListener::CreateInstance();
        AsioListener::Instance()->Init(*pio_service,"127.0.0.1", 50000);

        while (!main_threawd_exit)
        {
            pio_service->run();
        }

        pio_service->stop();


        //关闭单体
        AsioListener::DestroyInstance();


        //asio放在工作者进程--仔细思考一下是否需要
        //std::thread* t = new std::thread([pio_service]()
        //{
        //    pio_service->run();
        //}
        //);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
