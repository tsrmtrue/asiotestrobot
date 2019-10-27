#ifdef WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h> 
#endif
#include "ptl_login_encode4cpp.h"
#include <string.h>

int encode_SLoginRsp(SLoginRsp& st, unsigned char* pBuf, unsigned int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pBuf + __used__);
        *__i__ = htonl(st.id);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pBuf + __used__);
        *__i__ = htonl(st.result);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SLogin(SLogin& st, unsigned char* pBuf, unsigned int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pBuf + __used__);
        *__i__ = htonl(st.id);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pBuf + __used__);
        *__i__ = htonl(st.password);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    return __used__;
}


