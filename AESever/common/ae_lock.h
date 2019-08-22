#ifndef __AESERVER_LOCK_H__
#define  __AESERVER_LOCK_H__

#include <atomic>

struct EasySpinLock
{
    std::atomic_flag _lock{ ATOMIC_FLAG_INIT };

    //阻塞等
    //void Lock()
    //{
    //    char _target = UNLOCK_VALUE;
    //    while(!_lock.compare_exchange_weak(_target, LOCK_VALUE, std::memory_order_acquire))
    //    {
    //        _target = UNLOCK_VALUE;
    //    }
    //}

    //不阻塞等
    bool TryLock()
    {
        bool r = _lock.test_and_set(std::memory_order_acquire);
        return r == false;
    }

    //解锁
    void UnLock()
    {
        _lock.clear(std::memory_order_release);
    }
};
#endif