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
    //�������count 1 ��ô�ʹ���һ��,, 

    if (check_count == 0)
    {
        check_count = next_cd;
    }

    if (check_count > next_cd)
    {
    }
    std::cout <<"error !����������������������������������!!timer acculate elapse  ["<< next_cd << "]" <<std::endl;

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
    //����cd
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
        //�����ǲ��������е�timer���в��������У���ζ�Ų����ʱ���Ӧ�ô����������
        to->state = TimerState::TIMEROBJ_STATE_CLOSING;
    }
}


void TimerWheelManager::ReDispatchTimerList(TimerObjList list, uint32_t from_timer)//��һ�ݿ�����ȥ�������Ȼȫ��ɾ���������²���
{
    for (auto& timerobj : list)
    {
        InsertTimer(timerobj, from_timer);
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
            //�Ѿ�ɾ���ˣ��˳�
            DeleteTimerObj(timerobj);
        }

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

void TimerWheelManager::UpdateWheel(uint32_t from_timer)//�����ݹ����
{
    if (from_timer > WHEEL_INDEX_4)
    {
        return;
    }

    auto& index_wheel = timer_index_[from_timer];
    auto& timerwheel = all_timer_wheel_[from_timer];

    //��ת��
    index_wheel = (index_wheel + 1) ;//
    bool cross_clock = ((index_wheel+1) % (WHEEL_LENGTH) == 0);

    auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

    //ת������

    {
        //�õ���ʱ���� 
        TimerObjList temp = timerlist;
        //������
        timerlist.clear();
        //��ִ��
        if (from_timer == WHEEL_INDEX_1)
        {
            //��һ����Ҫִ��
            RunTimerList(temp);
        }
        else
        {
            //�����߼�����Ҫ���·������ͼ���
            ReDispatchTimerList(temp, from_timer);
        }

    }
    //if (from_timer == WHEEL_INDEX_1 && index_wheel != 0)
    //{
    //    //���Է�����
    //    return;
    //}

    //if (from_timer != WHEEL_INDEX_1 && index_wheel != 1)
    //{
    //    //���Է�����
    //    return;
    //}
    if (cross_clock)
    {
        UpdateWheel(from_timer + 1);
    }


    //if (from_timer > WHEEL_INDEX_1)
    //{
    //    //�ڶ��㿪ʼ��indexĬ��Ҫ��1��ʼ
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
    //�����ǵ����Ժ�����ִ�У����Ǹ߲��ֽ�������������ʱ�б���ִ�У�����Ӱ��ԭ������
    if (!to)
    {
        return false;
    }
    //auto cdms = to->next_cd - refresh_1_count * WHEEL_LENGTH;
    auto cdms = to->next_cd;
    //�ȸ���from_timer�ü� 
    //���²����ʱ��Ҫ������Դ������Ǵ���һ������ָ�������ģ���ô��Ҫ������һ���ʱ�䣬��Ϊ�Ѿ����ĵ��ˡ�

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
        //ԭ������ 
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

