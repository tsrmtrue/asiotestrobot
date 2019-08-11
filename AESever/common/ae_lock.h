#ifndef __AESERVER_LOCK_H__
#define  __AESERVER_LOCK_H__

#include <atomic>

struct EasySpinLock
{
    std::atomic_char _lock{0};

    void Lock()
    {
        char _target = 0;
        while(!_lock.compare_exchange_weak(_target, 1, std::memory_order_acquire))
        {
            _target = 0;
        }

    }

    void UnLock()
    {
        _lock.store(0 , std::memory_order_release);
    }
};

#endif