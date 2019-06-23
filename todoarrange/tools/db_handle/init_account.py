# -*- coding: utf8 -*-
import sys
sys.path.append('../')
import server_cfg

import MySQLdb
from parse_sql_str import *


def init_create_account(_host, _user, _pwd, _port, _dbname):
    conn=MySQLdb.connect(host="127.0.0.1",user=_user,passwd = _pwd, port=_port)
    cursor=conn.cursor()

    create_user =  """GRANT ALL ON %(_dbname)s.* TO '%(_user)s'@'%(_host)s'  IDENTIFIED BY '%(_pwd)s';"""%(locals())
    print create_user
    cursor.execute(create_user)

    
    cursor.close()
    conn.close()


init_create_account(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "OK"
