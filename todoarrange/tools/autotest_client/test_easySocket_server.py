# -*- coding: utf8 -*-
from test_easySocket import *
import time
print "server start"
s = XHWServer('127.0.0.1', 9999)
while s.run() == True:
    pass
    #time.sleep(0.001)

print "server all over"
    