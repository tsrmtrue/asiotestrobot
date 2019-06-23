# -*- coding: GBK -*-
import sys
sys.path.append('../autotest_lib')
from coder_hlp_lib import *
from test_namedlist_passport import *
g_decode_fun = {}
g_encode_fun = {}
C_2_PS_Get_ServerList_Req = 4097
PS_2_C_ServerList_Ntf = 4098
C_2_PS_Get_Server_Desc_Req = 4099
PS_2_C_Get_Server_Desc_Rsp = 4100
C_2_S_Bind_Passport_Req = 4101
S_2_C_Bind_Passport_Rsp = 4102
S_2_PS_Try_Bind_Passport_Req = 4103
PS_2_S_Try_Bind_Passport_Rsp = 4104
C_2_PS_Login_By_Passport_Req = 4105
PS_2_C_Login_By_Passport_Rsp = 4106
C_2_PS_Choose_Server_Req = 4107
PS_2_C_Choose_Server_Rsp = 4108
C_2_PS_Register_Passport_Req = 4109
PS_2_C_Register_Passport_Rsp = 4110
C_2_S_EnterGame_By_SessionId_Req = 4111
S_2_C_EnterGame_By_SessionId_Rsp = 4112
S_2_PS_Check_Session_Req = 4113
PS_2_S_Check_Session_Rsp = 4114
C_2_PS_Login_By_SessionId_Req = 4115
PS_2_C_Login_By_SessionId_Rsp = 4116
C_2_S_Create_And_Bind_Passport_Req = 4117
S_2_C_Create_And_Bind_Passport_Rsp = 4118
S_2_PS_Try_Create_And_Bind_Passport_Req = 4119
PS_2_S_Try_Create_And_Bind_Passport_Rsp = 4120
C_2_PS_EnterGame_Notify_Req = 4121
PS_2_C_EnterGame_Notify_Rsp = 4122
S_2_PS_ServerStatus_Report_Req = 4123
PS_2_S_ServerStatus_Report_Rsp = 4124
S_2_PS_ServerStatus_Register_Req = 4125
PS_2_S_ServerStatus_Register_Rsp = 4126
C_2_PS_Logoff_Passport_Req = 4127
PS_2_C_Logoff_Passport_Rsp = 4128
C_2_PS_Test_Req = 4129
PS_2_C_Test_Rsp = 4130
C_2_S_Master_Control_Req = 4131
S_2_C_Master_Control_Rsp = 4132
C_2_PS_PP_Login_Req = 4133
PS_2_C_PP_Login_Rsp = 4134
PS_2_PP_Check_Login_Req = 4135
PP_2_PS_Check_Login_Rsp = 4136

def encode_SGetServerListReq(st):
    str=''

    str += addByte(st.page)
    return str

def decode_SGetServerListReq(buf):
    st=SGetServerListReq()
    pos=0

    st.page,length = getByte(buf[pos:])
    pos += length
    return st,pos

def encode_SServerInfo(st):
    str=''

    str += addDword(st.serverid)
    str += addString(st.name)
    str += addByte(st.status)
    str += addString(st.ip)
    str += addWord(st.port)
    str += addByte(st.canRegister)
    return str

def decode_SServerInfo(buf):
    st=SServerInfo()
    pos=0

    st.serverid,length = getDword(buf[pos:])
    pos += length
    st.name,length = getString(buf[pos:])
    pos += length
    st.status,length = getByte(buf[pos:])
    pos += length
    st.ip,length = getString(buf[pos:])
    pos += length
    st.port,length = getWord(buf[pos:])
    pos += length
    st.canRegister,length = getByte(buf[pos:])
    pos += length
    return st,pos

def encode_SServerDesc(st):
    str=''

    str += addDword(st.serverid)
    str += addString(st.desc)
    return str

