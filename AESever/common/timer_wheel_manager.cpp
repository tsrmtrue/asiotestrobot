#include <iostream>
#include "timer_wheel_manager.h"
#include "object_pool.h"
INSTANCE_SINGLETON(TimerWheelManager);

bool TimerObj::RunAndCalcTriggerNextTime()
{
    if (count == -1)
    {
        return true;
    }
    if (count == 0 || cd_ms == 0)
    {
        return false;
    }

    count--;

    static uint32_t check_count = 0;
    //如果设置count 1 那么就触发一次,, 

    if (check_count == 0)
    {
        check_count = next_cd;
    }

    if (check_count > next_cd)
    {
    }
    std::cout <<"error !！！！！！！！！！！！！！！！！！!!timer acculate elapse  ["<< next_cd << "]" <<std::endl;

    check_count = next_cd;
    next_cd += cd_ms;

    //debug 
    auto now = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(now - debug_next_triggle_time).count();
    if (diff > 1)
    {
        //std::cout <<"timer CD late !! "<< diff <<std::endl;
    }
    

    //debug 

    if(callback)
    {
        callback();
    }

    if (count == 0)
    {
        return false;
    }
    //处理cd
    debug_next_triggle_time += std::chrono::milliseconds(cd_ms);
    return true;
}


bool TimerWheelManager::Init()
{
    //for (auto & wheel : total_timer_)
    //{
    //    for (auto & timerlist : wheel)
    //    {
    //        timerlist.emplace_back(new TimerObj());
    //    }
    //}
    return true;
};
void TimerWheelManager::Uninit()
{
 
};

void TimerWheelManager::DebugDump()
{

    std::cout << std::endl;
    std::cout << "第一层" << std::endl;
    size_t i = 0;
    for (auto & timerlist : all_timer_wheel_[WHEEL_INDEX_1])
    {
        for (auto & timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }

    std::cout << "第二层" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_2])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }


    std::cout << "第三层" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_3])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }

    std::cout << "第四层" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_4])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }

}


TIMER_ID TimerWheelManager::AddTimer(uint32_t cdms, int32_t c, TimerCB cb)
{
    if ( cdms == 0 
        || cdms > MAX_VALID_CD_4 //32位永远不会溢出 
        || c == 0
        || cb == nullptr)
    {
        return INVALID_TIMER_ID;
    }
    auto timerobject = NEW_MEMORY(TimerObj, cdms, c, cb);
    if (!timerobject)
    {
        return INVALID_TIMER_ID;
    }
    if (all_timer_object_.find(timerobject ) != all_timer_object_.end())
    {
        abort();
        return INVALID_TIMER_ID;
    }
    if (InsertTimer(timerobject))
    {
        all_timer_object_[timerobject] = timerobject;
        return reinterpret_cast<TIMER_ID>((void*)timerobject);
    }
    //直接返回指针
    DELETE_MEMORY(timerobject);
    return INVALID_TIMER_ID;

}

void TimerWheelManager::TryKillTimer(TIMER_ID handle)
{
    auto to = reinterpret_cast<TimerObj*>(handle);
    if (to && all_timer_object_.find(to) != all_timer_object_.end())
    {
        //不考虑不再运行中的timer所有不在运行中，意味着插入的时候就应该处理，不会插入
        to->state = TimerState::TIMEROBJ_STATE_CLOSING;
    }
}


void TimerWheelManager::ReDispatchTimerList(TimerObjList list, uint32_t from_timer)//传一份拷贝过去，这个必然全部删掉，会重新插入
{
    for (auto& timerobj : list)
    {
        InsertTimer(timerobj, from_timer);
    }
}

void TimerWheelManager::RunTimerList(TimerObjList list)
{
    //注意传入的是一个临时拷贝，不用管队列本身的释放
    //算法保证，不会落到同样的层，就算绕过终点，超过本层最大容量，只会落入更上层。
    for (auto& timerobj : list)
    {
        if (timerobj->state == TimerState::TIMEROBJ_STATE_CLOSING)
        {   
            //已经删除了，退出
            DeleteTimerObj(timerobj);
        }

        if (timerobj->RunAndCalcTriggerNextTime())
        {
            //还需要执行，
            InsertTimer(timerobj);
        }
        else
        {
            //删除timer对象,次数满了，不需要执行了
            DeleteTimerObj(timerobj);
        }
    }
}

