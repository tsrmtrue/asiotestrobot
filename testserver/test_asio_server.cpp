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
#include "asio.hpp"
#include "chat_message.hpp"

using asio::ip::tcp;

//----------------------------------------------------------------------


struct SMessage
{
	char buff[512]{ 0 };
	std::size_t count{ 0 };
};

typedef std::deque<SMessage> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
	virtual ~chat_participant() {}
	virtual void deliver(const SMessage& msg) = 0;
};

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
	void join(chat_participant_ptr participant)
	{
		participants_.insert(participant);
		for (auto msg : recent_msgs_)
			participant->deliver(msg);
	}

	void leave(chat_participant_ptr participant)
	{
		participants_.erase(participant);
	}

	void deliver(const SMessage& msg)
	{
		recent_msgs_.push_back(msg);
		while (recent_msgs_.size() > max_recent_msgs)
			recent_msgs_.pop_front();

		for (auto participant : participants_)
			participant->deliver(msg);

		std::cout << message_count << "chat message  " << msg.buff << std::endl;
		message_count++;
	}

private:
	std::set<chat_participant_ptr> participants_;
	enum { max_recent_msgs = 100 };
	chat_message_queue recent_msgs_;
	int message_count{ 0 };
};

//----------------------------------------------------------------------

class chat_session
	: public chat_participant,
	public std::enable_shared_from_this<chat_session>
{
public:
	chat_session(tcp::socket socket, chat_room& room)
		: socket_(std::move(socket)),
		room_(room)
	{
	}

	void start()
	{
		room_.join(shared_from_this());
		do_read_header();
	}

	void deliver(const SMessage& msg)
	{
		bool write_in_progress = !write_msgs_.empty();
		write_msgs_.push_back(msg);
		if (!write_in_progress)
		{
			do_write();
		}
	}

private:
	void do_read_header()
	{
		auto self(shared_from_this());
		asio::async_read(socket_,
			asio::buffer(read_msg_.buff, sizeof(read_msg_.buff)),
			[this, self](std::error_code ec, std::size_t length)
		{
			if (!ec )
			{
				read_msg_.count = length;
				room_.deliver(read_msg_);

				do_read_header();
			}
			else
			{
				room_.leave(shared_from_this());
			}
		});
	}

	//void do_read_body()
	//{
	//	auto self(shared_from_this());
	//	asio::async_read(socket_,
	//		asio::buffer(read_msg_.body(), read_msg_.body_length()),
	//		[this, self](std::error_code ec, std::size_t /*length*/)
	//	{
	//		if (!ec)
	//		{
	//			room_.deliver(read_msg_);
	//			do_read_header();
	//		}
	//		else
	//		{
	//			room_.leave(shared_from_this());
	//		}
	//	});
	//}

	void do_write()
	{
		auto self(shared_from_this());
		asio::async_write(socket_,
			asio::buffer(write_msgs_.front().buff,
				write_msgs_.front().count),
			[this, self](std::error_code ec, std::size_t /*length*/)
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
				room_.leave(shared_from_this());
			}
		});
	}

	tcp::socket socket_;
	chat_room& room_;
	SMessage read_msg_;
	chat_message_queue write_msgs_;
};

//----------------------------------------------------------------------

class chat_server
{
public:
	chat_server(asio::io_service& io_service,
		const tcp::endpoint& endpoint)
		: acceptor_(io_service, endpoint),
		socket_(io_service)
	{
		do_accept();
	}

private:
	void do_accept()
	{
		acceptor_.async_accept(socket_,
			[this](std::error_code ec)
		{
			if (!ec)
			{
				std::make_shared<chat_session>(std::move(socket_), room_)->start();
			}

			do_accept();
		});
	}

	tcp::acceptor acceptor_;
	tcp::socket socket_;
	chat_room room_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
	try
	{

		asio::io_service io_service;

		std::list<chat_server> servers;
		{
			tcp::endpoint endpoint(tcp::v4(), std::atoi("9999"));
			servers.emplace_back(io_service, endpoint);
		}

		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
