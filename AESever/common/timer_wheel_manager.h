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
    TIMEROBJ_STATE_IDLE,//��ʼ��
    TIMEROBJ_STATE_RUNNING,//ִ����
    TIMEROBJ_STATE_CLOSING,//׼��������
    TIMEROBJ_STATE_CLOSED//ɾ��
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

    ///> ״̬
    TimerState state{ TimerState::TIMEROBJ_STATE_RUNNING };
    ///> ��һ�δ���ʱ�䣬������Ϊ׼ȷ�Բο�ֵ������Ϊ�������ݡ�
    std::chrono::steady_clock::time_point debug_next_triggle_time{ std::chrono::steady_clock::now() };
    ///> ��λ���롣��ȴ���������cd��������ο�ֵ��
    uint32_t set_cd_ms{0};
    ///> ��Ҫ��������  -1 ��ʾ������ 
    int32_t count{ 0 };
    ///> �Ӽ�ʱ���ܵģ���������־
    int32_t total_cd{ 0 };
    ///> �´�cd
    int32_t next_cd{ 0 };
    ///> �ص�
    TimerCB callback{nullptr};

    ///> ִ�лص������Ҽ��״̬���ֱ����������ɾ�� 
    bool RunAndCalcTriggerNextTime();

    ///> ��ӡ��Ϣ
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


/// >           ���ݽṹ
////////////////////////////////////////
//��Ϊ�ĸ�������ָ�롿+һ����������С�
//[0,1024)
//[1024,1024k)
//[1024k,1024M)
//[1024M,1024G)
//[������ǰ�������ֵģ�ͳһ�������ﴦ���ȱ��������е��¼���գ����ֵ��������ٴβ���]
//��С��λ����Ϊ����

/// >           �㷨
////////////////////////////////////////
//�����롿���������cd������õ��ڱ����ϵ�λ�ã����뵽���λ�ã�ͬʱ��cd����Ϊ�۳��Ѿ��߹��Ĳ��֡�
//��ת����������ָ�롿��ÿ�αض�ת����Сָ��һ��ִ�е�ǰ����������С��ص�����ͬʱ���ָ���Ƿ��Ѿ�����һ�֣�����Ѿ��������򴥷��ϲ�ָ�롾ת����һ���ϲ�ָ���ת������ǰ���������ж���ȡ�����������¡����롿���ӣ���ʱ��cd�Ѿ��۳���֮ǰ�ƶ��Ĳ����ˡ�����̻��еݹ���ã�ֱ������������С�
//��ɾ��������ÿ�������ָ����Ϊkey�������һ��ȫ�ֵ�hashmap�����Ҫɾ����ʱ����keyҲ����ָ���ҵ���������״̬Ϊ�����˳���Ȼ������ʽ�ص���ʱ���Լ�ɾ����

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
    ///> �������
    TIMER_ID AddTimer(uint32_t cdms, int32_t c, TimerCB cb);
    ///> ��������ɾ�������������ӳٲ���
    void TryKillTimer(TIMER_ID handle);
    ///> ת��
    void Update(uint64_t time_stampe);

    inline uint64_t GetTotalcount() {
        return total_trigger_count_;
    };

private:
    ///> ת������������ָ�롿����ִ�лص�����ת��������ָ�롿
    void UpdateWheel();
    ///> ת�����߼�����ָ�롿����ת�����߼�����ָ�롿����ִ�����²��룬�����ݹ���ã�ֱ����������С�
    void UpdateHigherWheel(uint32_t from_timer);//
    ///> ����������ڵ�ǰ�ı����ϣ�Ѱ����һ������������ָ�롿λ�ã����롣
    bool InsertTimer(TimerObj*);
    ///> ɾ��������ֱ��ɾ��ָ�� 
    void DeleteTimerObj(TimerObj*);
    ///> ����ִ��timer���󣬴�һ�ݿ�����ȥ�������Ȼȫ��ɾ���������²���
    void RunTimerList(TimerObjList list);
    ///> ����Ͷ��timer���󣬴�һ�ݿ�����ȥ�������Ȼȫ��ɾ���������²���
    void ReDispatchTimerList(TimerObjList list);

private:
    uint64_t total_trigger_count_{ 0 };
    ///> �ĸ�ά�ȵı���
    TotalTimer all_timer_wheel_;
    ///> �ⲿ�֣���ǰ���ӷŲ��µģ����������������ʱ��Ҫ��������ⲿ����
    TimerObjList beyond_list_;
    ///> ���Ǽ�¼���ĸ����̵ĵ�ǰָ�룬������һ�ֵ�ʱ�򣬸߼��ֱ���ָ���1��
    TimerIndex timer_index_{0,0,0,0};//
    ///> ���е�ָ�����������ͬ��ɾ��
    TimerObjHashmap all_timer_object_;//��
};



#endif