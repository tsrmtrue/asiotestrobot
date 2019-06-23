# -*- coding: utf-8 -*-
from parse_log import *
import sys
sys.path.append('../')
from datetime import datetime
from protocol_enums import *

totalcount = 0
totalLine = 0
role_login = {
              #userid:[loginCount,logoutCount],
              }

def add_login_logout(userid, loginOrLogout):
    global role_login
    r = role_login.get(userid, None)
    if r<>None:
        r[loginOrLogout] = r[loginOrLogout]+1
    else:
        r = [0,0]
        r[loginOrLogout] = 1
        role_login[userid] = r
        
    
def handle_get_login_logout(logList, zoneid):
    if len(logList) <= 1:
        return
    global totalcount
    global g_member_idx
    global totalLine
    totalLine = totalLine + 1
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    if i == E_LOG_EVENT_LOGIN:
        #totalcount = totalcount + 1
        #print "here is a login %d"%(userid)
        add_login_logout(userid, 0)
    elif i == E_LOG_EVENT_LOGOUT:
        if userid == 0:
            print "here is the userid  0"
            print logList
        #print "here is a logout %d"%(userid)
        add_login_logout(userid, 1)
        
    
def print_result():
    global role_login
    print "here is the unbalanced "
    unbalanceCount = 0
    for userid in role_login.keys():
        r = role_login[userid]
        if r[0] <> r[1]:
            unbalanceCount = unbalanceCount + 1
            print "found unbalance %d %r"%(userid, r)
    print "total  unbalance count is %d"%(unbalanceCount)
    
print datetime.now()

parse_all('../../../Bin/Server/log', handle_get_login_logout)
print_result()
print datetime.now()

print "OK"