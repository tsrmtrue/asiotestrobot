//
// chat_client.cpp
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
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds
#include "asio.hpp"
#include "chat_message.hpp"
#include "types/behaviac_types.h"

using asio::ip::tcp;

//typedef basic_waitable_timer<boost::posix_time::ptime> my_deadline_timer;

class CRobotClient;

class CWorkFrame
{
public:
	CWorkFrame(CRobotClient& c) :client_(c) {};
	virtual bool OnRun() {};
private :
	CRobotClient & client_;
};

class CWordFrameTimer :public CWorkFrame
{
public :
	using CWorkFrame::CWorkFrame;
public:
	bool OnRun() override
	{
		return true;
	};
};

struct SMessage
{
	char buff[512]{ 0 };
	std::size_t count{ 0 };
};
using  MessageQueue = std::deque<SMessage>;

class CRobotClient
{
	//测试机器人执行特定的工作帧
	//工作帧  类型为, 可以扩充
		//发送一个协议,
		//等待一个协议,
		//等待时间
	//一段特定的工作帧组合,就是一个具体测试模块,可以有脚本生成.
public:
	CRobotClient(asio::io_service& io_service,
		tcp::resolver::iterator endpoint_iterator)
		: io_service_(io_service),
		socket_(io_service),
		timer_(io_service)

	{
		do_connect(endpoint_iterator);
	}

	void write(const SMessage& msg)
	{
		io_service_.post(
			[this, msg]()
		{
			bool write_in_progress = !write_msgs_.empty();
			write_msgs_.push_back(msg);
			if (!write_in_progress)
			{
				do_write();
			}
		});
	}

	void close()
	{
		io_service_.post([this]() { socket_.close(); });
	}
	void onRun()
	{

	}

	void update_frame(const asio::error_code& error)
	{
		//每一帧调用
		if (!error)
		{
			// Timer expired.
			std::cout << " timer handler " << std::endl;

			timer_.expires_from_now(std::chrono::seconds(10));
			timer_.async_wait([this](const asio::error_code& error) {this->update_frame(error); });
		}

	}

private:
	void do_connect(tcp::resolver::iterator endpoint_iterator)
	{
		asio::async_connect(socket_, endpoint_iterator,
			[this](std::error_code ec, tcp::resolver::iterator)
		{
			if (!ec)
			{
				//链接成功,初始化第一个测试模块
				//测试定时器
				timer_.expires_from_now(std::chrono::seconds(10));
				timer_.async_wait([this](const asio::error_code& error) {this->update_frame(error); });
				try_read();
			}
		});
	}

	void try_read()
	{
		asio::async_read(socket_,
			asio::buffer(read_msg_.buff, sizeof(read_msg_.buff)),
			[this](std::error_code ec, std::size_t /*length*/)
		{
			if (!ec )
			{
				try_read();
			}
			else
			{
				socket_.close();
			}
		});
	}


	int trycount = 0;
	void do_write()
	{
		asio::async_write(socket_,
			asio::buffer(write_msgs_.front().buff,
				write_msgs_.front().count),
			[this](std::error_code ec, std::size_t /*length*/)
		{
			if (!ec)
			{
				std::cout << trycount << " try send "<< write_msgs_.front().buff << std::endl;
				trycount++;

				write_msgs_.pop_front();
				if (!write_msgs_.empty())
				{
					do_write();
				}
			}
			else
			{
				socket_.close();
			}
		});
	}

private:
	asio::steady_timer timer_;
	asio::io_service& io_service_;
	tcp::socket socket_;
	MessageQueue write_msgs_;
	std::list<CWorkFrame*> work_todo_;

	SMessage read_msg_;
};


int main(int argc, char* argv[])
{


    asio::io_service io_service;

    tcp::resolver resolver(io_service);

	std::list<CRobotClient* > list_allclient;
    auto endpoint_iterator = resolver.resolve({ "127.0.0.1", "9999" });
	for (int i = 0; i < 1000; ++i)
	{
		auto* c = new CRobotClient(io_service, endpoint_iterator);
		list_allclient.emplace_back(c);
	}

	std::list<std::thread * > threadpool;
	for(int i = 0; i<1; ++i)
	{
		std::thread* t = new std::thread([&io_service]() { while (1) { io_service.run(); } });
		threadpool.push_back(t);
	}
	SMessage s;
	sprintf(s.buff, "helloworld");
	s.count = strlen("helloworld");

    while (1)
    {
		for (auto * c : list_allclient)
		{
			c->write(s);
		}

		std::this_thread::sleep_for(std::chrono::seconds(2));
    }
	for (auto * c : list_allclient)
	{
		c->close();
	}
	for (auto * t: threadpool)
	{
		t->join();
	}

	return 0;
}
