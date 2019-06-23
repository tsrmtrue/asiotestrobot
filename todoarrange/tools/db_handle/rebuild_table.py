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
    
    cursor.execute("drop table IF EXISTS role;")
    print "done 1"
    cursor.execute("drop table IF EXISTS rank;")
    print "done 2"
    cursor.execute("drop table IF EXISTS account;")
    print "done 3"
    cursor.execute("drop table IF EXISTS iap_transaction_id;")
    print "done 4"
    
    cursor.execute(create_roleinfo)
    print "done 5"
    print create_rank
    cursor.execute(create_rank)
    print "done 6"
    cursor.execute(create_account)
    print "done 7"
    cursor.execute(create_iap_transaction)
    print "done 8"
    cursor.execute("update account set macAddressCrc=crc32(macAddress);")
    cursor.execute("update role set rolenameCrc=crc32(rolename);")
    
    for i in range(20):
        cursor.execute("INSERT INTO rank (rankid) VALUES(%d); "%(i))

    print "OK"
    cursor.close()
    conn.close()
 
rebuild_tables("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#rebuild_tables(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"