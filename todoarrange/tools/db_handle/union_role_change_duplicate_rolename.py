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
    cursor.execute("use %s"%(_dbname))
    for i in range(0, 100):
        #if rolename == '':
        #    continue
        mac = "m%05d"%(i)
        s = "insert into account(macAddress) VALUES('%(mac)s')"%(locals())
        print s
        cursor.execute(s)
    print "OK"

    cursor.close()
    conn.close()

#
#init_create_db_for_gameserver(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_name, server_cfg.db_port, server_cfg.serverid)
init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 4)
#init_create_db_for_gameserver("127.0.0.1", "root", "root", "passport_2", 10002)
#init_create_db_for_gameserver("192.168.1.114", "root", "root", "lj_ceshi_4", 7002, 12)

print "OK"
