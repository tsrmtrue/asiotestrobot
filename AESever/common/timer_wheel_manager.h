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

#define WHEEL_BITS 10
#define WHEEL_LENGTH (1<<WHEEL_BITS)
#define WHEEL_MASK (WHEEL_LENGTH - 1)
#define WHEEL_INDEX_1 0
#define WHEEL_INDEX_2 (WHEEL_INDEX_1 + 1)
#define WHEEL_INDEX_3 (WHEEL_INDEX_2 + 1)
#define WHEEL_INDEX_4 (WHEEL_INDEX_3 + 1)
#define WHEEL_COUNT_MAX (WHEEL_INDEX_4 + 1 )

#define MAX_VALID_CD_0 1
#define MAX_VALID_CD_1 ((((((uint64_t)1<<WHEEL_BITS)))) )
#define MAX_VALID_CD_2 ((((((uint64_t)1<<WHEEL_BITS)<<WHEEL_BITS))) ) 
#define MAX_VALID_CD_3 ((((((uint64_t)1<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS)) )
#define MAX_VALID_CD_4 ((((((uint64_t)1<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS)<<WHEEL_BITS) )

#define WHEEL_IDX_BIT_POS 60
#define MAX_TIMER_ID_RANGE  (1 << WHEEL_IDX_BIT_POS)

using TimerCB = std::function<void()>;

enum class TimerState
{
    TIMEROBJ_STATE_IDLE,//初始化
    TIMEROBJ_STATE_RUNNING,//执行中
    TIMEROBJ_STATE_CLOSING,//准备被回收
    TIMEROBJ_STATE_CLOSED//删除
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
    }

    ///> 状态
    TimerState state{ TimerState::TIMEROBJ_STATE_RUNNING };
    ///> 下一次触发时间，仅仅作为准确性参考值。不作为排序依据。
    std::chrono::steady_clock::time_point debug_next_triggle_time{ std::chrono::steady_clock::now() };
    ///> 单位毫秒。冷却间隔，根据cd来做排序参考值。
    uint32_t set_cd_ms{0};
    ///> 需要触发次数  -1 表示无数次 
    int32_t count{ 0 };
    ///> 从计时起总的，用来打日志
    int32_t total_cd{ 0 };
    ///> 下次cd
    int32_t next_cd{ 0 };
    ///> 回调
    TimerCB callback{nullptr};

    ///> 执行回调，并且检查状态，分别做插入或者删除 
    bool RunAndCalcTriggerNextTime();

    ///> 打印信息
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


/// >           数据结构
////////////////////////////////////////
//分为四个【表盘指针】+一个【额外队列】
//[0,1024)
//[1024,1024k)
//[1024k,1024M)
//[1024M,1024G)
//[超过当前表盘数字的，统一放入这里处理，等表盘上所有的事件清空，则轮到这里做再次插入]
//最小单位设置为毫秒

/// >           算法
////////////////////////////////////////
//【插入】，输入相对cd，计算得到在表盘上的位置，插入到相对位置，同时将cd设置为扣除已经走过的部分。
//【转动】【表盘指针】，每次必定转动最小指针一格，执行当前格子里的所有【回调】，同时检查指针是否已经走满一轮，如果已经走满，则触发上层指针【转动】一格，上层指针的转动将当前格子里所有对象取出，并且重新【插入】格子，此时的cd已经扣除掉之前移动的部分了。这过程会有递归调用，直到处理【额外队列】
//【删除】，将每个对象的指针作为key，存放在一个全局的hashmap里，当需要删除的时候，用key也就是指针找到对象，设置状态为即将退出，然后再正式回调的时候将自己删除。

class TimerWheelManager
{
public:
    TimerWheelManager(){};
    ~TimerWheelManager(){};
    DECLARE_SINGLETON(TimerWheelManager);

public:
    bool Init();
    void Uninit();
    void DebugDump();
    void DebugRandomTryKill();
    ///> 插入操作
    TIMER_ID AddTimer(uint32_t cdms, int32_t c, TimerCB cb);
    ///> 主动调用删除操作，会有延迟操作
    void TryKillTimer(TIMER_ID handle);
    ///> 转动
    void Update(uint64_t time_stampe);

    inline uint64_t GetTotalcount() {
        return total_trigger_count_;
    };

private:
    ///> 转动【基础表盘指针】，先执行回调，后转动【表盘指针】
    void UpdateWheel();
    ///> 转动【高级表盘指针】，先转动【高级表盘指针】，后执行重新插入，这里会递归调用，直到【额外队列】
    void UpdateHigherWheel(uint32_t from_timer);//
    ///> 插入操作，在当前的表盘上，寻找下一个触发【表盘指针】位置，插入。
    bool InsertTimer(TimerObj*);
    ///> 删除操作，直接删除指针 
    void DeleteTimerObj(TimerObj*);
    ///> 依次执行timer对象，传一份拷贝过去，这个必然全部删掉，会重新插入
    void RunTimerList(TimerObjList list);
    ///> 重新投递timer对象，传一份拷贝过去，这个必然全部删掉，会重新插入
    void ReDispatchTimerList(TimerObjList list);

private:
    uint64_t total_trigger_count_{ 0 };
    ///> 四个维度的表盘
    TotalTimer all_timer_wheel_;
    ///> 外部轮，当前轮子放不下的，当整个轮子走完的时候，要遍历这个外部轮子
    TimerObjList beyond_list_;
    ///> 这是记录了四个表盘的当前指针，当走满一轮的时候，高级轮表盘指针加1。
    TimerIndex timer_index_{0,0,0,0};//
    ///> 所有的指针在这里，必须同步删掉
    TimerObjHashmap all_timer_object_;//。
};



#endif