#ifndef __AE_LOG_MGR__
#define __AE_LOG_MGR__
#include <functional>
#include <list>
#include <array>
#include <chrono>
#include <unordered_map>
#include <string>
#include <istream>
#include "singleton.h"


enum class AELogLevel: uint32_t {
    Trace = 0,//
    Debug = 1,// 
    Info = 2,// 
    Warn = 3,// 
    Error = 4// 
    Tlog = 5// 
};    

struct AELog
{
    //__FUNCTION__, __FILENAME__, __LINE__
    std::stringstream log;
    // [等级][时间][__FILENAME__][__FUNCTION__:__LINE__]...[自定义k:v]\n
    AELog(const std::string & level, const std::string & fun, const std::string& fn, uint32_t l)
    {
        std::time_t t = std::time(nullptr);
        log<<"["<<level<<"]";
        log<<"["<<std::put_time(std::localtime(&t)) << "]"
        log<<"["<<fn<<"]";
        log<<"["<<fun<<":" << l <<"]";
    }
    template <typename T> void AddLog(const std::string & k , T v)
    {
        log<<"["<<k<<":"<<v<<"]";
    }
    const char * GetPrint()
    {
        return log.str().c_str();
    }
}

//定义宏,其中要加上等级开关。
// AELOG_TRACE
// AELOG_DEBUG
// AELOG_INFO
// AELOG_WARN
// AELOG_ERROR
// AELOG_TLOG

class AELogManager
{
public:
    LogManager(){};
    ~LogManager(){};
    DECLARE_SINGLETON(LogManager);

    //开工作者线程。按照每个小时，每个文件大小输出文件，
    bool Init();
    void Uninit();
}


#endif