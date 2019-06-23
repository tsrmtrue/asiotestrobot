# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg
import global_path
import os
from datetime import *
import string

def get_id_level_info_limt_desc(limit):
    conn=MySQLdb.connect(host=server_cfg.db_ip,user=server_cfg.db_user,passwd=server_cfg.db_pwd, port=server_cfg.db_port)
    
    cursor=conn.cursor()
    db_name = server_cfg.db_name
    cursor.execute("use %(db_name)s;"%(locals()))
    cursor.execute("select userid,level from role order by userid DESC limit %(limit)d;"%(locals()))
    rs = cursor.fetchall()
    print rs    
    cursor.close()
    conn.close()
    #写入文件
    today = "%s"%(datetime.now())
    today = string.split(today, " ")[0].replace("-", "_")
    if not os.path.exists(global_path.log_from_db_path):
        os.makedirs(global_path.log_from_db_path)
    w = open("level_%(today)s_limit_%(limit)d.py"%(locals()), 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    template = """# -*- coding: utf8 -*-
id_level_list = %(rs)r
"""
    w.write(template%(locals()))
    w.close()
    print "OK"

def get_id_level_info():
    conn=MySQLdb.connect(host=server_cfg.db_ip,user=server_cfg.db_user,passwd=server_cfg.db_pwd, port=server_cfg.db_port)
    
    cursor=conn.cursor()
    db_name = server_cfg.db_name
    cursor.execute("use %(db_name)s;"%(locals()))
    cursor.execute("select userid,level from role ;")
    rs = cursor.fetchall()
    print rs    
    cursor.close()
    conn.close()
    #写入文件
    today = "%s"%(datetime.now())
    today = string.split(today, " ")[0].replace("-", "_")
    if not os.path.exists(global_path.log_from_db_path):
        os.makedirs(global_path.log_from_db_path)
    w = open(global_path.log_from_db_path+"level_%(today)s.py"%(locals()), 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    template = """# -*- coding: utf8 -*-
id_level_list = %(rs)r
"""
    w.write(template%(locals()))
    w.close()
    print "OK"
get_id_level_info()
#get_id_level_info_limt_desc(33)