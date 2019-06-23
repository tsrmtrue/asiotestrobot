# -*- coding: utf8 -*-
import sys
sys.path.append('../')
import server_cfg

import MySQLdb
from parse_sql_str import *

import string


def init_create_db_for_gameserver(_host, _user, _pwd, _dbname, _port, serverid):
    conn=MySQLdb.connect(host=_host, user=_user, passwd = _pwd, port=_port)
    cursor=conn.cursor()
    #创建表格以及初始数据
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("update role set accountid=userid-%d;"%(4*1000000))
    print "update role set accountid=userid"
 
 
    cursor.execute("drop table IF EXISTS account;")
    print "drop account ok"

    cursor.execute(create_account)
    print "create account ok"

    #
    for i in range(5000):
        macaddr = "m%05d"%(i)
        cursor.execute("INSERT INTO account (macAddress) VALUES('%(macaddr)s') ; "%(locals()))
        

    print "OK"

    cursor.close()
    conn.close()

#
#init_create_db_for_gameserver(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_name, server_cfg.db_port, server_cfg.serverid)
#init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 4)
#init_create_db_for_gameserver("127.0.0.1", "root", "root", "passport_2", 10002)
init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 8)

print "OK"
