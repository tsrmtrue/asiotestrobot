#include <iostream>
#include "login_system.h"
#include "ptl_login_decode4cpp.h"
#include "ptl_login_encode4cpp.h"
bool LoginMsgHdl::Handle(const SMessageFromClient & msg)
{
    auto *bytes = msg.GetBody();
    auto len = msg.GetBodyLen();
    if (bytes && len)
    {
        SLogin s;
        if (decode_SLogin(s, bytes, len))
        {
            //¥Ú”° 
            //std::cout << "message " << msg.session << " msg " << s.id<<std::endl;
            return true;
        }
    }
    return false;
}

int32_t LoginMsgSender::Pack(unsigned char * buf, uint32_t buflen)
{
    return  encode_SLogin(login, buf, buflen);
}












