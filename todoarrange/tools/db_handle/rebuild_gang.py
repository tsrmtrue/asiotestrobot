# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def rebuild_tables(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("drop table IF EXISTS gang;")
    print "done 1"
    
    cursor.execute(create_gang)
    print "done 5"
    

    print "OK"
    cursor.close()
    conn.close()
 
rebuild_tables("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#rebuild_tables("192.168.1.114", "root", "root", 7002, "lj_ceshi_7")    
#rebuild_tables(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"