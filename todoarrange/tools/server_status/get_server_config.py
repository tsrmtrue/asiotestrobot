# -*- coding: utf8 -*-
import string
g_ss_dict = {}

def handler_master_server_config(r):
    global g_ss_dict
    if len(r) < 14:
        return
    isopen = r[12]
    #配置中的 是 枚举值为29
    print r[0], isopen
    if isopen <> '是':
        return
    servername = r[1]
    ip = r[2]
    port = r[3]
    serverstatus = 2 #维护
    globalntf = r[13]
    g_ss_dict[servername] = [servername, ip, port, serverstatus, globalntf]

    
def init_master_server_status(configureFile):
    f = open(configureFile, 'r')
    s = f.readline()
    global g_member_idx
    s = f.readline()

    while s <> "":
        #print s
        r = string.split(s, ',')
        #print r
        handler_master_server_config(r)
        s = f.readline()

def get_server_id(filename):
    f = open(filename, 'r')
    s = f.readline()
    return int(s)

def get_server_name(cfgFileName, targetid):
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
            return servername
        s = f.readline()
    return "None_%(id)d"%(locals())

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
            return r
        s = f.readline()
    return []

def build_iap_info(iapid, rmb):
    return """iap_rmb_dict["%(iapid)s"] = %(rmb)s"""%(locals())

def get_server_iap_info(cfgFileName):
    f = open(cfgFileName, 'r')
    s = f.readline()
    s = f.readline()
    iap_info = ""
    while s <> "":
        #print s
        r = string.split(s, ',')
        #print r
        iapid = r[0]
        rmb = r[4]
        iap_info += build_iap_info(iapid, rmb)
        s = f.readline()

    return iap_info

def get_server_name_by_cfg(serverIdFile, cfgFileName):
    return get_server_name(cfgFileName, get_server_id(serverIdFile))

def get_this_server_cfg(serverIdFile, cfgFileName):
    return get_server_cfg(cfgFileName, get_server_id(serverIdFile))
def get_slave_server_status(logfile):
    pass