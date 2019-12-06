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
};

#define WHEEL_LENGTH 1024
#define WHEEL_COUNT 3

using TimerObjList = std::list<TimerObj*>;
using TimerObjListWheel = std::array<TimerObjList, WHEEL_LENGTH>;
using TotalTimer = std::array<TimerObjListWheel, WHEEL_COUNT>;

class TimerWheelManager
{
public:
    TimerWheelManager(){};
    ~TimerWheelManager(){};
    DECLARE_SINGLETON(TimerWheelManager);

public:
    TIMER_ID AddTimer() { return 0; };
    void KillTimer(TIMER_ID handle){};
    bool Init();
    void Uninit();

private:
    void Update(uint64_t time_stampe){};

private:
    uint64_t now_time_{ 0 };
    TotalTimer total_timer_;
   

};



#endif