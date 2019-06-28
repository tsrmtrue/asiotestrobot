#include "gperf_tcmalloc.h"
#ifndef WIN32
#include "gperftools/malloc_extension.h"
#include "gperftools/heap-profiler.h"
#include "gperftools/heap-checker.h"
#include "cmdline.h"
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>

static std::string profile_name;

static const int kMaxPrintSize = 10240;
static char g_print_string[kMaxPrintSize] = { 0 };
static void PrintStat(MallocExtension* tc)
{
    char name[128] = { 0 };
    snprintf(name, 128, "./log/tcmalloc-%s.txt", profile_name.c_str());
    FILE* fp = fopen(name, "a+");
    if (nullptr != fp)
    {
        // 获取调试信息
        tc->GetStats(g_print_string, kMaxPrintSize);
        fprintf(fp, "%s\n", g_print_string);
        fclose(fp);
    }
}
//static void GperfCallback(int32_t signo)
//{
//    if (SIGHUP == signo)
//    {
//        auto tc = MallocExtension::instance();
//        PrintStat(tc);
//        malloc_stats();
//        // 释放tcmalloc内存
//        tc->ReleaseFreeMemory();
//        // 再打印一次
//        PrintStat(tc);
//        malloc_stats();
//        //signal(SIGHUP, GperfCallback);
//    }
//}

static struct mallinfo g_mallinfo;

static bool DumpFile(const CmdLineArgs& args, std::string& out_message)
{
    if (!args.empty())
    {
        auto tc = MallocExtension::instance();
        tc->ReleaseFreeMemory();
        PrintStat(tc);
    }

    struct mallinfo m = mallinfo();
    if (m.arena != g_mallinfo.arena
        || m.uordblks > g_mallinfo.uordblks)
    {
        printf("last memory info:\n arena:%d, fsmblks:%d, fordblks:%d, uordblks:%d\n",
            g_mallinfo.arena, g_mallinfo.fsmblks, g_mallinfo.fordblks, g_mallinfo.uordblks);

        g_mallinfo = m;

        printf("now memory info:\n arena:%d, fsmblks:%d, fordblks:%d, uordblks:%d\n",
            g_mallinfo.arena, g_mallinfo.fsmblks, g_mallinfo.fordblks, g_mallinfo.uordblks);

        malloc_stats();
    }
    return true;
}

void InitGperfTCMalloc(const std::string& name, const std::string& arg)
{
    std::string idx = arg.substr(12, 1);
    char pro_name[128] = { 0 };
    snprintf(pro_name, sizeof(pro_name), "%s%s.prof", name.c_str(), idx.c_str());
    printf("%s\n", pro_name);
    profile_name.assign(pro_name);
    // 设置一下空闲内存回给系统的比例
    MallocExtension::instance()->SetMemoryReleaseRate(7.5);

    //signal(SIGHUP, GperfCallback);
    CmdLine::RegistCmd("tcmalloc", DumpFile);
}

void ReleaseTcMallocMemory()
{
    MallocExtension::instance()->ReleaseFreeMemory();

    printf("ReleaseTcMallocMemory \n");
}
#else
void InitGperfTCMalloc(const std::string& name, const std::string& arg)
{
    return;
}

void ReleaseTcMallocMemory()
{

}
#endif
