# -*- coding: utf-8 -*-
from parse_log import *
import sys
from datetime import datetime
sys.path.append('../')
from protocol_enums import *

save_failed = {
                    #"log1":count,
                    }

def add_save_failed(userid, log1):
    global save_failed
    print 
    save_failed[userid] = log1

def print_save_failed():
    global save_failed
    for userid in sorted(save_failed.keys()):
        print " %r %r"%(userid, save_failed[userid])

def handle_get_save_failed(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    para1 = int(logList[g_member_idx.index("p1")])
    logs = logList[g_member_idx.index("log1")]
    if i in [ELog_Save_Role_Failed]:
        #totalcount = totalcount + 1
        print "here is a savefailed %d"%(userid)
        add_login_step(userid, logs)
    
def print_result():
    print_save_failed()    
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_save_failed)
print_result()
print datetime.now()

print "OK"