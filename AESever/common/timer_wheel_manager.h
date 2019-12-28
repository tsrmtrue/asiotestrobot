#ifndef __TIMER_WHEEL_MANAGER_H__
#define __TIMER_WHEEL_MANAGER_H__

#include <functional>
#include <list>
#include <array>
#include "singleton.h"


    /*
     *    三个轮子，
     *    [1,1024]ms, [1,1024]Kms,[1,1024]Mms,[...]unhandled.
     *    最后一个放的是12天以外的。
     *
     *
     */

#define  TIMER_ID uint64_t
#define  INVALID_TIMER_ID 0

using TimerCB = std::function<void()>;

struct TimerObj
{
    TimerObj()
    {
        static uint64_t idx = 0;
        id = ++idx;
    }
    //valid 延迟删除。
    bool is_valid{ true };
    //id
    TIMER_ID id{0};
    //下一次触发时间
    uint64_t next_triggle_time{0};
    //冷却间隔
    uint32_t cd{0};
    //触发次数  -1 表示无数次 
    int32_t count{ 0 };
    //回调
    TimerCB cb{nullptr};
    bool WillTriggerNextTime();
};

#define WHEEL_BITS 10
#define WHEEL_LENGTH (2<<WHEEL_BITS)
#define WHEEL_INDEX_1 0
#define WHEEL_INDEX_2 (WHEEL_INDEX_1 + 1)
#define WHEEL_INDEX_3 (WHEEL_INDEX_2 + 1)
#define WHEEL_COUNT_MAX (WHEEL_INDEX_3 + 1 )

using TimerObjList = std::list<TimerObj*>;
using TimerObjListWheel = std::array<TimerObjList, WHEEL_LENGTH>;
using TotalTimer = std::array<TimerObjListWheel, WHEEL_COUNT_MAX>;
using TimerIndex = std::array<uint32_t, WHEEL_COUNT_MAX>;

class TimerWheelManager
{
public:
    TimerWheelManager(){};
    ~TimerWheelManager(){};
    DECLARE_SINGLETON(TimerWheelManager);

public:

    TIMER_ID AddTimer(TimerObj*);
    void KillTimer(TIMER_ID handle);
    bool Init();
    void Uninit();

private:
    /*
     *去到当前的时间片，从容器中全部取出，遍历执行回调，如果需要下次回调则插入下一个空洞，
     *问题1，timer每毫秒都必须跳动。
     *问题2，删除的时候需要快速定位。
     */
    void Update(uint64_t time_stampe){};

private:
    uint64_t now_time_{ 0 };
    TotalTimer total_timer_;
    TimerIndex timer_index_{0};
    TimerObjList outer_list_;//超长时间的timer，当所有timer队列都遍历过一遍，则这里刷新一次。
   

};



#endif