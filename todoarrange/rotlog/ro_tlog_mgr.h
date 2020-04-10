#ifndef __RO_TLOG_MGR_H__
#define __RO_TLOG_MGR_H__
#include <thread>
#include "ro_tlog_define.h"
#include <stdio.h>

#include <atomic>

struct EasySpinLock
{
    std::atomic_flag _lock{ ATOMIC_FLAG_INIT };

    //阻塞等
    //void Lock()
    //{
    //    char _target = UNLOCK_VALUE;
    //    while (!_lock.compare_exchange_weak(_target, LOCK_VALUE, std::memory_order_acquire))
    //    {
    //        _target = UNLOCK_VALUE;
    //    }
    //}

    //不阻塞等
    bool TryLock()
    {
        bool r = _lock.test_and_set( std::memory_order_acquire);
        return r == false;
    }

    //解锁
    void UnLock()
    {
        _lock.clear(std::memory_order_release);
    }
};


#ifdef __linux__
#include "tglogsdk/third_party/include/tsf4g/tlog/tlog.h"
#endif // __linux__


#define NORMAL_FILE_IDX 0
#define USER_FILE_IDX 1
#define MAX_FILE_IDX 2
using RoLogList = std::list<ROTlogBase * >;
class RoTlogMgrBase
{
public:
    RoTlogMgrBase() 
    {
        exchange_lock_.UnLock();
    }
	~RoTlogMgrBase(){}
public:
	bool Init();
	void Uninit();

    void AddTlog(ROTlogBase * tlog);

    bool DoCheckExchange(IArgs *, void *);

    //每个进程自己重载,设置不同的文件名字,避免竞争
    virtual void SetTlogFileNamePrefix() = 0;
    virtual void DeleteTlogObject(ROTlogBase * tlog) = 0;

    //工作者线程调用
    void DoWrite();
    void WriteLocalFile(ROTlogBase * tlog);
    void FlushFile();

protected:

    bool worker_free_{ false };
    bool close_thread_{ false };
    RoLogList in_buff_list_;
    RoLogList out_buff_list_;

    std::thread* worker_thread_{ nullptr };
    std::string tlog_file_name_prefix_{ "tlog" };
    //技术中心需要的特殊表头
    //写文件的句柄

    FILE *  tlog_ofs_[MAX_FILE_IDX]{ nullptr, nullptr };
    //使用时间做开关,今天的年月日 yyyy-mm-dd
    std::string today_time_[MAX_FILE_IDX]{ "","" };
    std::string special_tlog_file_name_prefix_[MAX_FILE_IDX]{ "", "user" };

    HTIMER wait_timepoint_{ INVALID_HTIMER };
    EasySpinLock exchange_lock_;


#ifdef __linux__
    LPTLOGCTX log_ctx_{ NULL }; // tx sdk
#endif // __linux__

};


#endif