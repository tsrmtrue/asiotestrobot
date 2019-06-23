# -*- coding: utf8 -*-
import sys
sys.path.append('../')
import server_cfg

import MySQLdb
from parse_sql_str import *

import string


def init_create_db_for_gameserver(_host, _user, _pwd, _dbname, _port, serverid):
    conn=MySQLdb.connect(host="127.0.0.1", user=_user, passwd = _pwd, port=_port)
    cursor=conn.cursor()
    #cursor.execute("DROP database %(_dbname)s "%(locals()))
    #create_user = """CREATE USER '%(_user)s'@'%(_host)s' IDENTIFIED BY '%(_pwd)s';"""%(locals())
    #print create_user
    #cursor.execute(create_user)
    #创建数据库
    create_template = """
CREATE DATABASE IF NOT EXISTS %(_dbname)s CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""
    cursor.execute(create_template%(locals()))
    #创建用户
    create_user =  """GRANT ALL ON %(_dbname)s.* TO '%(_user)s'@'%(_host)s'  IDENTIFIED BY '%(_pwd)s';"""%(locals())
    print create_user
    cursor.execute(create_user)
    #创建表格以及初始数据
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("drop table IF EXISTS passport;")
    print "done 1"
    
    cursor.execute(create_passport)
    print "done 2"
    
    cursor.execute("drop table IF EXISTS lj_role;")
    print "done 3"
    
    cursor.execute(create_lj_role)
    print "done 4"
    
    cursor.execute("drop table IF EXISTS pp_passport;")
    print "done 5"
    
    cursor.execute(create_pp_passport)
    print "done 6"
    
    cursor.execute("drop table IF EXISTS lj_pp_role;")
    print "done 7"
    
    cursor.execute(create_lj_pp_role)
    print "done 8"

    cursor.close()
    conn.close()

#
init_create_db_for_gameserver(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_name, server_cfg.db_port, server_cfg.serverid)
#init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 4)
#init_create_db_for_gameserver("192.168.1.141", "root", "root", "lj_passport_1", 30002, 10001)

print "OK"
