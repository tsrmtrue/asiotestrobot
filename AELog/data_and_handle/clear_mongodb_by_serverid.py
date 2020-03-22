# -*- coding: utf-8 -*-

#!/usr/bin/python3
import os
import time
import datetime
import pymongo


"""
流程
第一次需要先手动执行删除
然后开启crontab ,每个整点的05 分 执行一次 rsync同步，然后使用脚本入库，不需要执行太多。这样就可以
5 * * * * rsync -av root@129.211.130.180:/data/ro_out_chenxi/tlog_backup_zip /data/chenxi/tlog_all && cd /data/chenxi/tlog_all && python3 commit_ro_tlog_mongo_from_zip.py
"""
serverid = "6"
#清空mongodb
myclient = pymongo.MongoClient("mongodb://10.1.4.5:27017/")
mydb = myclient["ro_tlog_tx_test"]
mycol = mydb['ro_tlog']
#删除指定serverid的库  要填上自己的serverid
mycol.delete_many({'vgamesvrid': serverid})
print("clear mongo " + serverid)
