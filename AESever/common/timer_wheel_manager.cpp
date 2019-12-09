#include "timer_wheel_manager.h"

INSTANCE_SINGLETON(TimerWheelManager);

bool TimerObj::WillTriggerNextTime()
{
    if (count == -1)
    {
        return true;
    }
    if (count == 0 || cd == 0)
    {
        return false;
    }
    count--;
    //如果设置count 1 那么就触发一次
    if (count == 0)
    {
        return false;
    }
    //处理cd
    next_triggle_time += cd;
    return true;
}


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

TIMER_ID TimerWheelManager::AddTimer(TimerObj*to)
{
    if (  !to 
        || to->cd == 0 
        || to->count == 0)
    {
        return INVALID_TIMER_ID;
    }
    //
    if (to->next_triggle_time == 0)
    {
        to->next_triggle_time = now_time_ + to->cd;
    }
    uint64_t trigger_time = to->next_triggle_time > now_time_ ? to->next_triggle_time - now_time_: 0;
    uint32_t idx1 = trigger_time % (WHEEL_LENGTH);
    uint32_t idx2 = (trigger_time>> WHEEL_BITS) % (WHEEL_LENGTH);
    uint32_t idx3 = ((trigger_time >> WHEEL_BITS) >> WHEEL_BITS) % (WHEEL_LENGTH);
    uint32_t idx4 = (((trigger_time >> WHEEL_BITS) >> WHEEL_BITS) >> WHEEL_BITS);
    if (idx4 > 0)
    {
        outer_list_.push_back(to);
    }
    else if (idx3 > 0)
    {
        idx3 = (idx3 + timer_index_[WHEEL_INDEX_3])% WHEEL_LENGTH;
        total_timer_[WHEEL_INDEX_3][idx3].emplace_back(to);
    }
    else if (idx2 > 0)
    {
        idx2 = (idx2 + timer_index_[WHEEL_INDEX_2]) % WHEEL_LENGTH;
        total_timer_[WHEEL_INDEX_2][idx2].emplace_back(to);
    }
    else 
    {
        idx1 = (idx1 + timer_index_[WHEEL_INDEX_1]) % WHEEL_LENGTH;
        total_timer_[WHEEL_INDEX_1][idx1].emplace_back(to);
    }
    return to->id;
 
}

void TimerWheelManager::KillTimer(TIMER_ID handle)
{
    
}

