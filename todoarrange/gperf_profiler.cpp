#include "gperf_profiler.h"
#ifndef WIN32
#include "gperftools/profiler.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static std::string profile_name;
static void CheckProfileFile(bool is_stop)
{
    // 文件存在，重命名
    if (!access(profile_name.c_str(), F_OK))
    {
        if (is_stop)
        {
            ProfilerStop();
        }
        char target[128] = { 0 };
        snprintf(target, sizeof(target), "%s%ld", profile_name.c_str(), time(nullptr));
        rename(profile_name.c_str(), target);
    }
}
/*static void GperfCallback(int32_t signo)
{
    if (SIGUSR1 == signo)
    {
        printf("start ProfilerStart\n");
        CheckProfileFile(true);
        ProfilerStart(profile_name.c_str());
    }
    else if (SIGUSR2 == signo)
    {
        printf("stop ProfilerStop\n");
        ProfilerStop();
    }
}*/
static int32_t last_signo = 0;
static void CallbackUsr1(int32_t sig)
{
    if (last_signo == 0)
    {
        last_signo = SIGUSR1;
    }
    if (last_signo == SIGUSR2)
    {
        ProfilerStop();
    }
    last_signo = SIGUSR1;
    printf("start ProfilerStart\n");
    CheckProfileFile(true);
    ProfilerStart(profile_name.c_str());
    signal(SIGUSR1, CallbackUsr1);
}
static void CallbackUsr2(int32_t sig)
{
    if (last_signo != SIGUSR1)
    {
        return;
    }
    printf("stop ProfilerStop\n");
    ProfilerStop();
    signal(SIGUSR2, CallbackUsr2);
}
void InitGperfProfiler(const std::string& proc, const std::string& arg)
{
    signal(SIGUSR1, CallbackUsr1);
    signal(SIGUSR2, CallbackUsr2);
    std::string idx = arg.substr(12, 1);
    char pro_name[128] = { 0 };
    snprintf(pro_name, sizeof(pro_name), "%s%s.prof", proc.c_str(), idx.c_str());
    //printf("%s\n", pro_name);
    profile_name.assign(pro_name);
}
#else
void InitGperfProfiler(const std::string& proc, const std::string& arg)
{
    return;
}
#endif