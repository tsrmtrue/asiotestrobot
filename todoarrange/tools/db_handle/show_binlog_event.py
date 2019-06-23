# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg
import string

from parse_sql_str import *

def show_binlog_events(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("show binlog events in 'mysql_binlog_lj_ts_1.000005';")
    rs = cursor.fetchall()
    for r in rs :
        #print r
        if string.find(r[5], "WHERE userid='147'")>0:
            print r
    cursor.close()
    conn.close()

def do_recover(_host, _user, _passwd, _port, _dbname, source_file):
    """
    mysqlbinlog --start-position="205" --stop-position="8772" --to-last-log ../data/mysql_binlog_lj_ts_1.000001 > delete_mate.sql
     | mysql -uroot -pmypwd
mysqlbinlog --start-position="" --stop-position="" ../data/ > check_mate.sql
    """
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("source '%s';"%(source_file))
    cursor.close()
    conn.close()
    
show_binlog_events("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#do_recover("127.0.0.1", "root", "root", 7001, "lj_ts_1", "recover_mate.sql")
