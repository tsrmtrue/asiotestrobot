#ifndef __AESERVER_LOCK_H__
#define  __AESERVER_LOCK_H__

#include <atomic>

struct EasySpinLock
{
    std::atomic_flag lock{ ATOMIC_FLAG_INIT };

    //阻塞等
    void Lock()
    {
		while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
			;
    }

    //不阻塞等
    bool TryLock()
    {
        bool r = lock.test_and_set(std::memory_order_acquire);
        return r == false;
    }

    //解锁
    void UnLock()
    {
        lock.clear(std::memory_order_release);
    }
};
#endif