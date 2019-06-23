# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def alter_role(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))

    try:
        cursor.execute("alter table role drop index idx_rolename;"%(locals()))
    except :
        print "alter role delete idx_rolename err"
    
    try:
        cursor.execute("alter table role add UNIQUE index idx_rolename (`rolename`);"%(locals()))
    except :
        print "alter table role add UNIQUE index idx_rolename err"
        
    try:
        cursor.execute("ALTER TABLE role ADD COLUMN friends BLOB DEFAULT NULL;")
    except :
        print "alter add friend err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN friendsApply BLOB DEFAULT NULL;")
    except :
        print "alter add friendapply err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN nobility INTEGER(11) DEFAULT '0';")
    except :
        print "alter add nobility err"

    try:
        cursor.execute("ALTER TABLE role ADD COLUMN lastLogoffTime INTEGER(11) DEFAULT '0';")
    except :
        print "alter add lastLogoffTime err"


    print "OK"
    cursor.close()
    conn.close()

def alter_accout_index(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))

    try:
        cursor.execute("alter table account drop index idx_macAddress;"%(locals()))
    except :
        print "alter role delete idx_rolename err"
    
    try:
        cursor.execute("alter table account add UNIQUE index idx_macAddress (`macAddress`);"%(locals()))
    except :
        print "alter table role add UNIQUE index idx_rolename err"
    
    print "OK"
    cursor.close()
    conn.close()

#alter_role("192.168.1.114", "root", "root", 7002, "lj_ceshi_6") 
alter_role(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
alter_accout_index(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)

#alter_role("127.0.0.1", "root", "root", 7001, "lj_ts_1") 
#alter_accout_index("127.0.0.1", "root", "root", 7001, "lj_ts_1")   
print "ALL OK"