# -*- coding: utf-8 -*-
from parse_log import *
import sys
from datetime import datetime
sys.path.append('../')
from protocol_enums import *

step_counts_dict = {
                    #"log1":count,
                    }

def add_login_step(para1, log1):
    global step_counts_dict
    r = step_counts_dict.get(log1, None)
    if r == None:
        step_counts_dict[log1] = 1
    else :
        step_counts_dict[log1] = r+1

def handle_get_login_step(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    para1 = int(logList[g_member_idx.index("p1")])
    logs = logList[g_member_idx.index("log1")]
    if i in [E_LOG_EVENT_LOGIN_NUMBER, E_LOG_EVENT_LOGOUT, ELog_Send_Too_big]:
        #totalcount = totalcount + 1
        #print "here is a login %d"%(userid)
        add_login_step(para1, logs)
    
def print_result():
    global step_counts_dict
    for i in  sorted(step_counts_dict.keys()):
        print "%r: %r"%(i, step_counts_dict[i])
    
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_login_step)
print_result()
print datetime.now()

print "OK"