#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
os.chdir(os.getcwd()) 

from ro_tlog_define import g_all_tlog_define 

def BuildMacro(macro):
    name = macro[0]
    value = macro[1]
    template = """
        %(name)s = %(value)s"""
    return template%(locals())

def ParseMacro(macro):
    macro_list = list()
    pairs = macro.split("|")
    for pair in pairs:
        macro_list.append(pair.split(":"))
    # print macro_list
    return macro_list

def BuildMacrogroup(member):
    name = member[0]
    type = member[1]
    desc = member[2]
    macrogroup = member[3]
    if(macrogroup == ""):
        return ""
    template = """
    enum class %(name)s: uint32_t {%(all_macros)s    };    """ 
    all_macros = ",".join(map(BuildMacro, ParseMacro(macrogroup)))
    return template%(locals())


def BuildMember(member):
    name = member[0]
    type = member[1]
    desc = member[2]
    default = "0"
    if (type == "int"):
        type = "int32_t"
    elif (type in ["bigint", "int64"]):
        type = "int64_t"
    elif (type == "uint"):
        type = "uint32_t"
    elif (type in ["biguint", "uint64"]):
        type = "uint64_t"
    elif (type == "float"):
        type = "float"
    elif (type == "string" or type == "datetime"):
        type = "std::string"
        default = "\"\""
    elif (type == "double"):
        type = "double"
    else :
        return ""

    return """%(type)s %(name)s {%(default)s};
    """%(locals())

def BuildAdd(member):
    name = member[0]
    type = member[1]
    desc = member[2]

    if (type == "string" or type == "datetime"):
        return """        AddLog("%(name)s", %(name)s); 
"""%(locals())
#     elif( type == ):
#         return """        AddLog("%(name)s", GameTime::GetTimeString(%(name)s)); 
# """%(locals())
    else:
        return """        AddLog("%(name)s", ToStringTlog(%(name)s)); 
"""%(locals())

def BuildAddJson(member):
    name = member[0]
    type = member[1]
    desc = member[2]

    if (type == "string" or type == "datetime"):
        return """        AddLogJson("\\"%(name)s\\":\\""+%(name)s+"\\""); 
"""%(locals())
#     elif( type == ):
#         return """        AddLog("%(name)s", GameTime::GetTimeString(%(name)s)); 
# """%(locals())
    else:
        return """        AddLogJson("\\"%(name)s\\":"+ ToStringTlog(%(name)s)); 
"""%(locals())



g_role_common_tlog_name = "RoleCommonTlogBase"
g_role_common_tlog_define = [
    ["vGameSvrId", "string", "登录游戏服务器编号", "", 768], 
    ["dtEventTime", "datetime", "游戏事件的时间, 格式 YYYY-MM-DD HH:MM:SS", "", 768], 
    ["vGameAppid", "string", "游戏APPID", "", 768], 
    ["PlatID", "int", "ios 0 /android 1", "IOS:0|ANDROID:1", 768], 
    ["iZoneAreaID", "int", "针对分区分服的游戏填写分区id，用来唯一标示一个区；非分区分服游戏请填写0", "", 768], 
    ["vopenid", "string", "用户OPENID号", "", 768], 
    ["vRoleId", "string", "角色ID", "", 768], 
    ["vRoleName", "string", "角色姓名", "", 768], 
    ["JobId", "int", "角色职业   0=巫师 1=……", "ROLE_NONE:0|ROLE_NOVICE:1000|ROLE_SWORDMAN:2000|ROLE_ACOLYTE:3000|ROLE_MAGICIAN:4000|ROLE_THIEF:5000|ROLE_ARCHER:7000|ROLE_PRIEST:3101|ROLE_KNIGHT:2101|ROLE_WIZARD:4101|ROLE_ASSASSIN:5101|ROLE_HUNTER:7101", 768], 
    ["Gender", "int", "角色性别 0=男  1=女", "MAN:0|WOMAN:1", 768], 
    ["Level", "int", "角色基础等级", "", 768], 
    ["iJobLevel", "int", "角色职业等级", "", 768], 
    ["PlayerFriendsNum", "int", "玩家好友数量", "", 768], 
    ["ChargeGold", "int", "角色充值经历（累计充值）", "", 768], 
    ["RoleVip", "int", "角色VIP等级", "", 768], 
    ["CreateTime", "datetime", "账号创建时间", "", 768], 
    ["Power", "int", "战力/评分", "", 768], 
    ["UnionID", "bigint", "公会ID", "", 768], 
    ["UnionName", "string", "公会名称", "", 768], 
    ["RegChannel", "int", "注册渠道", "", 768], 
    ["LoginChannel", "int", "登录渠道", "", 768], 
]

