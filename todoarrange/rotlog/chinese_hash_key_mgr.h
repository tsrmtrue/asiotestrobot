#ifndef __CHINESE_HASH_KEY_MGR_H__
#define __CHINESE_HASH_KEY_MGR_H__
#include <unordered_map>
#include "singleton.h"

class ChineseHashKeyMgr
{
    DECLARE_SINGLETON(ChineseHashKeyMgr);
    ChineseHashKeyMgr();

public:
    bool Init();
    void Uninit();
    void Reload();

    const std::string& GetChinese(uint32_t key);

private:

    std::unordered_map<uint32_t, std::string> value_;
};


#endif