def decode_SServerDesc(buf):
    st=SServerDesc()
    pos=0

    st.serverid,length = getDword(buf[pos:])
    pos += length
    st.desc,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SServerStatus(st):
    str=''

    str += addByte(st.isOpen)
    str += addDword(st.currentRoleCount)
    str += addDword(st.maxRoleCount)
    str += addDword(st.isNew)
    return str

def decode_SServerStatus(buf):
    st=SServerStatus()
    pos=0

    st.isOpen,length = getByte(buf[pos:])
    pos += length
    st.currentRoleCount,length = getDword(buf[pos:])
    pos += length
    st.maxRoleCount,length = getDword(buf[pos:])
    pos += length
    st.isNew,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SServerListNtf(st):
    str=''

    str += addByte(st.page)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SServerInfo(st.list[i])
        str += _tempstr

    return str

def decode_SServerListNtf(buf):
    st=SServerListNtf()
    pos=0

    st.page,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.list[i],length = decode_SServerInfo(buf[pos:])
    
        pos += length

    return st,pos

def encode_SSessionId(st):
    str=''

    str += addString(st.sid)
    return str

def decode_SSessionId(buf):
    st=SSessionId()
    pos=0

    st.sid,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SMacAddress(st):
    str=''

    str += addString(st.macAddress)
    return str

def decode_SMacAddress(buf):
    st=SMacAddress()
    pos=0

    st.macAddress,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SPassport(st):
    str=''

    str += addString(st.passport)
    str += addString(st.password)
    return str

def decode_SPassport(buf):
    st=SPassport()
    pos=0

    st.passport,length = getString(buf[pos:])
    pos += length
    st.password,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SRegisterPassport(st):
    str=''


    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr

    str += addString(st.email)
    str += addDword(st.qq)
    return str

def decode_SRegisterPassport(buf):
    st=SRegisterPassport()
    pos=0


    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length

    st.email,length = getString(buf[pos:])
    pos += length
    st.qq,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SBindPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr

    return str

def decode_SBindPassportReq(buf):
    st=SBindPassportReq()
    pos=0


    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SBindPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passports[i])
        str += _tempstr

    return str

def decode_SBindPassportRsp(buf):
    st=SBindPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passports[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SEasyRoleInfo(st):
    str=''

    str += addString(st.rolename)
    str += addWord(st.level)
    str += addDword(st.userid)
    str += addDword(st.serverid)
    return str

def decode_SEasyRoleInfo(buf):
    st=SEasyRoleInfo()
    pos=0

    st.rolename,length = getString(buf[pos:])
    pos += length
    st.level,length = getWord(buf[pos:])
    pos += length
    st.userid,length = getDword(buf[pos:])
    pos += length
    st.serverid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_STryBindPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SEasyRoleInfo(st.easyRoleInfo)
        str += _tempstr

    return str

def decode_STryBindPassportReq(buf):
    st=STryBindPassportReq()
    pos=0


    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length


    for i in range(1):
        st.easyRoleInfo,length = decode_SEasyRoleInfo(buf[pos:])
    
        pos += length

    return st,pos

def encode_STryBindPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passports[i])
        str += _tempstr

    str += addDword(st.userid)
    return str

def decode_STryBindPassportRsp(buf):
    st=STryBindPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passports[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    st.userid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SLoginByPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr

    return str

def decode_SLoginByPassportReq(buf):
    st=SLoginByPassportReq()
    pos=0


    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SLoginByPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passport[i])
        str += _tempstr

    return str

