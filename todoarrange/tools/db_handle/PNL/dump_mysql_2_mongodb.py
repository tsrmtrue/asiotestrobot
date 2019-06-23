# -*- coding: utf8 -*-
import sys
sys.path.append('../../')

import MySQLdb

import string


from pymongo import MongoClient





def do():

    client = MongoClient()

    db = client.bilibili
    cl = db.collection

    conn=MySQLdb.connect(host="127.0.0.1", user="root", passwd = "root", port=3306, charset='utf8')
    cursor=conn.cursor()
    print conn.character_set_name()
    cursor.execute("use bc;")
    #创建数据库
    limit_start = 0
    limit_add = 1000
    total = 40000000
    for x in xrange(1,total/limit_add):
        limit_start = limit_start + limit_add
        create_template = """select * from collection limit %(limit_start)d, %(limit_add)d;"""%(locals())
        cursor.execute(create_template%(locals()))
        #创建用户
        for row in cursor.fetchall():      
            id = row[0]
            up = row[1]
            title=row[2]
            cl.insert_one(
                {
                "id":id,
                "up":up,
                "title":title
                }
                )

    cursor.close()
    conn.close()
    
    
do()