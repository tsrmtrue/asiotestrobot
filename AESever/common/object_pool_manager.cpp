#include "singleton.h"
#include "object_pool_manager.h"
#include "object_pool.h"
#include <cstdio>
#include <sstream>
namespace ObjectPool
{
    INSTANCE_SINGLETON(ObjectPoolManager);

    ObjectPoolManager::ObjectPoolManager()
    {
    }

    ObjectPoolManager::~ObjectPoolManager()
    {
        //Dump();
        for (auto it = pools_.begin(); it != pools_.end(); /*++it*/)
        {
            it->second->UnInit();
            it = pools_.erase(it);
        }
    }

    bool ObjectPoolManager::Init()
    {
		return true;
    }

    void ObjectPoolManager::Uninit()
    {

    }

    void ObjectPoolManager::Recycle(const char* object_name, void* data, const char* src_file, int32_t line_no, uint64_t hash_code)
    {
        auto op = pools_.find(hash_code);
        if (op != pools_.end())
        {
            op->second->Recycle(data, src_file, line_no);
        }
        else
        {
            printf("can not find object name[%s] in memory pool, address[%p]",
                object_name, data);
        }
    }

    void ObjectPoolManager::Register(const uint64_t name, AbstractPool* pool)
    {
        auto it = pools_.find(name);
        if (it == pools_.end())
        {
            pools_.emplace(name, pool);
        }
    }


	std::string ObjectPoolManager::Dump()
	{
		std::string r;
		for (auto& item : pools_)
		{
			r += item.second->ToString();
			r += "\n";
		}
		return r;
	}

    //void ObjectPoolManager::DoProfile(FILE* fp)
    //{
    //    uint64_t memory_size = 0;
    //    char ab[256] = { 0 };
    //    std::string out;
    //    for (auto& item : pools_)
    //    {
    //        item.second->ToString(ab, 256);
    //        memory_size += item.second->MemorySize();
    //        fprintf(fp, "%s\n", ab);
    //        if (is_print_detail_)
    //        {
    //            item.second->ToString(&out);
    //            fprintf(fp, "%s\n", out.c_str());
    //        }
    //    }
    //    fprintf(fp, "total memory size[%llu]\n", (long long unsigned int)memory_size);
    //}

    //bool ObjectPoolManager::BuildFileName(std::string* out)
    //{
    //    return true;
    //}
}