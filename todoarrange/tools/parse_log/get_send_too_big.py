# -*- coding: utf-8 -*-
from parse_log import *
import sys
from datetime import datetime
sys.path.append('../')
from protocol_enums import *

totalcount = 0
totalLine = 0
def handle_get_send_too_big(logList, zoneid):
    if len(logList) <= 1:
        return
    global totalcount
    global g_member_idx
    global totalLine
    totalLine = totalLine + 1
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    if i == ELog_Send_Too_big:
        totalcount = totalcount + 1
    
def print_result():
    print "totoal send too big count is %d"%(totalcount)
    print "totoal line is %d"%(totalLine)
    
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_send_too_big)
print_result()
print datetime.now()

print "OK"