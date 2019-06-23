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
    
    cursor.execute("drop table IF EXISTS passport;")
    print "done 1"
    
    cursor.execute(create_passport)
    print "done 2"
    
    cursor.execute("drop table IF EXISTS lj_role;")
    print "done 3"
    
    cursor.execute(create_lj_role)
    print "done 4"

    print "OK"
    cursor.close()
    conn.close()
 
rebuild_tables("127.0.0.1", "root", "root", 10002, "passport_2")    
#rebuild_tables(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"