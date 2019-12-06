#include "timer_wheel_manager.h"

INSTANCE_SINGLETON(TimerWheelManager);



bool TimerWheelManager::Init()
{
    for (auto & wheel : total_timer_)
    {
        for (auto & timerlist : wheel)
        {
            timerlist.emplace_back(new TimerObj());
        }
    }
    return true;
};
void TimerWheelManager::Uninit()
{
    
};
