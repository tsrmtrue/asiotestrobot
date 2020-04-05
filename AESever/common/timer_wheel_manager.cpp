#include <iostream>
#include "timer_wheel_manager.h"
#include "object_pool.h"
#include <random>

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

    //if (check_count == 0)
    //{
    //    check_count = total_cd;
    //}

    if (total_cd != TimerWheelManager::Instance()->GetTotalcount())
    {
        std::cout <<"error !����������������������������������!!timer acculate elapse  ["<< total_cd << "]" << " system total count ["<< TimerWheelManager::Instance()->GetTotalcount()<<"] " <<std::endl;
    }
    //check_count = total_cd;
    total_cd += set_cd_ms;
    next_cd = set_cd_ms;

    //debug 
    auto now = std::chrono::steady_clock::now();
    //auto diff = std::chrono::duration_cast<std::chrono::microseconds>(now - debug_next_triggle_time).count();///> 
    //if (diff > 1)
    //{
    //    //std::cout <<"timer CD late !! "<< diff <<std::endl;
    //}

    //debug 

    if(callback)
    {
        callback();
    }

    if (count == 0)
    {    
        //�������count 1 ��ô�ʹ���һ��,, 
        return false;
    }
    //����cd
    //debug_next_triggle_time += std::chrono::milliseconds(set_cd_ms);
    return true;
}


bool TimerWheelManager::Init()
{
    timer_index_[WHEEL_INDEX_1] = 0;
    timer_index_[WHEEL_INDEX_2] = 0;
    timer_index_[WHEEL_INDEX_3] = 0;
    timer_index_[WHEEL_INDEX_4] = 0;
    return true;
};
void TimerWheelManager::Uninit()
{
 
};

void TimerWheelManager::DebugRandomTryKill()
{
    if (all_timer_object_.size() == 0)
    {
        return;
    }
    //�����������
    static std::random_device r;
    static std::default_random_engine e1(r());
    static std::uniform_int_distribution<int> uniform_dist(1, 10000);

    uint32_t random_index = r()% all_timer_object_.size();
    for(auto & iter : all_timer_object_)
    {
        if (--random_index == 0)
        {
            TryKillTimer(reinterpret_cast<TIMER_ID>(iter.second));
            break;
        }
    }
}

void TimerWheelManager::DebugDump()
{

    std::cout << std::endl;
    std::cout << "��ǰʱ�� " << "[" << timer_index_[WHEEL_INDEX_1] << "]" << "[" << timer_index_[WHEEL_INDEX_2] << "]" << "[" << timer_index_[WHEEL_INDEX_3] << "]" << "[" << timer_index_[WHEEL_INDEX_4] << "]"  << std::endl;

    std::cout << "��һ��" << std::endl;
    size_t i = 0;
    for (auto & timerlist : all_timer_wheel_[WHEEL_INDEX_1])
    {
        for (auto & timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }

    std::cout << "�ڶ���" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_2])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }


    std::cout << "������" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_3])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }

    std::cout << "���Ĳ�" << std::endl;
    i = 0;
    for (auto& timerlist : all_timer_wheel_[WHEEL_INDEX_4])
    {
        for (auto& timerobj : timerlist)
        {
            std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
        }
        i++;
    }
    std::cout << "�����" << std::endl;
    i = 0;
    for (auto& timerobj : beyond_list_)
    {
        std::cout << "pos [" << i << "] " << timerobj->DebugDump() << std::endl;
    }
}


