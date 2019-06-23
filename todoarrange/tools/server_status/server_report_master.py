# -*- coding: utf8 -*-
from easySocket_server_reporter import *
import time
print "server start"
s = ServerReportListener('127.0.0.1', 9999)
s.init_all_server_cfg("../../../Bin/Server/cfg/fuwuqipeizhi_utf8.csv")
while s.run() == True:
    time.sleep(1)

print "server all over"
    