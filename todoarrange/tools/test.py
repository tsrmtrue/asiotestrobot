# -*- coding: utf8 -*-
"""
from datetime import *
d1 = date(2013, 4, 30)
d2 = date(2013, 5, 1)
d3 = date(2012, 5, 9)
td1 = d2 - d1
td2 = d3 - d2
print td1
print td2.days
td3 = timedelta(7)
print d3 - td3
s = "%s"%(d2)
print s

import os
#stat = os.system('taskkill /im gs.exe')
import time
t1 = datetime.now()
print t1
print time.sleep(1)
t2 = datetime.now()
print t2
print (t2-t1).total_seconds()

print os.path.abspath(".")

print os.path.abspath("..")

rolelist = ["accountid", 'challengeRecord', 'currentGuid', 'diamond', 'exp', "equipmentStrengthen", 'exploit', 'expTotal', 'isInit',  'itemsPacket', "loginCount", 'level', "misc", 'money', 'mates', 'prizeRecord', "professionId", 'popularity', 'randomRecruit', 'rolename', "showLevel", 'taskFinished', 'taskCurrent', 'todayPrizeRecord', 'todayFubenRecord', 'vigor', 'wingPage', 'wingCompoundStar', ]

print len(rolelist)
print sorted(rolelist)
"""

import re
http_req = """GET / HTTP/1.1
Host: 192.168.1.134:9999
Connection: keep-alive
Cache-Control: max-age=0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.76 Safari/537.36
Accept-Encoding: gzip,deflate,sdch
Accept-Language: en-US,en;q=0.8


"""
"""
pat = re.compile('^([\w]+) ([/\w]+) ')
result = pat.findall(http_req)
print result
"""
"""
import random
from datetime import *
random.seed(datetime.now())
print random.randrange(100001, 100004)
"""
"""
a=[1,2,3,4]
b=[2,4,6,9]
c=[3,4,7,9]
print list(set(a).union(b,c))
print list(set(a)|b|c)
"""
"""
for i in range(1,100):
    print '["m%06dd", "role%06d"],'%(i, i)

"""


# 测试加密解密
import sys
sys.path.append("autotest_lib")
import coder_hlp_lib
pool = [
    0x12,0x33,0x34,0x8F,
    0x12,0x33,0x34,0x8F,
    0x12,0x33,0x34,0x8F,
    0x12,0x33,0x34,0x8F,
]
poolLen = len(pool)
ts = ""
s="2bc"
count = len(s)
byteArray = coder_hlp_lib.getBuf(s, count)[0]
for i in range(count):
    byteArray[i] = byteArray[i] ^ pool[i%poolLen]
    ts += coder_hlp_lib.addByte(byteArray[i])

assert len(ts) == len(s)

ts2=""
byteArray = coder_hlp_lib.getBuf(ts, count)[0]
for i in range(count):
    byteArray[i] = byteArray[i] ^ pool[i%poolLen]
    ts2 += coder_hlp_lib.addByte(byteArray[i])

assert len(ts2) == len(ts)
print ts
print ts2
