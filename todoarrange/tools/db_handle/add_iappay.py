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
    cursor.execute("use %(_dbname)s;"%(locals()))
        
    cursor.execute(create_iapppay)
    print "create iapppay ok"
    print "OK"

    cursor.close()
    conn.close()

#
#init_create_db_for_gameserver(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_name, server_cfg.db_port, server_cfg.serverid)
init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 4)
#init_create_db_for_gameserver("192.168.1.114", "root", "root", "lj_ceshi_4", 7002, 12)

print "OK"
