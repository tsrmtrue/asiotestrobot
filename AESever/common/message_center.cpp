#include "message_center.h"
#include <chrono>
#include <iostream>
INSTANCE_SINGLETON(MessageCenter);

void MessageCenter::AddMessage(SMessageFromClient &&  msg)
{
    // msg_list_.push_back(msg);
}

void MessageCenter::RegisterHandler(uint32_t msgid, MessageHandler* hlder)
{
    msg_handler_[msgid] = hlder;
}

void MessageCenter::OnProcess()
{
    //std::cout<<"OnProcess"<< std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())<<std::endl;
    while(msg_list_.size() > 0)
    {
        const auto & msg = msg_list_.front();
        auto msgid = msg.GetMsgId();
        if (msgid != AE_INVALID_MESSAGE_ID)
        {
            auto * hlder = msg_handler_[msgid];
            if (hlder )
            {
                hlder->Handle(msg);
            }
        }
        msg_list_.pop_front();
    }
}



