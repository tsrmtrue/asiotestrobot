# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def add_gang_record(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
        
    
    cursor.execute("drop table IF EXISTS gang;")
    cursor.execute(create_gang)

    for i in range(101):
        try:
            cursor.execute("INSERT INTO gang (id) VALUES(%d); "%(i))
        except :
            pass

    print "OK"
    cursor.close()
    conn.close()
 
#add_gang_record("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#add_gang_record("192.168.1.114", "root", "root", 7002, "lj_ceshi_6")    
add_gang_record(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"
