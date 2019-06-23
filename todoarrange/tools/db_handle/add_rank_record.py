# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def add_rank_record(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
        
    for i in range(30):
        try:
            cursor.execute("INSERT INTO rank (rankid) VALUES(%d); "%(i))
        except :
            pass

    print "OK"
    cursor.close()
    conn.close()
 
#add_rank_record("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#add_rank_record("192.168.1.114", "root", "root", 7002, "lj_ts_2")    
add_rank_record(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"