def BuildCppRoleCommonStruct(name, all_member):
    template = """namespace %(name)sEnum{
%(macrogroup)s
}

class %(name)s : public ROTlogBase
{
public:
    const char * GetTableName() override
    {
        return "%(name)s"; 
    }
    static const char * TableName() 
    {
        return "%(name)s"; 
    }
public:
    %(all_members)s
};
"""
    all_add = "".join(map(BuildAdd, all_member))
    all_members = "".join(map(BuildMember, all_member))
    macrogroup = "".join(map(BuildMacrogroup, all_member))
    return template%(locals())

def CheckExtendRoleCommonTlogBase(name, all_member):
    for i in range(len(g_role_common_tlog_define)):
        found = False
        for j in range(len(all_member)):
            if len(all_member[j]) < 2:
                continue
            if g_role_common_tlog_define[i][0] == all_member[j][0] and g_role_common_tlog_define[i][1] == all_member[j][1]:
                found = True
                break
        if not found:
            return False
    return True
    
def FilterRoleCommonTlogBaseMember(member):
    if len(member) < 2:
        return True
    for i in range(len(g_role_common_tlog_define)):
        if g_role_common_tlog_define[i][0] == member[0] and g_role_common_tlog_define[i][1] == member[1]:
            return False
    return True
    
def BuildCppStruct(name, all_member):
    template = """namespace %(name)sEnum{
%(macrogroup)s
}

class %(name)s : public %(base_clase)s
{
public:
    virtual void DoAdd() override
    {
%(all_add)s
    }
    virtual void DoAddJson() override
    {
%(all_add_json)s
    }
    const char * GetTableName() override
    {
        return "%(name)s"; 
    }
    static const char * TableName() 
    {
        return "%(name)s"; 
    }
    const std::string GetVersion()
    {
        return "%(version)s"; 
    }
public:
    %(all_members)s
};
"""
    base_clase = "ROTlogBase"
    version = all_member[1][0]
    all_add = "".join(map(BuildAdd, all_member[3:]))
    all_add_json = "".join(map(BuildAddJson, all_member[3:]))
    all_members = "".join(map(BuildMember, all_member[3:]))
    macrogroup = "".join(map(BuildMacrogroup, all_member[3:]))
    if CheckExtendRoleCommonTlogBase(name, all_member):
        base_clase = g_role_common_tlog_name
        all_members = "".join(map(BuildMember, filter(FilterRoleCommonTlogBaseMember, all_member[3:])))
    return template%(locals())


h_file_name = "ro_tlog_define_auto.h"
define_auto_writefd = open(h_file_name,'w' )

define_auto_writefd.write(
"""#ifndef __RO_TLOG_DEFINE_AUTO_H__
#define __RO_TLOG_DEFINE_AUTO_H__

#include "rotlog/ro_tlog_define.h"
template<typename T>
std::string ToStringTlog(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

""")

define_auto_writefd.write(BuildCppRoleCommonStruct(g_role_common_tlog_name, g_role_common_tlog_define))

for name in g_all_tlog_define.keys():
    define_auto_writefd.write(BuildCppStruct(name, g_all_tlog_define[name]))
define_auto_writefd.write("""
#endif
""")


define_auto_writefd.close()

#自动拷贝 windows命令
import platform
if(platform.system()=='Windows'):
    os.system("copy %(h_file_name)s ..\\..\\share\\rotlog"%locals())
