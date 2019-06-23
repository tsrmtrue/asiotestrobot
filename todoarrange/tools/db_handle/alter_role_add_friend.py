# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def alter_role_add_friend(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN friends BLOB DEFAULT NULL;")
    except :
        print "alter 1 err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN friendsApply BLOB DEFAULT NULL;")
    except :
        print "alter 1 err"

    
    print "OK"
    cursor.close()
    conn.close()

alter_role_add_friend("192.168.1.114", "root", "root", 7002, "lj_ts_2") 
#alter_role_add_friend("127.0.0.1", "root", "root", 7001, "lj_ts_1") 
print "ALL OK"