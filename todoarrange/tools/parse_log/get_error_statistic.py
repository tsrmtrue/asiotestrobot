# -*- coding: gbk -*-
from parse_log import *
import sys
sys.path.append('../')
from datetime import *
from protocol_enums import *

def handle_error(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    datestr = logList[g_member_idx.index("date")]
    log2 = logList[g_member_idx.index("log2")]
    day = string.split(datestr, " ")[0]
    if i < E_LOG_EVENT_LEVEL and  i not in [ELog_Query_Role_Failed, ]:
        print "", logList
    
def print_result():
    pass

print datetime.now()

parse_all('../../../Bin/Server/log', handle_error)

print datetime.now()

print "OK"
