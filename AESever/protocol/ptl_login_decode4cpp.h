#ifndef    __PROTOCOLDECODE_CPP_ptl_login_H__
#define    __PROTOCOLDECODE_CPP_ptl_login_H__

#include <string>
#include <stdio.h>
#include "ptl_login.h"
using namespace std;

int decode_SLoginRsp(SLoginRsp& st, unsigned char* pSrc, unsigned int bufLength );
int decode_SLogin(SLogin& st, unsigned char* pSrc, unsigned int bufLength );

#endif    //__PROTOCOLDECODE_CPP_H__
