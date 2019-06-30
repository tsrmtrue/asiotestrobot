#ifndef __PTL_LOGIN_H__
#define __PTL_LOGIN_H__
#include "stdint.h"
enum class EMessage
{
    Msg_Login,
};



struct SLogin
{
    int32_t id;
};


#endif