def decode_SLoginByPassportRsp(buf):
    st=SLoginByPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passport[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SChooseServerReq(st):
    str=''

    str += addDword(st.serverid)
    return str

def decode_SChooseServerReq(buf):
    st=SChooseServerReq()
    pos=0

    st.serverid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SChooseServerRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SEasyRoleInfo(st.roles[i])
        str += _tempstr

    str += addDword(st.currentQueueCount)
    str += addDword(st.queueCountDown)
    return str

def decode_SChooseServerRsp(buf):
    st=SChooseServerRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.roles[i],length = decode_SEasyRoleInfo(buf[pos:])
    
        pos += length

    st.currentQueueCount,length = getDword(buf[pos:])
    pos += length
    st.queueCountDown,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SLoginBySessionIdReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SSessionId(st.sid)
        str += _tempstr

    return str

def decode_SLoginBySessionIdReq(buf):
    st=SLoginBySessionIdReq()
    pos=0


    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length


    for i in range(1):
        st.sid,length = decode_SSessionId(buf[pos:])
    
        pos += length

    return st,pos

def encode_SLoginBySessionIdRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr

    return str

def decode_SLoginBySessionIdRsp(buf):
    st=SLoginBySessionIdRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length

    return st,pos

def encode_SCheckSessionReq(st):
    str=''

    str += addDword(st.socket)

    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SSessionId(st.sid)
        str += _tempstr

    return str

def decode_SCheckSessionReq(buf):
    st=SCheckSessionReq()
    pos=0

    st.socket,length = getDword(buf[pos:])
    pos += length

    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length


    for i in range(1):
        st.sid,length = decode_SSessionId(buf[pos:])
    
        pos += length

    return st,pos

def encode_SCheckSessionRsp(st):
    str=''

    str += addDword(st.socket)
    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr

    return str

def decode_SCheckSessionRsp(buf):
    st=SCheckSessionRsp()
    pos=0

    st.socket,length = getDword(buf[pos:])
    pos += length
    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length

    return st,pos

def encode_SEnterGameBySessionIdReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SSessionId(st.sid)
        str += _tempstr

    str += addDword(st.userid)

    for i in range(1):
        _tempstr = encode_SPassport(st.passport)
        str += _tempstr

    return str

def decode_SEnterGameBySessionIdReq(buf):
    st=SEnterGameBySessionIdReq()
    pos=0


    for i in range(1):
        st.sid,length = decode_SSessionId(buf[pos:])
    
        pos += length

    st.userid,length = getDword(buf[pos:])
    pos += length

    for i in range(1):
        st.passport,length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SEnterGameBySessionIdRsp(st):
    str=''

    str += addByte(st.errcode)
    return str

def decode_SEnterGameBySessionIdRsp(buf):
    st=SEnterGameBySessionIdRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    return st,pos

def encode_SCreateAndBindPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SRegisterPassport(st.registerPassport)
        str += _tempstr

    return str

def decode_SCreateAndBindPassportReq(buf):
    st=SCreateAndBindPassportReq()
    pos=0


    for i in range(1):
        st.registerPassport,length = decode_SRegisterPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SCreateAndBindPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passport[i])
        str += _tempstr

    return str

def decode_SCreateAndBindPassportRsp(buf):
    st=SCreateAndBindPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passport[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_STryCreateAndBindPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SEasyRoleInfo(st.role)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SRegisterPassport(st.registerPassport)
        str += _tempstr

    return str

def decode_STryCreateAndBindPassportReq(buf):
    st=STryCreateAndBindPassportReq()
    pos=0


    for i in range(1):
        st.role,length = decode_SEasyRoleInfo(buf[pos:])
    
        pos += length


    for i in range(1):
        st.registerPassport,length = decode_SRegisterPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_STryCreateAndBindPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passport[i])
        str += _tempstr

    str += addDword(st.userid)
    return str

