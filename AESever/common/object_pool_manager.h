#ifndef __SHARE_OBJECT_POOL_MANAGER_H__
#define __SHARE_OBJECT_POOL_MANAGER_H__
#include "singleton.h"
#include <string>
#include <unordered_map>
#include <typeinfo>

namespace ObjectPool
{
    class AbstractPool;
    class ObjectPoolManager
    {
        using PoolContainer = std::unordered_map<uint64_t, AbstractPool*>;
	public:
        ObjectPoolManager();
        ~ObjectPoolManager();
        DECLARE_SINGLETON(ObjectPoolManager)
        
    public:
        bool Init();
        void Uninit();

        void Recycle(const char* object_name, void* data, const char* src_file, int32_t line_no, uint64_t hash_code);
        void Register(const uint64_t name, AbstractPool* pool);

		std::string Dump();

    private:
        PoolContainer pools_;
    };
}


#endif