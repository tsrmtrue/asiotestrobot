#ifndef __TIMER_WHEEL_MANAGER_H__
#define __TIMER_WHEEL_MANAGER_H__

#include <functional>
#include <list>
#include <array>
#include <chrono>
#include <unordered_map>
#include <string>
#include "singleton.h"


    /*
     *    �������ӣ�
     *    [1,1024]ms, [1,1024]Kms,[1,1024]Mms,[1,1024]Gms.
     *    ���һ���ŵ���12��12000��ģ�������������Χ����Ϊ���timer�ǲ��Ϸ��ģ�ֱ�ӷ��ش���
     *
     *
     */

#define  TIMER_ID uint64_t
#define  INVALID_TIMER_ID 0

#define WHEEL_BITS 2
#define WHEEL_LENGTH (1<<WHEEL_BITS)
#define WHEEL_MASK (WHEEL_LENGTH - 1)
#define WHEEL_INDEX_1 0
#define WHEEL_INDEX_2 (WHEEL_INDEX_1 + 1)
#define WHEEL_INDEX_3 (WHEEL_INDEX_2 + 1)
#define WHEEL_INDEX_4 (WHEEL_INDEX_3 + 1)
#define WHEEL_COUNT_MAX (WHEEL_INDEX_4 + 1 )


#define MAX_VALID_CD_1 (((((1<<WHEEL_BITS)))) )
#define MAX_VALID_CD_2 (((((1<<WHEEL_BITS)<<WHEEL_BITS))) ) 
#define MAX_VALID_CD_3 (((((1<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS)) )
#define MAX_VALID_CD_4 (((((1<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS) )

#define WHEEL_IDX_BIT_POS 60
#define MAX_TIMER_ID_RANGE  (1 << WHEEL_IDX_BIT_POS)

using TimerCB = std::function<void()>;

enum class TimerState
{
    TIMEROBJ_STATE_IDLE,
    TIMEROBJ_STATE_RUNNING,
    TIMEROBJ_STATE_CLOSING,
    TIMEROBJ_STATE_CLOSED
};


struct TimerObj
{
    TimerObj(uint32_t cdms, int32_t c, TimerCB cb):
        set_cd_ms(cdms)
        , count(c)
        , total_cd(set_cd_ms)
        , callback(cb)
    {
        next_cd = set_cd_ms;
        ////ÿ60λѭ�� 
        //static uint64_t idx = 0;
        //idx = (idx + 1) % MAX_TIMER_ID_RANGE;
        //id = ++idx;
        //debug_next_triggle_time = std::chrono::system_clock::now();
    }
    //void SetWheelIndex(uint32_t w_index)
    //{
    //    //id |= w_index << WHEEL_IDX_BIT_POS;
    //}
    //static uint32_t GetWheelIndex(uint64_t idxid)
    //{
    //    return (uint64_t)(idxid & (0xf << WHEEL_IDX_BIT_POS)) >> WHEEL_IDX_BIT_POS;
    //}
    //uint32_t GetWheelIndex()
    //{
    //    return TimerObj::GetWheelIndex(id);
    //}

    //valid �ӳ�ɾ����
    TimerState state{ TimerState::TIMEROBJ_STATE_RUNNING };
    //��һ�δ���ʱ�䣬������Ϊ׼ȷ�Բο�ֵ������Ϊ�������ݡ�
    std::chrono::steady_clock::time_point debug_next_triggle_time{ std::chrono::steady_clock::now() };
    //����λ���롣��ȴ���������cd��������ο�ֵ��
    uint32_t set_cd_ms{0};
    //��Ҫ��������  -1 ��ʾ������ 
    int32_t count{ 0 };
    //�Ӽ�ʱ���ܵ�
    int32_t total_cd{ 0 };
    //�´�cd
    int32_t next_cd{ 0 };
    //�ص�
    TimerCB callback{nullptr};
    bool RunAndCalcTriggerNextTime();
    std::string DebugDump()
    {
        std::string s = "call count is [" + std::to_string(total_cd) + "]" + "cd is [" + std::to_string(set_cd_ms) + "]" + " nextcd is [" + std::to_string(next_cd) + "]";
        return s;
    }
};


using TimerObjList = std::list<TimerObj*>;
using TimerObjListWheel = std::array<TimerObjList, WHEEL_LENGTH>;
using TotalTimer = std::array<TimerObjListWheel, WHEEL_COUNT_MAX>;
using TimerIndex = std::array<uint32_t, WHEEL_COUNT_MAX>;
using StartTime = std::array<uint32_t, WHEEL_COUNT_MAX>;
using TimerObjHashmap = std::unordered_map<TimerObj*, TimerObj*>;

class TimerWheelManager
{
public:
    TimerWheelManager(){};
    ~TimerWheelManager(){};
    DECLARE_SINGLETON(TimerWheelManager);

public:

    TIMER_ID AddTimer(uint32_t cdms, int32_t c, TimerCB cb);
    void TryKillTimer(TIMER_ID handle);
    bool Init();
    void Uninit();
    void DebugDump();
    void Update(uint64_t time_stampe);

private:
    /*
     *ȥ����ǰ��ʱ��Ƭ����������ȫ��ȡ��������ִ�лص��������Ҫ�´λص��������һ���ն���
     *����1��timerÿ���붼����������
     *����2��ɾ����ʱ����Ҫ���ٶ�λ��
     */
    void UpdateWheel(uint32_t from_timer);//�����ݹ����
    bool InsertTimer(TimerObj*, uint32_t from_timer= WHEEL_COUNT_MAX);

    //������ʱ���֣������ʱ��Ƭ����
    bool MoveOnTimer(TimerObj*, uint32_t from_timer);
    void DeleteTimerObj(TimerObj*);
    //����ִ��timer����
    void RunTimerList(TimerObjList list);//��һ�ݿ�����ȥ�������Ȼȫ��ɾ���������²���
    //����Ͷ��timer����
    void ReDispatchTimerList(TimerObjList list, uint32_t from_timer);//��һ�ݿ�����ȥ�������Ȼȫ��ɾ���������²���

private:
    uint64_t now_time_{ 0 };
    TotalTimer all_timer_wheel_;//�ĸ�ά�ȵ���
    TimerIndex timer_index_{0,0,0,0};//���Ǽ�¼���ĸ�timer��index����index�ִ�ָ��0��ʱ����ζ�ű������еĶ������ˣ���Ҫ�������߼�ά�ȵ��֡�
    //TimerObjList to_delete_;
    TimerObjHashmap all_timer_object_;//���е�ָ�����������ͬ��ɾ����
    //TimerIndex  refresh_1_count{ 0 };
};



#endif