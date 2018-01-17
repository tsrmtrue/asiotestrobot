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

using asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client
{
public:
	chat_client(asio::io_service& io_service,
		tcp::resolver::iterator endpoint_iterator)
		: io_service_(io_service),
		socket_(io_service)
	{
		do_connect(endpoint_iterator);
	}

	void write(const chat_message& msg)
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

private:
	void do_connect(tcp::resolver::iterator endpoint_iterator)
	{
		asio::async_connect(socket_, endpoint_iterator,
			[this](std::error_code ec, tcp::resolver::iterator)
		{
			if (!ec)
			{
				do_read_header();
			}
		});
	}

	void do_read_header()
	{
		asio::async_read(socket_,
			asio::buffer(read_msg_.data(), chat_message::header_length),
			[this](std::error_code ec, std::size_t /*length*/)
		{
			if (!ec && read_msg_.decode_header())
			{
				do_read_body();
			}
			else
			{
				socket_.close();
			}
		});
	}

	void do_read_body()
	{
		asio::async_read(socket_,
			asio::buffer(read_msg_.body(), read_msg_.body_length()),
			[this](std::error_code ec, std::size_t /*length*/)
		{
			if (!ec)
			{
				std::cout.write(read_msg_.body(), read_msg_.body_length());
				std::cout << "\n";
				do_read_header();
			}
			else
			{
				socket_.close();
			}
		});
	}

	void do_write()
	{
		asio::async_write(socket_,
			asio::buffer(write_msgs_.front().data(),
				write_msgs_.front().length()),
			[this](std::error_code ec, std::size_t /*length*/)
		{
			if (!ec)
			{
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
	asio::io_service& io_service_;
	tcp::socket socket_;
	chat_message read_msg_;
	chat_message_queue write_msgs_;
};

void worker()
{
	try
	{
		asio::io_service io_service;
		tcp::resolver resolver(io_service);
		auto endpoint_iterator=resolver.resolve({ "127.0.0.1", "9999" });
		std::list<chat_client* > list_allclient;
		for (int i = 0; i < 1; ++i)
		{
			chat_client* c = new chat_client(io_service, endpoint_iterator);
			list_allclient.emplace_back(c);
		}
		int trycount = 0;
		char line[chat_message::max_body_length + 1] = "hello world";
			for(auto iter = list_allclient.begin(); iter != list_allclient.end(); ++iter)
			{
				chat_message msg;
				msg.body_length(std::strlen(line));
				std::memcpy(msg.body(), line, msg.body_length());
				msg.encode_header();
				(*iter)->write(msg);
				std::cout << trycount << " try send helloworld" << std::endl;
				trycount++;
			}
		while (1)
		{

			for(auto iter = list_allclient.begin(); iter != list_allclient.end(); ++iter)
			{
				chat_message msg;
				msg.body_length(std::strlen(line));
				std::memcpy(msg.body(), line, msg.body_length());
				msg.encode_header();
				(*iter)->write(msg);
				std::cout << trycount << " try send helloworld" << std::endl;
				trycount++;
			}
			// std::this_thread::sleep_for(std::chrono::microseconds(1));
		}

		for (auto * c : list_allclient)
		{
			c->close();
		}
		//t.join();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

int main(int argc, char* argv[])
{

	// asio::io_service io_service;

	// std::thread* t = new std::thread(worker);
	// for (int i = 0; i < 1; ++i)
	// {
	// }
	// while (1)
	// {
	// 	io_service.run();
	// 	std::this_thread::sleep_for(std::chrono::seconds(1));
	// }

	// t->join();


    asio::io_service io_service;

    tcp::resolver resolver(io_service);
    auto endpoint_iterator = resolver.resolve({ "127.0.0.1", "9999" });
    chat_client c(io_service, endpoint_iterator);

    std::thread t([&io_service](){ io_service.run(); });

    char line[chat_message::max_body_length + 1] = "hello world";
    while (1)
    {
      	chat_message msg;
      	msg.body_length(std::strlen(line));
      	std::memcpy(msg.body(), line, msg.body_length());
      	msg.encode_header();
      	c.write(msg);
		std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    c.close();
    t.join();



	return 0;
}