TIMER_ID TimerWheelManager::AddTimer(uint32_t cdms, int32_t c, TimerCB cb)
{
    if ( cdms == 0 
        || cdms > MAX_VALID_CD_4 //32λ��Զ������� 
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
    //ֱ�ӷ���ָ��
    DELETE_MEMORY(timerobject);
    return INVALID_TIMER_ID;

}

void TimerWheelManager::TryKillTimer(TIMER_ID handle)
{
    auto to = reinterpret_cast<TimerObj*>(handle);
    if (to && all_timer_object_.find(to) != all_timer_object_.end())
    {
        //�ȴ��ص���ʱ��ִ��ɾ�� 
        to->state = TimerState::TIMEROBJ_STATE_CLOSING;
    }
}


void TimerWheelManager::ReDispatchTimerList(TimerObjList list)
{
    for (auto& timerobj : list)
    {
        InsertTimer(timerobj);
    }
}

void TimerWheelManager::RunTimerList(TimerObjList list)
{
    //ע�⴫�����һ����ʱ���������ùܶ��б�����ͷ�
    //�㷨��֤�������䵽ͬ���Ĳ㣬�����ƹ��յ㣬�����������������ֻ��������ϲ㡣
    for (auto& timerobj : list)
    {
        if (timerobj->state == TimerState::TIMEROBJ_STATE_CLOSING)
        {   
            //�Ѿ����߼�ɾ���ˣ�ֱ��ɾ��
            DeleteTimerObj(timerobj);
        }
        else
        {
            if (timerobj->RunAndCalcTriggerNextTime())
            {
                //����Ҫִ�У�
                InsertTimer(timerobj);
            }
            else
            {
                //ɾ��timer����,�������ˣ�����Ҫִ����
                DeleteTimerObj(timerobj);
            }
        }
    }
}

//�����ݹ����
void TimerWheelManager::UpdateHigherWheel(uint32_t from_timer)
{
    if (from_timer>= WHEEL_COUNT_MAX)
    {
        TimerObjList temp = beyond_list_;
        beyond_list_.clear();
        ReDispatchTimerList(temp);
        return;
    }
    else
    {
        auto& index_wheel = timer_index_[from_timer];
        index_wheel = (index_wheel + 1) % (WHEEL_LENGTH);//

        auto& timerwheel = all_timer_wheel_[from_timer];

        auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

        //�õ���ʱ���� 
        TimerObjList temp = timerlist;
        timerlist.clear();
        ReDispatchTimerList(temp);
        if (index_wheel == 0)
        {
            UpdateHigherWheel(from_timer + 1);
        }
    }
}

void TimerWheelManager::UpdateWheel()
{
    auto& index_wheel = timer_index_[WHEEL_INDEX_1];
    auto& timerwheel = all_timer_wheel_[WHEEL_INDEX_1];
    auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

    //�õ���ʱ���� 
    TimerObjList temp = timerlist;
    timerlist.clear();
    RunTimerList(temp);
    index_wheel = (index_wheel + 1) % (WHEEL_LENGTH);//

    if (index_wheel == 0)
    {
        UpdateHigherWheel(WHEEL_INDEX_1 + 1);
    }

}

void TimerWheelManager::Update(uint64_t time_stampe)
{
    UpdateWheel();
    total_trigger_count_++;
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

bool TimerWheelManager::InsertTimer(TimerObj* to)
{
    //�����ǵ����Ժ�����ִ�У����Ǹ߲��ֽ�������������ʱ�б���ִ�У�����Ӱ��ԭ������
    if (!to || to->next_cd >= MAX_VALID_CD_4)
    {
        return false;
    }

    //�ݽ�����ָ��
    //uint32_t wheel_lenth = 1;
    uint32_t wheel_time_1 = timer_index_[WHEEL_INDEX_1];
    uint32_t wheel_time_2 = timer_index_[WHEEL_INDEX_2];
    uint32_t wheel_time_3 = timer_index_[WHEEL_INDEX_3];
    uint32_t wheel_time_4 = timer_index_[WHEEL_INDEX_4];
    uint32_t wheel_idx = WHEEL_INDEX_1;

    uint32_t idx = 0;
    //auto cdms = to->next_cd;
    auto next_trigger = wheel_time_1 + to->next_cd;
    if (next_trigger < MAX_VALID_CD_1)
    {
        wheel_idx = WHEEL_INDEX_1;
        idx = next_trigger/ MAX_VALID_CD_0;
        to->next_cd = next_trigger% MAX_VALID_CD_0;
        all_timer_wheel_[wheel_idx][idx].emplace_back(to);
        return true;
    }

    to->next_cd -= (MAX_VALID_CD_1 - wheel_time_1);
    wheel_time_2 += 1;
    next_trigger = wheel_time_2 * MAX_VALID_CD_1 + to->next_cd;
    if(next_trigger < MAX_VALID_CD_2)
    {
        wheel_idx = WHEEL_INDEX_2;
        idx = next_trigger/ MAX_VALID_CD_1;
        to->next_cd = next_trigger % MAX_VALID_CD_1;
        all_timer_wheel_[wheel_idx][idx].emplace_back(to);
        return true;
    }


    to->next_cd -= (MAX_VALID_CD_2 - wheel_time_2* MAX_VALID_CD_1);
    wheel_time_3 += 1;
    next_trigger = wheel_time_3 * MAX_VALID_CD_2 + to->next_cd;
    if (next_trigger < MAX_VALID_CD_3)
    {
        wheel_idx = WHEEL_INDEX_3;
        idx = next_trigger / MAX_VALID_CD_2;
        to->next_cd = next_trigger % MAX_VALID_CD_2;
        all_timer_wheel_[wheel_idx][idx].emplace_back(to);
        return true;
    }

    to->next_cd -= (MAX_VALID_CD_3 - wheel_time_3 * MAX_VALID_CD_2);
    wheel_time_4 += 1;
    next_trigger = wheel_time_4 * MAX_VALID_CD_3 + to->next_cd;
    if (next_trigger < MAX_VALID_CD_4)
    {
        wheel_idx = WHEEL_INDEX_4;
        idx = next_trigger / MAX_VALID_CD_3;
        to->next_cd = next_trigger % MAX_VALID_CD_3;
        all_timer_wheel_[wheel_idx][idx].emplace_back(to);
        return true;
    }

    to->next_cd = next_trigger - MAX_VALID_CD_4;
    beyond_list_.emplace_back(to);
    return true;

}

