#ifndef    __PROTOCOLENCODE_CPP_ptl_login_H__
#define    __PROTOCOLENCODE_CPP_ptl_login_H__

#include <string>
#include <stdio.h>
#include "ptl_login.h"
using namespace std;

int encode_SLogin(SLogin& st, unsigned char* pBuf, unsigned int bufLength );

#endif    //__PROTOCOLENCODE_CPP_H__
