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
     *    三个轮子，
     *    [1,1024]ms, [1,1024]Kms,[1,1024]Mms,[1,1024]Gms.
     *    最后一个放的是12到12000天的，如果出了这个范围，认为这个timer是不合法的，直接返回错误。
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
        ////每60位循环 
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

    //valid 延迟删除。
    TimerState state{ TimerState::TIMEROBJ_STATE_RUNNING };
    //下一次触发时间，仅仅作为准确性参考值。不作为排序依据。
    std::chrono::steady_clock::time_point debug_next_triggle_time{ std::chrono::steady_clock::now() };
    //，单位毫秒。冷却间隔，根据cd来做排序参考值。
    uint32_t set_cd_ms{0};
    //需要触发次数  -1 表示无数次 
    int32_t count{ 0 };
    //从计时起总的
    int32_t total_cd{ 0 };
    //下次cd
    int32_t next_cd{ 0 };
    //回调
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
     *去到当前的时间片，从容器中全部取出，遍历执行回调，如果需要下次回调则插入下一个空洞，
     *问题1，timer每毫秒都必须跳动。
     *问题2，删除的时候需要快速定位。
     */
    void UpdateWheel(uint32_t from_timer);//这里会递归调用
    bool InsertTimer(TimerObj*, uint32_t from_timer= WHEEL_COUNT_MAX);

    //当拨动时间轮，这里的时间片降级
    bool MoveOnTimer(TimerObj*, uint32_t from_timer);
    void DeleteTimerObj(TimerObj*);
    //依次执行timer对象
    void RunTimerList(TimerObjList list);//传一份拷贝过去，这个必然全部删掉，会重新插入
    //重新投递timer对象
    void ReDispatchTimerList(TimerObjList list, uint32_t from_timer);//传一份拷贝过去，这个必然全部删掉，会重新插入

private:
    uint64_t now_time_{ 0 };
    TotalTimer all_timer_wheel_;//四个维度的轮
    TimerIndex timer_index_{0,0,0,0};//这是记录了四个timer的index，当index抵达指针0的时候，意味着本轮所有的都走完了，需要遍历更高级维度的轮。
    //TimerObjList to_delete_;
    TimerObjHashmap all_timer_object_;//所有的指针在这里，必须同步删掉。
    //TimerIndex  refresh_1_count{ 0 };
};



#endif