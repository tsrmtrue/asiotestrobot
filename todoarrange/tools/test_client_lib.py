# -*- coding: utf8 -*-

from protocol_enums import  *
from protocol_json_str import *
import string
import struct

#选择协议版本,特殊处理,这里发送的是二进制版本
def build_SProtocolTypeRpt_str(type):
    s = struct.pack("!B", type)
    
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Protocol_Type_Rpt)
    sendbuf += s
    return sendbuf
    

#登陆
def build_SLoginReq_str(account, mac, pwd, type):
    s = SLoginReq
    if account <> "":
        s = s.replace('"account":""', '"account":"%s"'%(account))
    if mac <> "":
        s = s.replace('"mac":""', '"mac":"%s"'%(mac))
    if pwd <> "":
        s = s.replace('"pwd":""', '"pwd":"%s"'%(pwd))
    if type <> 0:
        s = s.replace('"type":0', '"type":%d'%(type))
    
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Login_Req)
    sendbuf += s
    return sendbuf

#进入
def build_SEnterReq_str():
    s = SEnterReq
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Enter_Req)
    sendbuf += s
    return sendbuf

#加载完毕
def build_SLoadFinishedReq_str():
    s = SLoadFinishedReq
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_LoadFinished_Req)
    sendbuf += s
    return sendbuf

#创建角色
def build_SCreateReq_str(rolename, professionId):
    s = SCreateReq
    if rolename <> "":
        s = s.replace('"rolename":""', '"rolename":"%s"'%(rolename))
    if professionId <> 0:
        s = s.replace('"professionId":0', '"professionId":%d'%(professionId))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Create_Req)
    sendbuf += s
    return sendbuf

#移动
def build_SMovetoReq_str(x, y):
    s = SMovetoReq
    if x <> 0:
        s = s.replace('"x":0', '"x":%d'%(x))
    if y <> 0:
        s = s.replace('"y":0', '"y":%d'%(y))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Moveto_Req)
    sendbuf += s
    return sendbuf

#npc对话
def build_SNpcTalkReq_str(npcid):
    s = SNpcTalkReq
    if npcid <> 0:
        s = s.replace('"npcid":0', '"npcid":%d'%(npcid))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Npc_Talk_Req)
    sendbuf += s
    return sendbuf

#跳转npc对话
def build_SNpcTalkJumpPageReq_str(npcid, page):
    s = SNpcTalkJumpPageReq
    if npcid <> 0:
        s = s.replace('"npcid":0', '"npcid":%d'%(npcid))
    if page <> 0:
        s = s.replace('"page":0', '"page":%d'%(page))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Npc_Talk_Jump_Page_Req)
    sendbuf += s
    return sendbuf

#任务操作
def build_STaskOperationReq_str(taskid, operation, npcid):
    s = STaskOperationReq
    if taskid <> 0:
        s = s.replace('"taskid":0', '"taskid":%d'%(taskid))
    if operation <> 0:
        s = s.replace('"operation":0', '"operation":%d'%(operation))
    if npcid <> 0:
        s = s.replace('"npcid":0', '"npcid":%d'%(npcid))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Task_Operation_Req)
    sendbuf += s
    return sendbuf

#进入副本
def build_SEnterFubenReq_str(fubenid):
    s = SEnterFubenReq
    if fubenid <> 0:
        s = s.replace('"fubenid":0', '"fubenid":%d'%(fubenid))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_EnterFuben_Req)
    sendbuf += s
    return sendbuf

#开始战斗
def build_SFightReq_str():
    s = SFightReq
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Fight_Req)
    sendbuf += s
    return sendbuf

#退出副本
def build_SLeaveFubenReq_str():
    s = SLeaveFubenReq
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_LeaveFuben_Req)
    sendbuf += s
    return sendbuf

#副本导航信息
def build_SGetFubenNavigationReq_str(itemid):
    s = SGetFubenNavigationReq
    if itemid <> 0:
        s = s.replace('"itemid":0', '"itemid":%d'%(itemid))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Get_Fuben_Navigation_Req)
    sendbuf += s
    return sendbuf
    
#背包交换格子
def build_SInterchangeInPacketReq_str(fromType, indexFrom, toType, indexTo):
    s = SInterchangeInPacketReq
    if fromType <> 0:
        s = s.replace('"fromType":0', '"fromType":%d'%(fromType))
    if indexFrom <> 0:
        s = s.replace('"indexFrom":0', '"indexFrom":%d'%(indexFrom))
    if toType <> 0:
        s = s.replace('"toType":0', '"toType":%d'%(toType))
    if indexTo <> 0:
        s = s.replace('"indexTo":0', '"indexTo":%d'%(indexTo))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Interchange_In_Packet_Req)
    sendbuf += s
    return sendbuf

