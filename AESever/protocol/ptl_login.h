#ifndef __PTL_LOGIN_H__
#define __PTL_LOGIN_H__
#include "stdint.h"
enum class EMessage
{
	MSG_LOGIN,
	MSG_LOGIN_RSP,
};



struct SLogin
{
	int32_t id;
	int32_t password;
};

struct SLoginRsp
{
	int32_t id;
	int32_t result;
};

#endif