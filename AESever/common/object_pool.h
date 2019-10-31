#ifndef __SHARE_OBJECT_POOL_H__
#define __SHARE_OBJECT_POOL_H__
#include <vector>
#include <map>
#include <string>
#include "freelist.h"
#include "object_pool_manager.h"
namespace ObjectPool
{
    class AbstractPool
    {
    public:
        using FileSaveContainer = std::map<std::string, std::map<std::string, int32_t>>;
        enum SaveType
        {
            kSaveMallocSource = 0,
            kSaveRecycleSource = 1,
            kSaveContainerMax
        };
        AbstractPool();
        virtual ~AbstractPool();
        virtual void UnInit() = 0;
        virtual void Recycle(void* data, const char* src_file, int32_t line_no) = 0;
        virtual size_t Size() const = 0;
        virtual size_t MemorySize() const = 0;
        inline void SetObjectName(const std::string& object_name, size_t size)
        {
            object_name_ = object_name;
            object_size_ = size;
        }
        inline void IncreaseGet()
        {
            ++get_numbers_;
        }
        void IncreaseRecycle()
        {
            ++recycle_numbers_;
        }
        std::string  ToString();
        void ToString(std::string* out);
        void SaveSource(const void* ptr, const std::string& src_file, int32_t line_no, SaveType type);
        const std::string& GetName() const;

    private:
        bool BuildString(const std::string& src_file, int32_t line_no, std::string* out);
        void AppendToString(const std::string& str, const FileSaveContainer& container, std::string* out) const;

    private:
        std::string object_name_;
        size_t object_size_{ 0 };
        uint32_t get_numbers_{ 0 };
        uint32_t recycle_numbers_{ 0 };
        std::vector<FileSaveContainer> container_;
    };

    template<typename T>
    class ObjectPool : public AbstractPool
    {
        ObjectPool()
        {
            std::string object_name = typeid(T).name();
            SetObjectName(object_name, sizeof(T));
            memory_size_ = 0;
            pool_ = new FreeList(sizeof(T));
        }
    public:
        ~ObjectPool()
        {
            if (nullptr != pool_)
            {
                delete pool_;
                pool_ = nullptr;
            }
        }

    public:
        static ObjectPool<T>* Instance()
        {
            if (nullptr == singleton_)
            {
                singleton_ = new ObjectPool<T>();
                uint64_t object_name = typeid(T).hash_code();
                ObjectPoolManager::Instance()->Register(object_name, singleton_);
            }
            return singleton_;
        }

        void UnInit() override
        {
            if (nullptr != singleton_)
            {
                delete singleton_;
                singleton_ = nullptr;
            }
        }

        template<class ...Args>
        T* Get(const char* src_file, int32_t line_no, Args&&... args)
        {
            void* tmp = nullptr;
            tmp = malloc(sizeof(T));

            T* obj = new (tmp)T(std::forward<Args>(args)...);

            IncreaseGet();
            //SaveSource(obj, src_file, line_no, SaveType::kSaveMallocSource);

            return obj;
        }
        void Recycle(void* obj, const char* src_file, int32_t line_no) override
        {
            T* data = static_cast<T*>(obj);
            data->~T();
			//直接删除，不要做保留
			free(obj);
            IncreaseRecycle();
            //SaveSource(obj, src_file, line_no, SaveType::kSaveRecycleSource);
        }
        size_t Size() const override
        {
            return pool_->Size();
        }
        size_t MemorySize() const override
        {
            return memory_size_;
        }

    private:
        static ObjectPool<T>* singleton_;

        FreeList* pool_{ nullptr };
        size_t memory_size_{ 0 };
    };
    template<typename T>
    ObjectPool<T>* ObjectPool<T>::singleton_ = nullptr;
}



#define NEW_MEMORY(cls, ...) \
    ObjectPool::ObjectPool<cls>::Instance()->Get(__FILE__, (int32_t)__LINE__, ##__VA_ARGS__)


#define DELETE_MEMORY(obj)\
    if (nullptr != obj) \
    {\
        auto* object_name = (typeid(*obj).name());\
        uint64_t hash_code = typeid(*obj).hash_code();\
        ObjectPool::ObjectPoolManager::Instance()->Recycle(object_name, obj, __FILE__, __LINE__, hash_code);\
        obj = nullptr;\
    }



#endif