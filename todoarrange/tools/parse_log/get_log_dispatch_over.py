# -*- coding: utf-8 -*-
from parse_log import *
import sys
from datetime import datetime
sys.path.append('../')
from protocol_enums import *
import string
save_failed = {
                    #"log1":count,
                    }


def handle_get_dispatch_failed(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    para1 = int(logList[g_member_idx.index("p1")])
    para2 = int(logList[g_member_idx.index("p2")])
    logs = logList[g_member_idx.index("log1")]
    if -1 <> string.find(logs, "dispatch"):
        #totalcount = totalcount + 1
        print "here is a dispatch failed  %r"%(para2)
    
def print_result():
    print "OK"
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_dispatch_failed)
print_result()
print datetime.now()

print "OK"