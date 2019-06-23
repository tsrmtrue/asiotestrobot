# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

conn=MySQLdb.connect(host=server_cfg.db_ip,user=server_cfg.db_user,passwd=server_cfg.db_pwd, port=server_cfg.db_port)

cursor=conn.cursor()
db_name = server_cfg.db_name
cursor.execute("use %(db_name)s;"%(locals()))
cursor.execute("select userid,diamond from role;")
rs = cursor.fetchall()
for r in rs:
    userid = r[0]
    diamond = int(r[1])
    diamond = diamond + 1000
    print r
    update = "update role set diamond=%(diamond)d where userid=%(userid)s"%(locals())
    cursor.execute(update)
    
conn.commit()
cursor.close()
conn.close()
print "OK"
