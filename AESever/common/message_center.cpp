#include "message_center.h"
#include <chrono>
#include <iostream>
#include "ae_log.h"
INSTANCE_SINGLETON(MessageCenter);

void MessageCenter::AddMessage(uint64_t id, uint32_t len, unsigned char * b)
{
    spin_lock_.Lock();
    msg_list_back_.emplace_back(id, len, b);
    spin_lock_.UnLock();

}


//void MessageCenter::AddMessage(SMessageFromClient &&  msg)
//{
//    msg_list_.push_back(msg);
//}

void MessageCenter::RegisterHandler(uint32_t msgid, MessageHandler* hlder)
{
    msg_handler_[msgid] = hlder;
}

void MessageCenter::OnProcess()
{
    spin_lock_.Lock();
    msg_list_back_.swap(msg_list_);
    spin_lock_.UnLock();


    static uint32_t total_count = 0;
    static uint32_t frame_count = 0;
    frame_count = 0;
    //std::cout<<"OnProcess"<< std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())<<std::endl;
    while (msg_list_.size() > 0)
    {
        const auto & msg = msg_list_.front();
        auto msgid = msg.GetMsgId();
        if (msgid != AE_INVALID_MESSAGE_ID)
        {
            auto * hlder = msg_handler_[msgid];
            if (hlder)
            {
                hlder->Handle(msg);
                total_count++;
                frame_count++;
            }
        }
        msg_list_.pop_front();
    }
    std::cout << "handle message total [" << total_count << "] frame [" << frame_count << "]"<<std::endl;


    //²âÊÔ·¢ËÍÊý¾Ý
    static uint32_t log_indx = 0;
    for(auto i=0; i<50000;++i)
    {
        AELogger::Instance()->AddLog("2323233", log_indx++);
    }

}


