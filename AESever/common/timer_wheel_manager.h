#ifndef __TIMER_WHEEL_MANAGER_H__
#define __TIMER_WHEEL_MANAGER_H__

#include <functional>
#include <list>
#include <array>
#include "singleton.h"


    /*
     *    �������ӣ�
     *    [1,1024]ms, [1,1024]Kms,[1,1024]Mms,[...]unhandled.
     *    ���һ���ŵ���12������ġ�
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
    //valid �ӳ�ɾ����
    bool is_valid{ true };
    //id
    TIMER_ID id{0};
    //��һ�δ���ʱ��
    uint64_t next_triggle_time{0};
    //��ȴ���
    uint32_t cd{0};
    //��������  -1 ��ʾ������ 
    int32_t count{ 0 };
    //�ص�
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
     *ȥ����ǰ��ʱ��Ƭ����������ȫ��ȡ��������ִ�лص��������Ҫ�´λص��������һ���ն���
     *����1��timerÿ���붼����������
     *����2��ɾ����ʱ����Ҫ���ٶ�λ��
     */
    void Update(uint64_t time_stampe){};

private:
    uint64_t now_time_{ 0 };
    TotalTimer total_timer_;
    TimerIndex timer_index_{0};
    TimerObjList outer_list_;//����ʱ���timer��������timer���ж�������һ�飬������ˢ��һ�Ρ�
   

};



#endif