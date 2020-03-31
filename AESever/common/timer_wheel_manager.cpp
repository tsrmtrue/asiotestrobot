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
    //�������count 1 ��ô�ʹ���һ��,, 

    if (check_count == 0)
    {
        check_count = total_cd;
    }

    if (check_count > total_cd)
    {
    }
    std::cout <<"error !����������������������������������!!timer acculate elapse  ["<< total_cd << "]" <<std::endl;

    check_count = total_cd;
    total_cd += set_cd_ms;
    next_cd = total_cd;

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
        MoveOnTimer(timerobj, from_timer);
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

    auto& timerlist = timerwheel[index_wheel % (WHEEL_LENGTH)];

    //�õ���ʱ���� 
    TimerObjList temp = timerlist;
    //������
    timerlist.clear();
    //��ִ��
    if (from_timer == WHEEL_INDEX_1)
    {
        //��һ����Ҫִ��
        //��������������Ҫ����Ͷ�ݣ���Ҫ����ǰʱ��
        RunTimerList(temp);
    }
    else
    {
        //�����߼�����Ҫ���·������ͼ���
        //����������ÿ���ǰʱ��
        ReDispatchTimerList(temp, from_timer);
    }
    //��ת��
    index_wheel = (index_wheel + 1) % (WHEEL_LENGTH);//
    bool cross_clock = (index_wheel  == 0);

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
        //���˵�һ��ָ�룬�����Ķ�û��0�̶�
        //if (from_timer > WHEEL_INDEX_1 )
        //{
        //    index_wheel = 0;
        //}
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

//������ʱ���֣������ʱ��Ƭ����
bool TimerWheelManager::MoveOnTimer(TimerObj* to, uint32_t from_timer)
{
    if (!to)
    {
        return false;
    }
    //�ȸ���from_timer�ü� 
    //���²����ʱ��Ҫ������Դ������Ǵ���һ������ָ�������ģ���ô��Ҫ������һ���ʱ�䣬��Ϊ�Ѿ����ĵ��ˡ�

    //[0-9, 10-99, 100-999, 1000-9999]
    //[10   100    1000     10000]
    // ������  1566�����ļ�  1  ʵ��-1 0  
    // ����     566  ������  5  ʵ��-1 4
    // ����      66  �ڶ���  6  ʵ��-1 5
    // ����       6  ��һ��  6  ʵ�� 6
    uint32_t wheel_idx = 0;
    uint32_t idx = 0; //

    if (from_timer == WHEEL_INDEX_4)
    {
        to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_4])*MAX_VALID_CD_3;
        InsertTimer(to);
    }
    else if (from_timer == WHEEL_INDEX_3)
    {
        to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_3])* MAX_VALID_CD_2;
        InsertTimer(to);
    }
    else if (from_timer == WHEEL_INDEX_2)
    {
        to->next_cd = to->total_cd - (timer_index_[WHEEL_INDEX_3])* MAX_VALID_CD_2;
        to->next_cd = to->total_cd % MAX_VALID_CD_1;
        InsertTimer(to);
    }


}

bool TimerWheelManager::InsertTimer(TimerObj* to)
{
    //�����ǵ����Ժ�����ִ�У����Ǹ߲��ֽ�������������ʱ�б���ִ�У�����Ӱ��ԭ������
    if (!to || to->set_cd_ms >= MAX_VALID_CD_4)
    {
        return false;
    }

    //�ݽ�ָ��
    auto cdms = to->set_cd_ms;
    uint32_t idx = 0;
    uint32_t wheel_time_1 = timer_index_[WHEEL_INDEX_1];
    uint32_t wheel_time_2 = timer_index_[WHEEL_INDEX_2];
    uint32_t wheel_time_3 = timer_index_[WHEEL_INDEX_3];
    uint32_t wheel_time_4 = timer_index_[WHEEL_INDEX_4];
    uint32_t wheel_idx = WHEEL_INDEX_1;

    if (cdms + wheel_time_1 >= WHEEL_LENGTH)
    {
        //�۵�����
        cdms -= (WHEEL_LENGTH - wheel_time_1);
        //���߽ף���Ҫȡ��Ӧ��λ��
        cdms >>= WHEEL_BITS;
        wheel_idx = WHEEL_INDEX_2;
        if (cdms + wheel_time_2 >= WHEEL_LENGTH)
        {
            cdms -= (WHEEL_LENGTH - wheel_time_2);
            cdms >>= WHEEL_BITS;

            wheel_idx = WHEEL_INDEX_3;
            if (cdms + wheel_time_3 >= WHEEL_LENGTH)
            {
                cdms -= (WHEEL_LENGTH - wheel_time_3);
                cdms /= WHEEL_LENGTH;
                wheel_idx = WHEEL_INDEX_4;
            }
        }
    }
    idx = cdms% WHEEL_LENGTH;
    //+ timer_index_[wheel_idx]
    idx = (idx + timer_index_[wheel_idx]) % WHEEL_LENGTH;

    all_timer_wheel_[wheel_idx][idx].emplace_back(to);
    return true;
}