def decode_STryCreateAndBindPassportRsp(buf):
    st=STryCreateAndBindPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passport[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    st.userid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SRegisterPassportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SRegisterPassport(st.registerPassport)
        str += _tempstr

    return str

def decode_SRegisterPassportReq(buf):
    st=SRegisterPassportReq()
    pos=0


    for i in range(1):
        st.registerPassport,length = decode_SRegisterPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SRegisterPassportRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addByte(st.count)

    for i in range(st.count):
        _tempstr = encode_SSessionId(st.sid[i])
        str += _tempstr


    for i in range(st.count):
        _tempstr = encode_SPassport(st.passport[i])
        str += _tempstr

    return str

def decode_SRegisterPassportRsp(buf):
    st=SRegisterPassportRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.count,length = getByte(buf[pos:])
    pos += length

    for i in range(st.count):
        st.sid[i],length = decode_SSessionId(buf[pos:])
    
        pos += length


    for i in range(st.count):
        st.passport[i],length = decode_SPassport(buf[pos:])
    
        pos += length

    return st,pos

def encode_SEnterGameNotifyReq(st):
    str=''

    str += addDword(st.serverid)
    return str

def decode_SEnterGameNotifyReq(buf):
    st=SEnterGameNotifyReq()
    pos=0

    st.serverid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SEnterGameNotifyRsp(st):
    str=''

    str += addByte(st.errcode)
    str += addDword(st.nextConnectSeconds)
    str += addDword(st.priorCount)
    return str

def decode_SEnterGameNotifyRsp(buf):
    st=SEnterGameNotifyRsp()
    pos=0

    st.errcode,length = getByte(buf[pos:])
    pos += length
    st.nextConnectSeconds,length = getDword(buf[pos:])
    pos += length
    st.priorCount,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SServerStatusReportReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SServerStatus(st.status)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SServerDesc(st.desc)
        str += _tempstr

    return str

def decode_SServerStatusReportReq(buf):
    st=SServerStatusReportReq()
    pos=0


    for i in range(1):
        st.status,length = decode_SServerStatus(buf[pos:])
    
        pos += length


    for i in range(1):
        st.desc,length = decode_SServerDesc(buf[pos:])
    
        pos += length

    return st,pos

def encode_SServerStatusReportRsp(st):
    str=''

    return str

def decode_SServerStatusReportRsp(buf):
    st=SServerStatusReportRsp()
    pos=0

    return st,pos

def encode_SServerStatusRegisterReq(st):
    str=''


    for i in range(1):
        _tempstr = encode_SServerInfo(st.info)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SServerDesc(st.desc)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SServerStatus(st.status)
        str += _tempstr

    return str

def decode_SServerStatusRegisterReq(buf):
    st=SServerStatusRegisterReq()
    pos=0


    for i in range(1):
        st.info,length = decode_SServerInfo(buf[pos:])
    
        pos += length


    for i in range(1):
        st.desc,length = decode_SServerDesc(buf[pos:])
    
        pos += length


    for i in range(1):
        st.status,length = decode_SServerStatus(buf[pos:])
    
        pos += length

    return st,pos

def encode_SServerStatusRegisterRsp(st):
    str=''

    return str

def decode_SServerStatusRegisterRsp(buf):
    st=SServerStatusRegisterRsp()
    pos=0

    return st,pos

def encode_STestReq(st):
    str=''

    str += addByte(st.testType)

    for i in range(1):
        _tempstr = encode_SEasyRoleInfo(st.role)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SRegisterPassport(st.registerPassport)
        str += _tempstr


    for i in range(1):
        _tempstr = encode_SMacAddress(st.macAddress)
        str += _tempstr

    return str

def decode_STestReq(buf):
    st=STestReq()
    pos=0

    st.testType,length = getByte(buf[pos:])
    pos += length

    for i in range(1):
        st.role,length = decode_SEasyRoleInfo(buf[pos:])
    
        pos += length


    for i in range(1):
        st.registerPassport,length = decode_SRegisterPassport(buf[pos:])
    
        pos += length


    for i in range(1):
        st.macAddress,length = decode_SMacAddress(buf[pos:])
    
        pos += length

    return st,pos

def encode_STestRsp(st):
    str=''

    return str

def decode_STestRsp(buf):
    st=STestRsp()
    pos=0

    return st,pos

def encode_SLogoffPassportReq(st):
    str=''

    return str

def decode_SLogoffPassportReq(buf):
    st=SLogoffPassportReq()
    pos=0

    return st,pos

def encode_SLogoffPassportRsp(st):
    str=''

    return str

def decode_SLogoffPassportRsp(buf):
    st=SLogoffPassportRsp()
    pos=0

    return st,pos

def encode_SGetServerDescReq(st):
    str=''

    str += addDword(st.serverid)
    return str

def decode_SGetServerDescReq(buf):
    st=SGetServerDescReq()
    pos=0

    st.serverid,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SGetServerDescRsp(st):
    str=''


    for i in range(1):
        _tempstr = encode_SServerDesc(st.desc)
        str += _tempstr

    return str

def decode_SGetServerDescRsp(buf):
    st=SGetServerDescRsp()
    pos=0


    for i in range(1):
        st.desc,length = decode_SServerDesc(buf[pos:])
    
        pos += length

    return st,pos

def encode_SMasterControlReq(st):
    str=''

    str += addDword(st.cmd)
    return str

def decode_SMasterControlReq(buf):
    st=SMasterControlReq()
    pos=0

    st.cmd,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SMasterControlRsp(st):
    str=''

    str += addDword(st.errcode)
    return str

def decode_SMasterControlRsp(buf):
    st=SMasterControlRsp()
    pos=0

    st.errcode,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SPPLoginReq(st):
    str=''

    str += addDword(st.len)
    str += addDword(st.command)
    str += addString(st.token_key)
    return str

def decode_SPPLoginReq(buf):
    st=SPPLoginReq()
    pos=0

    st.len,length = getDword(buf[pos:])
    pos += length
    st.command,length = getDword(buf[pos:])
    pos += length
    st.token_key,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SPPLoginRsp(st):
    str=''

    str += addDword(st.len)
    str += addDword(st.command)
    str += addDword(st.status)
    return str

def decode_SPPLoginRsp(buf):
    st=SPPLoginRsp()
    pos=0

    st.len,length = getDword(buf[pos:])
    pos += length
    st.command,length = getDword(buf[pos:])
    pos += length
    st.status,length = getDword(buf[pos:])
    pos += length
    return st,pos

def encode_SPPCheckLoginReq(st):
    str=''

    str += addDword(st.len)
    str += addDword(st.command)
    str += addString(st.token_key)
    return str

def decode_SPPCheckLoginReq(buf):
    st=SPPCheckLoginReq()
    pos=0

    st.len,length = getDword(buf[pos:])
    pos += length
    st.command,length = getDword(buf[pos:])
    pos += length
    st.token_key,length = getString(buf[pos:])
    pos += length
    return st,pos

def encode_SPPCheckLoginRsp(st):
    str=''

    str += addDword(st.len)
    str += addDword(st.command)
    str += addDword(st.status)
    str += addString(st.username)
    return str

def decode_SPPCheckLoginRsp(buf):
    st=SPPCheckLoginRsp()
    pos=0

    st.len,length = getDword(buf[pos:])
    pos += length
    st.command,length = getDword(buf[pos:])
    pos += length
    st.status,length = getDword(buf[pos:])
    pos += length
    st.username,length = getString(buf[pos:])
    pos += length
    return st,pos
g_decode_fun[C_2_PS_Get_ServerList_Req] = decode_SGetServerListReq
g_encode_fun[C_2_PS_Get_ServerList_Req] = encode_SGetServerListReq
g_decode_fun[PS_2_C_ServerList_Ntf] = decode_SServerListNtf
g_encode_fun[PS_2_C_ServerList_Ntf] = encode_SServerListNtf
g_decode_fun[C_2_PS_Get_Server_Desc_Req] = decode_SGetServerDescReq
g_encode_fun[C_2_PS_Get_Server_Desc_Req] = encode_SGetServerDescReq
g_decode_fun[PS_2_C_Get_Server_Desc_Rsp] = decode_SGetServerDescRsp
g_encode_fun[PS_2_C_Get_Server_Desc_Rsp] = encode_SGetServerDescRsp
g_decode_fun[C_2_S_Bind_Passport_Req] = decode_SBindPassportReq
g_encode_fun[C_2_S_Bind_Passport_Req] = encode_SBindPassportReq
g_decode_fun[S_2_C_Bind_Passport_Rsp] = decode_SBindPassportRsp
g_encode_fun[S_2_C_Bind_Passport_Rsp] = encode_SBindPassportRsp
g_decode_fun[S_2_PS_Try_Bind_Passport_Req] = decode_STryBindPassportReq
g_encode_fun[S_2_PS_Try_Bind_Passport_Req] = encode_STryBindPassportReq
g_decode_fun[PS_2_S_Try_Bind_Passport_Rsp] = decode_STryBindPassportRsp
g_encode_fun[PS_2_S_Try_Bind_Passport_Rsp] = encode_STryBindPassportRsp
g_decode_fun[C_2_PS_Login_By_Passport_Req] = decode_SLoginByPassportReq
g_encode_fun[C_2_PS_Login_By_Passport_Req] = encode_SLoginByPassportReq
g_decode_fun[PS_2_C_Login_By_Passport_Rsp] = decode_SLoginByPassportRsp
g_encode_fun[PS_2_C_Login_By_Passport_Rsp] = encode_SLoginByPassportRsp
g_decode_fun[C_2_PS_Choose_Server_Req] = decode_SChooseServerReq
g_encode_fun[C_2_PS_Choose_Server_Req] = encode_SChooseServerReq
g_decode_fun[PS_2_C_Choose_Server_Rsp] = decode_SChooseServerRsp
g_encode_fun[PS_2_C_Choose_Server_Rsp] = encode_SChooseServerRsp
g_decode_fun[C_2_PS_Register_Passport_Req] = decode_SRegisterPassportReq
g_encode_fun[C_2_PS_Register_Passport_Req] = encode_SRegisterPassportReq
g_decode_fun[PS_2_C_Register_Passport_Rsp] = decode_SRegisterPassportRsp
g_encode_fun[PS_2_C_Register_Passport_Rsp] = encode_SRegisterPassportRsp
g_decode_fun[C_2_S_EnterGame_By_SessionId_Req] = decode_SEnterGameBySessionIdReq
g_encode_fun[C_2_S_EnterGame_By_SessionId_Req] = encode_SEnterGameBySessionIdReq
g_decode_fun[S_2_C_EnterGame_By_SessionId_Rsp] = decode_SEnterGameBySessionIdRsp
g_encode_fun[S_2_C_EnterGame_By_SessionId_Rsp] = encode_SEnterGameBySessionIdRsp
g_decode_fun[S_2_PS_Check_Session_Req] = decode_SCheckSessionReq
g_encode_fun[S_2_PS_Check_Session_Req] = encode_SCheckSessionReq
g_decode_fun[PS_2_S_Check_Session_Rsp] = decode_SCheckSessionRsp
g_encode_fun[PS_2_S_Check_Session_Rsp] = encode_SCheckSessionRsp
g_decode_fun[C_2_PS_Login_By_SessionId_Req] = decode_SLoginBySessionIdReq
g_encode_fun[C_2_PS_Login_By_SessionId_Req] = encode_SLoginBySessionIdReq
g_decode_fun[PS_2_C_Login_By_SessionId_Rsp] = decode_SLoginBySessionIdRsp
g_encode_fun[PS_2_C_Login_By_SessionId_Rsp] = encode_SLoginBySessionIdRsp
g_decode_fun[C_2_S_Create_And_Bind_Passport_Req] = decode_SCreateAndBindPassportReq
g_encode_fun[C_2_S_Create_And_Bind_Passport_Req] = encode_SCreateAndBindPassportReq
g_decode_fun[S_2_C_Create_And_Bind_Passport_Rsp] = decode_SCreateAndBindPassportRsp
g_encode_fun[S_2_C_Create_And_Bind_Passport_Rsp] = encode_SCreateAndBindPassportRsp
g_decode_fun[S_2_PS_Try_Create_And_Bind_Passport_Req] = decode_STryCreateAndBindPassportReq
g_encode_fun[S_2_PS_Try_Create_And_Bind_Passport_Req] = encode_STryCreateAndBindPassportReq
g_decode_fun[PS_2_S_Try_Create_And_Bind_Passport_Rsp] = decode_STryCreateAndBindPassportRsp
g_encode_fun[PS_2_S_Try_Create_And_Bind_Passport_Rsp] = encode_STryCreateAndBindPassportRsp
g_decode_fun[C_2_PS_EnterGame_Notify_Req] = decode_SEnterGameNotifyReq
g_encode_fun[C_2_PS_EnterGame_Notify_Req] = encode_SEnterGameNotifyReq
g_decode_fun[PS_2_C_EnterGame_Notify_Rsp] = decode_SEnterGameNotifyRsp
g_encode_fun[PS_2_C_EnterGame_Notify_Rsp] = encode_SEnterGameNotifyRsp
g_decode_fun[S_2_PS_ServerStatus_Report_Req] = decode_SServerStatusReportReq
g_encode_fun[S_2_PS_ServerStatus_Report_Req] = encode_SServerStatusReportReq
g_decode_fun[PS_2_S_ServerStatus_Report_Rsp] = decode_SServerStatusReportRsp
g_encode_fun[PS_2_S_ServerStatus_Report_Rsp] = encode_SServerStatusReportRsp
g_decode_fun[S_2_PS_ServerStatus_Register_Req] = decode_SServerStatusRegisterReq
g_encode_fun[S_2_PS_ServerStatus_Register_Req] = encode_SServerStatusRegisterReq
g_decode_fun[PS_2_S_ServerStatus_Register_Rsp] = decode_SServerStatusRegisterRsp
g_encode_fun[PS_2_S_ServerStatus_Register_Rsp] = encode_SServerStatusRegisterRsp
g_decode_fun[C_2_PS_Logoff_Passport_Req] = decode_SLogoffPassportReq
g_encode_fun[C_2_PS_Logoff_Passport_Req] = encode_SLogoffPassportReq
g_decode_fun[PS_2_C_Logoff_Passport_Rsp] = decode_SLogoffPassportRsp
g_encode_fun[PS_2_C_Logoff_Passport_Rsp] = encode_SLogoffPassportRsp
g_decode_fun[C_2_PS_Test_Req] = decode_STestReq
g_encode_fun[C_2_PS_Test_Req] = encode_STestReq
g_decode_fun[PS_2_C_Test_Rsp] = decode_STestRsp
g_encode_fun[PS_2_C_Test_Rsp] = encode_STestRsp
g_decode_fun[C_2_S_Master_Control_Req] = decode_SMasterControlReq
g_encode_fun[C_2_S_Master_Control_Req] = encode_SMasterControlReq
g_decode_fun[S_2_C_Master_Control_Rsp] = decode_SMasterControlRsp
g_encode_fun[S_2_C_Master_Control_Rsp] = encode_SMasterControlRsp
g_decode_fun[C_2_PS_PP_Login_Req] = decode_SPPLoginReq
g_encode_fun[C_2_PS_PP_Login_Req] = encode_SPPLoginReq
g_decode_fun[PS_2_C_PP_Login_Rsp] = decode_SPPLoginRsp
g_encode_fun[PS_2_C_PP_Login_Rsp] = encode_SPPLoginRsp
g_decode_fun[PS_2_PP_Check_Login_Req] = decode_SPPCheckLoginReq
g_encode_fun[PS_2_PP_Check_Login_Req] = encode_SPPCheckLoginReq
g_decode_fun[PP_2_PS_Check_Login_Rsp] = decode_SPPCheckLoginRsp
g_encode_fun[PP_2_PS_Check_Login_Rsp] = encode_SPPCheckLoginRsp
