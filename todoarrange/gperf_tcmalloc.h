#ifndef __SHARE_GPERF_TCMALLOC_H__
#define __SHARE_GPERF_TCMALLOC_H__
#include <string>
void InitGperfTCMalloc(const std::string& name, const std::string& arg);

void ReleaseTcMallocMemory();

#endif
