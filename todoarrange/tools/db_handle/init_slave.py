# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg
import global_path
import os
from datetime import *
import string

def grant_slave():
    conn=MySQLdb.connect(host=server_cfg.db_ip,user=server_cfg.db_user,passwd=server_cfg.db_pwd, port=server_cfg.db_port)
    cursor=conn.cursor()
    db_name = server_cfg.db_name
    slave_host=""
    slave_user=""
    slave_pwd = ""
    cursor.execute("grant replication slave on *.* to '%(slave_user)s'@'%(slave_host)s' identified by '%(slave_pwd)s';"%(locals()))
    cursor.execute("flush privileges;")
    cursor.close()
    conn.close()
    print "OK"
"""
change master to master_host='120.31.136.164', MASTER_PORT=8001, master_user='slave2', master_password='slave2', master_log_file='mysql-bin.000009', master_log_pos=120;
"""

