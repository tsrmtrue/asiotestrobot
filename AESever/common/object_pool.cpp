#include <sstream>
#include <cassert>
#include "object_pool.h"
namespace ObjectPool
{

    AbstractPool::AbstractPool()
    {
        container_.reserve(kSaveContainerMax);
        for (auto i = 0; i < kSaveContainerMax; ++i)
        {
            FileSaveContainer p;
            container_.emplace_back(p);
        }
    }

    AbstractPool::~AbstractPool()
    {
        container_.clear();
    }

    std::string AbstractPool::ToString()
    {
		std::string s;
		s.append("object[").append(object_name_).append("] get[").append(std::to_string(get_numbers_)).append("], recycle[").append(std::to_string(recycle_numbers_)).append("], object size[").append(std::to_string(object_size_)).append("]");
		return s;
    }

    void AbstractPool::ToString(std::string* out)
    {
        if (nullptr == out)
        {
            return;
        }
        out->clear();
        AppendToString("malloc", container_[kSaveMallocSource], out);
        AppendToString("recycle", container_[kSaveRecycleSource], out);
    }

    void AbstractPool::SaveSource(const void* ptr, const std::string& src_file, int32_t line_no, SaveType type)
    {
        FileSaveContainer* src = nullptr;
        std::string file_no;
        BuildString(src_file, line_no, &file_no);
        char ptr_date[128] = { 0 };
        snprintf(ptr_date, 128, "%p", ptr);
        std::string ptr_str(static_cast<const char*>(ptr_date));
        assert(type < kSaveContainerMax);

        src = &container_[type];

        assert(nullptr != src);
        auto ptr_it = src->find(ptr_str);
        if (ptr_it == src->end())
        {
            std::map<std::string, int32_t> in;
            in.emplace(file_no, 1);
            src->emplace(ptr_str, in);
        }
        else
        {
            auto p = ptr_it->second.find(file_no);
            if (p == ptr_it->second.end())
            {
                ptr_it->second.emplace(file_no, 1);
            }
            else
            {
                p->second++;
            }
        }
    }

    bool AbstractPool::BuildString(const std::string& src_file, int32_t line_no, std::string* out)
    {
        std::stringstream ss;
        ss << src_file.substr(src_file.find_last_of("/\\") + 1) << ":" << line_no;
        if (nullptr != out)
        {
            out->clear();
            out->assign(ss.str());
        }
        return true;
    }

    void AbstractPool::AppendToString(const std::string& str, const FileSaveContainer& container, std::string* out) const
    {
        char src_file[1024] = { 0 };
        snprintf(src_file, 1024, "object[%s] %s detail info: address count[%d]\n",
            object_name_.c_str(), str.c_str(), (int32_t)container.size());
        out->append(src_file);
        for (auto& src : container)
        {
            snprintf(src_file, 1024, "data address[%s]:\n", src.first.c_str());
            out->append(src_file);
            for (auto& p : src.second)
            {
                snprintf(src_file, 1024, "%s file %s, %s count[%d]\n", str.c_str(),
                    p.first.c_str(), str.c_str(), p.second);
                out->append(src_file);
            }
        }
    }

}