void TimerWheelManager::UpdateWheel(uint32_t from_timer)//这里会递归调用
{
    if (from_timer > WHEEL_INDEX_4)
    {
        return;
    }

    auto& index_wheel = timer_index_[from_timer];
    auto& timerwheel = all_timer_wheel_[from_timer];

    //先转动
    index_wheel = (index_wheel + 1) ;//
    bool cross_clock = ((index_wheel+1) % (WHEEL_LENGTH) == 0);

    auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

    //转动本层

    {
        //得到临时对象 
        TimerObjList temp = timerlist;
        //先清理
        timerlist.clear();
        //再执行
        if (from_timer == WHEEL_INDEX_1)
        {
            //第一层需要执行
            RunTimerList(temp);
        }
        else
        {
            //其他高级层需要重新发布到低级层
            ReDispatchTimerList(temp, from_timer);
        }

    }
    //if (from_timer == WHEEL_INDEX_1 && index_wheel != 0)
    //{
    //    //可以返回了
    //    return;
    //}

    //if (from_timer != WHEEL_INDEX_1 && index_wheel != 1)
    //{
    //    //可以返回了
    //    return;
    //}
    if (cross_clock)
    {
        UpdateWheel(from_timer + 1);
    }


    //if (from_timer > WHEEL_INDEX_1)
    //{
    //    //第二层开始，index默认要从1开始
    //    index_wheel += 1;
    //}
}

void TimerWheelManager::Update(uint64_t time_stampe)
{
    UpdateWheel(WHEEL_INDEX_1);
    now_time_++;
}

void TimerWheelManager::DeleteTimerObj(TimerObj* to)
{
    if (!to)
    {
        return;
    }
    if (all_timer_object_.find(to) != all_timer_object_.end())
    {
        all_timer_object_.erase(to);
    }
    DELETE_MEMORY(to);
}

bool TimerWheelManager::InsertTimer(TimerObj* to, uint32_t from_timer)
{
    //不管是调用以后重新执行，还是高层轮降级，都是在临时列表里执行，不会影响原本队列
    if (!to)
    {
        return false;
    }
    //auto cdms = to->next_cd - refresh_1_count * WHEEL_LENGTH;
    auto cdms = to->next_cd;
    //先根据from_timer裁剪 
    //重新插入的时候要考虑来源，如果是从上一层重新指派下来的，那么需要忽略上一层的时间，因为已经消耗掉了。

    if (from_timer == WHEEL_INDEX_4)
    {
        cdms = to->next_cd;
        cdms %= MAX_VALID_CD_3;
    }
    else if (from_timer == WHEEL_INDEX_3)
    {
        cdms = to->next_cd;
        cdms %= MAX_VALID_CD_2;
    }
    else if (from_timer == WHEEL_INDEX_2)
    {
        cdms = to->next_cd;
        cdms %= MAX_VALID_CD_1;
    }

    uint32_t idx = cdms; //

    uint32_t wheel_idx = 0;
    uint32_t left_shift = 0;
    if (cdms < MAX_VALID_CD_1)
    {
        wheel_idx = WHEEL_INDEX_1;
    }
    else if (cdms < MAX_VALID_CD_2)
    {
        left_shift =  1;
        wheel_idx = WHEEL_INDEX_2;
    }
    else if (cdms < MAX_VALID_CD_3)
    {
        wheel_idx = WHEEL_INDEX_3;
        left_shift = 1;
    }
    else if (cdms < MAX_VALID_CD_4)
    {
        wheel_idx = WHEEL_INDEX_4;
        left_shift = 1;
    }
    if (from_timer == WHEEL_COUNT_MAX)
    {
        //原生插入 
        for (auto i =0; i< wheel_idx; ++i)
        {
            idx = idx >> (WHEEL_BITS);
        }
        idx += timer_index_[wheel_idx];
    }

    // - left_shift+  WHEEL_LENGTH 
    idx = (idx ) % WHEEL_LENGTH;
    all_timer_wheel_[wheel_idx][idx].emplace_back(to);


    return true;
}

