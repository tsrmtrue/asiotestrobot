#include <cstdlib>
#include <cassert>
#include "freelist.h"
namespace ObjectPool
{
    FreeList::FreeList(int32_t size)
        : malloc_size_(size)
    {
        if (size < (int32_t)sizeof(void*))
        {
            malloc_size_ = sizeof(void*);
        }
    }
    FreeList::~FreeList()
    {
        Free(-1);
    }

    int32_t FreeList::Size() const
    {
        return size_;
    }

    void* FreeList::Get()
    {
        if (size_ > 0)
        {
            return Pop();
        }
        void* result = malloc(malloc_size_);
        assert(nullptr != result);
        return result;
    }

    void FreeList::Recycle(void* data)
    {
        void* next = data_;
        data_ = data;
        SetNext(data, next);
        ++size_;
    }

    void FreeList::Free(int32_t count)
    {
        void* head = data_;
        while (head && count--)
        {
            void* tmp = Next(head);
            free(head);
            head = tmp;
        }
    }

    void* FreeList::Pop()
    {
        assert(nullptr != data_);
        void* result = data_;
        data_ = Next(data_);
        --size_;
        return result;
    }
}
