#include "chinese_hash_key_mgr.h"
#include "LogInit.h"
#include <stdio.h>

#define CHINESE_TXT_PATH "gsconf/Tlog/CHINESE_RUNTIME_STRING_POOL.txt"
constexpr int32_t kMaxChineseLength = 1024;

ChineseHashKeyMgr* ChineseHashKeyMgr::sm_poSingleton = new ChineseHashKeyMgr();
ChineseHashKeyMgr::ChineseHashKeyMgr()
{
    Init();
}

bool ChineseHashKeyMgr::Init()
{
    FILE* fp = fopen(CHINESE_TXT_PATH, "rt");
    if (!fp)
    {
        printf("can't load file:%s", CHINESE_TXT_PATH);
        return false;
    }

    char buffer[kMaxChineseLength] = { 0 };
    while (fgets(buffer, kMaxChineseLength, fp))
    {
        int32_t i = 0;
        bool valid = buffer[0] != ' ';
        while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\t')
        {
            if (buffer[i] < '0' || buffer[i] > '9')
            {
                valid = false;
                break;
            }
            i++;
        }

        if (!valid)
        {
            continue;
        }

        int32_t len = strlen(buffer);
        if (i + 2 >= len)
        {
            continue;
        }

        uint32_t key = atol(buffer);
        if (!value_.emplace(key, std::string(buffer + i + 1, len - i - 3)).second)
        {
            printf("CHINESE_RUNTIME_STRING_POOL has repeat hash key:%u", key);

        }
    }
    fclose(fp);
    
    return true;
}

void ChineseHashKeyMgr::Uninit()
{
    value_.clear();
}

void ChineseHashKeyMgr::Reload()
{
    Uninit();
    Init();
}

const std::string & ChineseHashKeyMgr::GetChinese(uint32_t key)
{
    auto it = value_.find(key);
    if (it != value_.end())
    {
        return it->second;
    }

    static std::string default_string;
    default_string.clear();
    default_string.append("[").append(std::to_string(key)).append("]");
    return default_string;
}