#丢弃物品
def build_SDropItemInPacketReq_str(type, index):
    s = SDropItemInPacketReq
    if index <> 0:
        s = s.replace('"index":0', '"index":%d'%(index))
    if type <> 0:
        s = s.replace('"type":0', '"type":%d'%(type))    
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_DropItem_In_Packet_Req)
    sendbuf += s
    return sendbuf

#使用物品
def build_SUseItemInPacketReq_str(index, type):
    s = SUseItemInPacketReq
    if index <> 0:
        s = s.replace('"index":0', '"index":%d'%(index))
    if type <> 0:
        s = s.replace('"type":0', '"type":%d'%(type))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_UseItem_In_Packet_Req)
    sendbuf += s
    return sendbuf
    
#解锁格子
def build_SUnlockGripInPacketReq_str(type, index):
    s = SUnlockGripInPacketReq
    if index <> 0:
        s = s.replace('"index":0', '"index":%d'%(index))
    if type <> 0:
        s = s.replace('"type":0', '"type":%d'%(type))    
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_UnlockGrid_In_Packet_Req)
    sendbuf += s
    return sendbuf

#重新整理背包
def build_SReorganizeInPacketReq_str(type):
    s = SReorganizeInPacketReq
    if type <> 0:
        s = s.replace('"type":0', '"type":%d'%(type))  
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Reorganize_In_Packet_Req)
    sendbuf += s
    return sendbuf

#刷新声望雇佣列表

#刷新钻石雇佣列表

#雇佣

#出战

#休战

#精炼

#强化装备

#升级翅膀

#gm命令
def build_SGmcmdReq_str(cmd):
    s = SGmcmdReq
    if cmd <> "":
        s = s.replace('"cmd":""', '"cmd":"%s"'%(cmd))
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_GmCmd_Req)
    sendbuf += s
    return sendbuf

#提交iap回执
def build_SIapCommitReceiptReq(count, receiptData):
    s = SIapCommitReceiptReq
    if count <> "":
        s = s.replace('"count":0', '"count":%d'%(count))
    if receiptData <> "":
        s = s.replace('"receiptData":""', '"receiptData":"%s"'%(receiptData))
        
    sendbuf = struct.pack("!H", len(s)+4)
    sendbuf += struct.pack("!H", C_2_S_Iap_Commit_Receipt_Req)
    sendbuf += s
    return sendbuf
    
"""
#test
print build_SLoginReq_str("", "", "", 0)

print build_SLoginReq_str("a", "", "", 0)

print build_SLoginReq_str("", "b", "", 0)

print build_SLoginReq_str("", "", "c", 0)

print build_SLoginReq_str("", "", "", 4)

print build_SLoginReq_str("a", "b", "c", 0)

print build_SLoginReq_str("", "b", "", 5)

print build_SCreateReq_str("", 0)

print build_SCreateReq_str("a", 0)

print build_SCreateReq_str("", 2)

print build_SCreateReq_str("a", 3)

print build_SMovetoReq_str(0, 0)

print build_SMovetoReq_str(0, 1)

print build_SMovetoReq_str(1, 0)

print build_SMovetoReq_str(1, 1)

print build_SNpcTalkReq_str(0)

print build_SNpcTalkReq_str(1)

print build_SNpcTalkJumpPageReq_str(0, 0)

print build_SNpcTalkJumpPageReq_str(1, 0)

print build_SNpcTalkJumpPageReq_str(0, 1)

print build_SNpcTalkJumpPageReq_str(1, 1)

print build_STaskOperationReq_str(0, 0, 0)

print build_STaskOperationReq_str(0, 1, 0)

print build_STaskOperationReq_str(0, 1, 2)

print build_STaskOperationReq_str(3, 1, 2)

print build_SEnterFubenReq_str(1)

print build_SEnterFubenReq_str(0)

print build_SFightReq_str()

print build_SLeaveFubenReq_str()

print build_SGetFubenNavigationReq_str(0)

print build_SGetFubenNavigationReq_str(3)

print build_SInterchangeInPacketReq_str(0, 0, 0, 0)

print build_SInterchangeInPacketReq_str(0, 3, 0, 0)

print build_SInterchangeInPacketReq_str(0, 0, 6, 0)

print build_SInterchangeInPacketReq_str(1, 2, 3, 50)

print build_SUseItemInPacketReq_str(0, 0)

print build_SUseItemInPacketReq_str(10, 20)

print build_SUnlockGripInPacketReq_str(0, 0)

print build_SUnlockGripInPacketReq_str(40, 50)

print build_SDropItemInPacketReq_str(0, 0)

print build_SDropItemInPacketReq_str(10, 20)

print build_SReorganizeInPacketReq_str(0)

print build_SReorganizeInPacketReq_str(10)

print build_SGmcmdReq_str("setmoney 10 10 10 10 ")

"""

