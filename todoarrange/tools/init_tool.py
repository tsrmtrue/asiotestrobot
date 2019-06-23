# -*- coding: utf8 -*-
import os
import string

def get_global_cfg():
    path_template = """# -*- coding: utf8 -*-
real_path = "%(cur_bin_path)s"

log_path = real_path+"log/"
cfg_path = real_path+"cfg/"
report_path = real_path+"report/"
gameserver_path = real_path+"gameserver/"
roledump_path = real_path+"roledump/"
serverid_file = real_path+"server_id.txt"
tools_path = real_path+"tools/"
parse_log_path = tools_path + "parse_log/"
iap_file = cfg_path + "iap_utf8.csv"
db_handle_path = tools_path + "db_handle/"
log_from_db_path = db_handle_path + "log_from_db/"
"""
    
    cur_bin_path = os.path.abspath("..").replace("\\", "/") + "/"
    return path_template%(locals())

def get_server_cfg(server_cfg_dict):
    d = server_cfg_dict
    iap_init = ""#get_server_config.get_server_iap_info(global_path.iap_file)
    serverid                = d["id"]
    servername              = d["name"]
    ip                      = d["ip"]
    port                    = d["port"]
    db_ip                   = d["db_ip"]
    db_port                 = d["db_port"]
    db_user                 = d["db_u"]
    db_pwd                  = d["db_p"]
    db_name                 = d["db"]
    role_limit              = d["rolelimit"]
    loop_sleep              = d["sleep"]
    iocp_worker_count       = d["iocpworkers"]
    is_open                 = d["isopen"]
    global_ntf              = d["globalNtf"]
    
    server_cfg_template = """# -*- coding: utf8 -*-
serverid = %(serverid)s
servername = "%(servername)s"
ip = "%(ip)s"
port = %(port)s
db_ip = "%(db_ip)s"
db_port = %(db_port)s
db_user = "%(db_user)s"
db_pwd = "%(db_pwd)s"
db_name = "%(db_name)s"
role_limit = %(role_limit)s
loop_sleep = %(loop_sleep)s
iocp_worker_count = %(iocp_worker_count)s
is_open = "%(is_open)s"
global_ntf = \"\"\"%(global_ntf)s\"\"\"
iap_rmb_dict = {}
iap_rmb_dict["diamond_60"]      = 6
iap_rmb_dict["diamond_320"]     = 30
iap_rmb_dict["diamond_1410"]    = 128
iap_rmb_dict["diamond_3780"]    = 328
iap_rmb_dict["diamond_7780"]    = 648
iap_rmb_dict["diamond_180"]     = 18
iap_rmb_dict["diamond_250"]     = 25
iap_rmb_dict["diamond_525"]     = 50
iap_rmb_dict["diamond_official_60"]      = 6
iap_rmb_dict["diamond_official_320"]     = 30
iap_rmb_dict["diamond_official_1410"]    = 128
iap_rmb_dict["diamond_official_3780"]    = 328
iap_rmb_dict["diamond_official_7780"]    = 648
iap_rmb_dict["diamond_official_180"]     = 18
iap_rmb_dict["diamond_official_250"]     = 25
iap_rmb_dict["diamond_official_525"]     = 50
%(iap_init)s
    """
    return server_cfg_template%(locals())

def init_server_cfg(server_cfg_dict):
    path_template = """# -*- coding: utf8 -*-
real_path = "%(cur_bin_path)s"

log_path = real_path+"log/"
cfg_path = real_path+"cfg/"
report_path = real_path+"report/"
gameserver_path = real_path+"gameserver/"
roledump_path = real_path+"roledump/"
serverid_file = real_path+"server_id.txt"
tools_path = real_path+"tools/"
parse_log_path = tools_path + "parse_log/"
iap_file = cfg_path + "iap_utf8.csv"
db_handle_path = tools_path + "db_handle/"
log_from_db_path = db_handle_path + "log_from_db/"
"""
    
    cur_bin_path = os.path.abspath("..").replace("\\", "/") + "/"
    print "current bin path", cur_bin_path
    w = open("global_path.py", 'w')
    w.write(path_template%(locals()))
    w.close()
    
    d = server_cfg_dict
    iap_init = ""#get_server_config.get_server_iap_info(global_path.iap_file)
    serverid                = d["id"]
    servername              = d["name"]
    ip                      = d["ip"]
    port                    = d["port"]
    db_ip                   = d["db_ip"]
    db_port                 = d["db_port"]
    db_user                 = d["db_u"]
    db_pwd                  = d["db_p"]
    db_name                 = d["db"]
    role_limit              = d["rolelimit"]
    loop_sleep              = d["sleep"]
    iocp_worker_count       = d["iocpworkers"]
    is_open                 = d["isopen"]
    global_ntf              = d["globalNtf"]

    server_cfg_template = """# -*- coding: utf8 -*-
serverid = %(serverid)s
servername = "%(servername)s"
ip = "%(ip)s"
port = %(port)s
db_ip = "%(db_ip)s"
db_port = %(db_port)s
db_user = "%(db_user)s"
db_pwd = "%(db_pwd)s"
db_name = "%(db_name)s"
role_limit = %(role_limit)s
loop_sleep = %(loop_sleep)s
iocp_worker_count = %(iocp_worker_count)s
is_open = "%(is_open)s"
global_ntf = \"\"\"%(global_ntf)s\"\"\"
iap_rmb_dict = {}
iap_rmb_dict["diamond_60"]      = 6
iap_rmb_dict["diamond_320"]     = 30
iap_rmb_dict["diamond_1410"]    = 128
iap_rmb_dict["diamond_3780"]    = 328
iap_rmb_dict["diamond_7780"]    = 648
iap_rmb_dict["diamond_180"]     = 18
iap_rmb_dict["diamond_250"]     = 25
iap_rmb_dict["diamond_525"]     = 50
iap_rmb_dict["diamond_official_60"]      = 6
iap_rmb_dict["diamond_official_320"]     = 30
iap_rmb_dict["diamond_official_1410"]    = 128
iap_rmb_dict["diamond_official_3780"]    = 328
iap_rmb_dict["diamond_official_7780"]    = 648
iap_rmb_dict["diamond_official_180"]     = 18
iap_rmb_dict["diamond_official_250"]     = 25
iap_rmb_dict["diamond_official_525"]     = 50
%(iap_init)s
    """
    w = open("server_cfg.py", 'w')
    w.write(server_cfg_template%(locals()))
    w.close()
    
    print "OK"
