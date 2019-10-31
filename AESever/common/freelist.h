#ifndef __SHARE_FREE_LIST_H__
#define __SHARE_FREE_LIST_H__
#include <cstdint>
namespace ObjectPool
{
    class FreeList
    {
    public:
        FreeList(int32_t size);
        ~FreeList();
        int32_t Size() const;
        void* Get();
        // 回给对象池
        void Recycle(void* data);
        // 回给系统
        void Free(int32_t count);

    private:
        void* Pop();
        inline void* Next(void* t)
        {
            return *(reinterpret_cast<void**>(t));
        }
        inline void SetNext(void* l, void* n)
        {
            *(reinterpret_cast<void**>(l)) = n;
        }

    private:
        void* data_{ nullptr };
        int32_t size_{ 0 };
        int32_t malloc_size_{ 0 };
    };
}
#endif