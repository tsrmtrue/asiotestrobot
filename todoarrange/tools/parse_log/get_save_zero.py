# -*- coding: utf-8 -*-
from parse_log import *
import sys
from datetime import datetime
sys.path.append('../')
from protocol_enums import *
    
def handle_get_save_zero(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    if i == E_LOG_EVENT_SAVE_ROLE_START and userid == 0:
        #totalcount = totalcount + 1
        #print "here is a login %d"%(userid)
        print logList
    
def print_result():
    print "OK "
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_save_zero)
print_result()
print datetime.now()

print "OK"