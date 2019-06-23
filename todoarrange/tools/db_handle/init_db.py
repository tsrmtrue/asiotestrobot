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
    #创建数据库
    create_template = """
CREATE DATABASE IF NOT EXISTS %(_dbname)s CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""
    cursor.execute(create_template%(locals()))
    #创建用户
    create_user =  """GRANT ALL ON %(_dbname)s.* TO '%(_user)s'@'%(_host)s'  IDENTIFIED BY '%(_pwd)s';"""%(locals())
    print create_user
    cursor.execute(create_user)

    #创建表格以及初始数据
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("drop table IF EXISTS role;")
    print "drop role ok"
    cursor.execute("drop table IF EXISTS rank;")
    print "drop rank ok"
    cursor.execute("drop table IF EXISTS account;")
    print "drop account ok"
    cursor.execute("drop table IF EXISTS iap_transaction_id;")
    print "drop iap_transaction_id ok"
    cursor.execute("drop table IF EXISTS gang;")
    print "drop gang ok"
    cursor.execute("drop table IF EXISTS iapppay;")
    print "drop iapppay ok"
    
    #创建角色的时候,要根据区号,把userid的起始设定成新区的,id设定为signed,最大0x7fffffff,
    #每个区1000000个id,一共可以开2000个区
    userid_start = serverid*1000000
    create_r = g_sql_map['role'].replace("AUTO_INCREMENT=1", "AUTO_INCREMENT=%(userid_start)d"%(locals()))
    cursor.execute(create_r)
    print "create role ok"
    cursor.execute(create_rank)
    print "create rank ok"
    cursor.execute(create_account)
    print "create account ok"
    cursor.execute(create_iap_transaction)
    print "create iap ok"
    cursor.execute(create_gang)
    print "create gang ok"
    cursor.execute(create_iapppay)
    print "create iapppay ok"

    #rank表格 预先插入100个预留字段
    for i in range(100):
        cursor.execute("INSERT INTO rank (rankid) VALUES(%d); "%(i))
        
    #gang表格,预先插入200个预留字段
    for i in range(201):
        try:
            cursor.execute("INSERT INTO gang (id) VALUES(%d); "%(i))
        except :
            print "INSERT INTO gang (id) VALUES(%d); "%(i)

    print "OK"

    cursor.close()
    conn.close()
    
    
import server_config_parse as scp
def init_db_from_cfg(serverid):
    server_conf_dict_file = "../../cfg/fuwuqipeizhi_utf8.csv"
    scd = scp.get_server_cfg(server_conf_dict_file, serverid)
    if scd == None:
        print "not found the server ",serverid
        return 
    init_create_db_for_gameserver(scd['db_ip'], scd['db_u'], scd['db_p'], scd['db'], int(scd['db_port']), serverid)

#
#init_db_from_cfg(8)
init_create_db_for_gameserver(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_name, server_cfg.db_port, server_cfg.serverid)
#init_create_db_for_gameserver("127.0.0.1", "root", "root", "lj_ts_1", 7001, 4)
#init_create_db_for_gameserver("192.168.1.114", "root", "root", "lj_ts_2", 7002, 1)
print "OK"
#init_db_from_cfg(8)