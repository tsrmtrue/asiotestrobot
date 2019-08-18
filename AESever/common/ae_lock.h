#ifndef __AESERVER_LOCK_H__
#define  __AESERVER_LOCK_H__

#include <atomic>

struct EasySpinLock
{
    #define LOCK_VALUE 1
    #define UNLOCK_VALUE 0
    std::atomic_char _lock{UNLOCK_VALUE};

    //������
    void Lock()
    {
        char _target = UNLOCK_VALUE;
        while(!_lock.compare_exchange_weak(_target, LOCK_VALUE, std::memory_order_acquire))
        {
            _target = UNLOCK_VALUE;
        }
    }

    //��������
    bool TryLock()
    {
        char _target = UNLOCK_VALUE;
        return _lock.compare_exchange_weak(_target, LOCK_VALUE, std::memory_order_acquire);

    }

    //����
    void UnLock()
    {
        _lock.store(UNLOCK_VALUE , std::memory_order_release);
    }
};

#endif