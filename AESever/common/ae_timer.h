#ifndef __AE_TIMER_H__
#define __AE_TIMER_H__
#include "asio.hpp"

class AETimer
{
public:
    virtual void OnTimer(const asio::error_code& error, asio::steady_timer * timer, uint32_t mselapse)
    {
        if (timer)
        {
            timer->expires_from_now(std::chrono::milliseconds(mselapse));

            timer->async_wait([this, error, timer, mselapse](const asio::error_code& error) 
            {
                OnTimer(error, timer, mselapse);
            });
        }

    }
    static void StartTimer(asio::io_service* io_service, class AETimer* aet, uint32_t mselapse)
    {
        if(io_service && aet)
        {
            asio::steady_timer * timer_ = new asio::steady_timer(*io_service);
            timer_->expires_from_now(std::chrono::milliseconds(mselapse));

            timer_->async_wait([aet, timer_,mselapse](const asio::error_code& error) 
            {
                aet->OnTimer(error, timer_, mselapse); 
            });
        }
    }
};

#endif