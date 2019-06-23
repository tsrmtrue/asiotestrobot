# -*- coding: utf8 -*-
import string

def get_server_cfg(cfgFileName, targetid):
    f = open(cfgFileName, 'r')
    s = f.readline()
    global g_member_idx
    s = f.readline()

    while s <> "":
        #print s
        r = string.split(s, ',')
        #print r
        id = int(r[0])
        servername = r[1]
        if id == targetid:
            d = {}
            d["id"]             = r[0]  #; //﻿服务器组编号
            d["name"]           = r[1]  #; //名字
            d["ip"]             = r[2]  #; //ip
            d["port"]           = r[3]  #; //port
            d["db_ip"]          = r[4]  #; //db_ip
            d["db_port"]        = r[5]  #; //db_port
            d["db_u"]           = r[6]  #; //db_u
            d["db_p"]           = r[7]  # [32]; //db_p
            d["db"]             = r[8]  #char [32]; //db
            d["rolelimit"]      = r[9]  #int ; //玩家上限
            d["sleep"]          = r[10]  #int ; //主循环睡眠
            d["iocpworkers"]    = r[11]  #int ; //完成端口工作者线程
            d["isopen"]         = r[12]  #int ; //是否公开
            d["globalNtf"]      = r[13]  #char [2048]; //公告

            return d
        s = f.readline()
    return None
"""
import os
import os.path

import version_control_global_setting as vcgs

d = get_server_cfg(vcgs.g_server_instance_path + "/lj_server_4/cfg/fuwuqipeizhi_utf8.csv", 4)
print d
"""