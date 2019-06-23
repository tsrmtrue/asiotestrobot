# -*- coding: utf8 -*-
import MySQLdb

conn=MySQLdb.connect(host="127.0.0.1",user="root",passwd="root", port=7001)

cursor=conn.cursor()

stuff_str = "a"*51200
print stuff_str[100:129]

print len(stuff_str)
print stuff_str
cursor.execute("use lj_ts_1;")
i=0
#stuff account
while i<1000000:
    accountid=i
    mac = "stmac%d"%(i)
    #cursor.execute("INSERT INTO account (accountid,macAddress) VALUES(%(accountid)d, '%(mac)s') ;"%(locals()))
    #rolename="rn%d"%(i)
    #cursor.execute("INSERT INTO role (accountid,rolename, mates) VALUES('%(accountid)d','%(rolename)s', '%(stuff_str)s'); "%(locals()) )
    passport = "pspt%d"%(i)
    pwd = "pwd%d"%(i)
    qq = i
    email="%(qq)d@qq.com"%(locals())
    cursor.execute("INSERT INTO passport (passport, pwd,email,qq) VALUES('%(passport)s', '%(pwd)s', '%(email)s', %(qq)d) ;"%(locals()))
    
    i = i +1
    
cursor.close()
conn.close()

print "OK"
