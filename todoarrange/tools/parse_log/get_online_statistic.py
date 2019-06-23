# -*- coding: gbk -*-
from parse_log import *
import sys
sys.path.append('../')
from datetime import *
from protocol_enums import *
g_online_dict = {}

def add_online_report(zoneid, t, onlinecount):
    global g_online_dict
    if g_online_dict.get(zoneid, None) <> None:
        
        g_online_dict[zoneid].append([t, onlinecount])
        if len(g_online_dict[zoneid]) > 100:
            del g_online_dict[zoneid][0]
    else:
        g_online_dict[zoneid] = []
        g_online_dict[zoneid].append([t, onlinecount])
        
def handle_online(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    datestr = logList[g_member_idx.index("date")]
    log2 = logList[g_member_idx.index("log2")]
    p1 = logList[g_member_idx.index("p1")]
    
    day = string.split(datestr, " ")[0]
    if i in [E_LOG_EVENT_REPORT_ONLINE_NUMBER, ]:
        add_online_report(zoneid, datestr, p1)
        #print "", logList
    
def print_result():
    global g_online_dict
    #print g_online_list

def do_parse_online(logBaseDir):
    global g_online_dict
    g_online_dict = {}
    print datetime.now()
    parse_all(logBaseDir, handle_online)
    print datetime.now()
    
    print "OK"
