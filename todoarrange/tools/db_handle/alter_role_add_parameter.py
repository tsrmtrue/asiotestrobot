# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def alter_role_add_parameter(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN paremeterNow BLOB DEFAULT NULL;")
    except :
        print "alter 1 err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN paremeterMin BLOB DEFAULT NULL;")
    except :
        print "alter 2 err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN paremeterMax BLOB DEFAULT NULL;")
    except :
        print "alter 3 err"
    
    print "OK"
    cursor.close()
    conn.close()
alter_role_add_parameter(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name) 
#alter_role_add_friend("127.0.0.1", "root", "root", 7001, "lj_ts_1") 
print "ALL OK"