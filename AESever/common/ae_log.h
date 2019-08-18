#ifndef __AE_LOGGER_H__
#define __AE_LOGGER_H__
#include <string>
#include <list>
#include <cassert>
#include <thread>
#include <iostream>
#include "singleton.h"
#include "ae_timer.h"
#include "ae_lock.h"

struct AELog
{
    uint32_t idx{0};
    std::string log;
    AELog(const char* str, uint32_t i)
    {
        log = str;
        idx = i;
    }
    AELog(const std::string & str, uint32_t i)
    {
        log = str;
        idx = i;
    }
};

class AELogger:public AETimer
{
public:
    using LIST_LOG = std::list<AELog>;
    AELogger()
    {
        
    };
    ~AELogger()
    {
        if(log_thread_)
        {
            log_thread_->join();
        }
    };
    DECLARE_SINGLETON(AELogger);


public:

    void AddLog(const char* str, uint32_t t)
    {
        //保证和OnExchange在同一个线程里,所以不用上锁
        temp_.emplace_back(str, t);
    }
    bool InitStart();

    void OnTimer(const asio::error_code& error, asio::steady_timer * timer, uint32_t mselapse) override 
    {
        OnExchange();
        AETimer::OnTimer(error, timer, mselapse);
    }
    //交换数据的timer
    void OnExchange()
    {
        if(exchange_lock_.TryLock())
        {
            if(working_.empty())
            {
                temp_.swap(working_);
            }
            exchange_lock_.UnLock();
        }
    }

public:
    //工作者
    void Worker()
    {
        while(1)
        {
            static uint32_t i = 0;
            if(exchange_lock_.TryLock())
            {
                for(auto & log : working_)
                {
                    assert(i++ == log.idx);
                }
                if (working_.size() > 0)
                {
                    std::cout<<"workder ["<<i<<"]"<<std::endl;

                }
                working_.clear();
                exchange_lock_.UnLock();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
private:
    LIST_LOG working_;
    LIST_LOG temp_;
    EasySpinLock exchange_lock_;
    std::thread* log_thread_;
};

#endif 