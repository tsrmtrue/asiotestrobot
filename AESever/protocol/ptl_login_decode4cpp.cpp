#ifdef WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h> 
#endif
#include "ptl_login_decode4cpp.h"
#include <string.h>

int decode_SLoginRsp(SLoginRsp& st, unsigned char* pSrc, unsigned int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pSrc + __used__);
        st.id = ntohl(*__i__);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pSrc + __used__);
        st.result = ntohl(*__i__);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SLogin(SLogin& st, unsigned char* pSrc, unsigned int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pSrc + __used__);
        st.id = ntohl(*__i__);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int32_t) <= bufLength)
    {
        int32_t* __i__ = (int32_t *)(pSrc + __used__);
        st.password = ntohl(*__i__);
        __used__ += sizeof(int32_t);
    }
    else
    {
        return -1;
    }



    return __used__;
}


