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
    if (count == 0 || set_cd_ms == 0)
    {
        return false;
    }

    count--;

    static uint32_t check_count = 0;
    //如果设置count 1 那么就触发一次,, 

    if (check_count == 0)
    {
        check_count = total_cd;
    }

    if (check_count > total_cd)
    {
    }
    std::cout <<"error !！！！！！！！！！！！！！！！！！!!timer acculate elapse  ["<< total_cd << "]" <<std::endl;

    check_count = total_cd;
    total_cd += set_cd_ms;
    next_cd = set_cd_ms;

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
    debug_next_triggle_time += std::chrono::milliseconds(set_cd_ms);
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
    std::cout << "当前时钟 " << "[" << timer_index_[WHEEL_INDEX_1] << "]" << "[" << timer_index_[WHEEL_INDEX_2] << "]" << "[" << timer_index_[WHEEL_INDEX_3] << "]" << "[" << timer_index_[WHEEL_INDEX_4] << "]"  << std::endl;

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
        MoveOnTimer(timerobj, from_timer);
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
    bool cross_clock = false; 
    if (from_timer == WHEEL_INDEX_1)
    {
        auto& index_wheel = timer_index_[from_timer];
        auto& timerwheel = all_timer_wheel_[from_timer];
        auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

        //得到临时对象 
        TimerObjList temp = timerlist;
        timerlist.clear();
        RunTimerList(temp);
        index_wheel = (index_wheel + 1) % (WHEEL_LENGTH);//

        cross_clock = (index_wheel == 0);
    }
    else
    {
        auto& index_wheel = timer_index_[from_timer];
        index_wheel = (index_wheel + 1) % (WHEEL_LENGTH);//

        auto& timerwheel = all_timer_wheel_[from_timer];

        auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

        //得到临时对象 
        TimerObjList temp = timerlist;
        timerlist.clear();
        ReDispatchTimerList(temp, from_timer);

        cross_clock = (index_wheel == 0);
    }
    //后转动
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

//当拨动时间轮，这里的时间片降级
bool TimerWheelManager::MoveOnTimer(TimerObj* to, uint32_t from_timer)
{
    if (!to)
    {
        return false;
    }

    InsertTimer(to, from_timer);

    //先根据from_timer裁剪 
    //重新插入的时候要考虑来源，如果是从上一层重新指派下来的，那么需要忽略上一层的时间，因为已经消耗掉了。

    //[0-9, 10-99, 100-999, 1000-9999]
    //[10   100    1000     10000]
    // 假设有  1566，第四级  1  实际-1 0  
    // 降级     566  第三级  5  实际-1 4
    // 降级      66  第二级  6  实际-1 5
    // 降级       6  第一级  6  实际 6
    //uint32_t wheel_idx = 0;
    //uint32_t idx = 0; //

    //if (from_timer == WHEEL_INDEX_4)
    //{
    //    //to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_4])*MAX_VALID_CD_3;
    //    InsertTimer(to);
    //}
    //else if (from_timer == WHEEL_INDEX_3)
    //{
    //    to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_3])* MAX_VALID_CD_2;
    //    InsertTimer(to);
    //}
    //else if (from_timer == WHEEL_INDEX_2)
    //{
    //    to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_3])* MAX_VALID_CD_2;
    //    to->next_cd = to->total_cd % MAX_VALID_CD_1;
    //    InsertTimer(to);
    //}


}

bool TimerWheelManager::InsertTimer(TimerObj* to, uint32_t from_timer)
{
    //不管是调用以后重新执行，还是高层轮降级，都是在临时列表里执行，不会影响原本队列
    if (!to || to->next_cd >= MAX_VALID_CD_4)
    {
        return false;
    }

    //递进指针
    uint64_t total_now = 0;
    uint32_t wheel_lenth = 1;
    for (uint32_t i = 0 ; i < from_timer; ++i)
    {
        total_now += timer_index_[i] * (wheel_lenth);
        wheel_lenth *= WHEEL_LENGTH;
    }
    //uint32_t wheel_time_1 = timer_index_[WHEEL_INDEX_1];
    //uint32_t wheel_time_2 = timer_index_[WHEEL_INDEX_2];
    //uint32_t wheel_time_3 = timer_index_[WHEEL_INDEX_3];
    //uint32_t wheel_time_4 = timer_index_[WHEEL_INDEX_4];
    uint32_t wheel_idx = WHEEL_INDEX_1;

    //uint64_t total_now = wheel_time_1 + wheel_time_2 * MAX_VALID_CD_1 + wheel_time_3 * MAX_VALID_CD_2 + wheel_time_4 * MAX_VALID_CD_4;

    uint64_t next_time = to->next_cd + total_now;//
    uint32_t idx = 0;
    if (next_time >= MAX_VALID_CD_3)
    {
        idx = next_time / MAX_VALID_CD_3;
        to->next_cd = next_time % MAX_VALID_CD_3;
        wheel_idx = WHEEL_INDEX_4;
    }
    else if (next_time >= MAX_VALID_CD_2)
    {
        idx = next_time / MAX_VALID_CD_2;
        to->next_cd = next_time % MAX_VALID_CD_2;
        wheel_idx = WHEEL_INDEX_3;
    }
    else if (next_time >= MAX_VALID_CD_1)
    {
        idx = next_time / MAX_VALID_CD_1;
        to->next_cd = next_time % MAX_VALID_CD_1;
        wheel_idx = WHEEL_INDEX_2;
    }
    else 
    {
        idx = next_time;
        to->next_cd = next_time ;
        wheel_idx = WHEEL_INDEX_1;
    }

    all_timer_wheel_[wheel_idx][idx].emplace_back(to);
    return true;
}

