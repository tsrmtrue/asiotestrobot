# -*- coding: utf8 -*-
from parse_log import *
import sys
from datetime import *
sys.path.append('../')
from protocol_enums import *
import server_cfg
g_iap_statistic = {
                   #zoneid:{day:[count,gmcount, rmb, sandbox],},
                   }

g_iap_role_statistic = {
                        #zoneid:{day:[roleid, ],}
                        }

g_iap_role_count_monthly_statistic = {
                                      #zoneid:{month:{roleid:1,roleid2:1},}
                                      }

g_iap_monthly_rmb_statistic = {
                               #zoneid:{month:rmb,},
                               }

def add_monthly_rmb(zoneid, month, rmb):
    global g_iap_monthly_rmb_statistic
    if g_iap_monthly_rmb_statistic.get(zoneid, None) == None:
        g_iap_monthly_rmb_statistic[zoneid] = {month:rmb,}
    elif g_iap_monthly_rmb_statistic[zoneid].get(month, None) == None:
        g_iap_monthly_rmb_statistic[zoneid][month] = rmb
    else:
        g_iap_monthly_rmb_statistic[zoneid][month] += rmb

def add_iap_role_count_monthly(zoneid, month, roleid):
    global g_iap_role_count_monthly_statistic
    if g_iap_role_count_monthly_statistic.get(zoneid, None) == None:
        _m = {}
        _m[month] = {roleid:1,}
        g_iap_role_count_monthly_statistic[zoneid] = _m
    elif g_iap_role_count_monthly_statistic[zoneid].get(month, None) == None:
        g_iap_role_count_monthly_statistic[zoneid][month] = {roleid:1,}
    else :
        g_iap_role_count_monthly_statistic[zoneid][month][roleid] = 1#g_iap_role_count_monthly_statistic[zoneid][month] + count

def get_month_by_day(day):
    dateList1 = string.split(day, "-")
    return "%s-%s"%(dateList1[0], dateList1[1])

def build_month_statistic():
    #global g_iap_role_count_monthly_statistic
    global g_iap_role_statistic
    for zoneid in sorted(g_iap_role_statistic.keys()):
        for day in sorted(g_iap_role_statistic[zoneid].keys()):
            mon = get_month_by_day(day)
            count = len(g_iap_role_statistic[zoneid][day])
            for roleid in g_iap_role_statistic[zoneid][day]:
                add_iap_role_count_monthly(zoneid, mon, roleid)
    global g_iap_statistic 
    for zoneid in sorted(g_iap_statistic.keys()):
        for day in sorted(g_iap_statistic[zoneid].keys()):
            mon = get_month_by_day(day)
            rmb = g_iap_statistic[zoneid][day][2]
            add_monthly_rmb(zoneid, mon, rmb)

def add_iap_role_by_zone_day(zoneid, day, roleid):
    global g_iap_role_statistic
    if g_iap_role_statistic.get(zoneid, None) == None:
        _d = {}
        _d[day] = [roleid]
        g_iap_role_statistic[zoneid] = _d
    elif g_iap_role_statistic[zoneid].get(day, None) == None:
        g_iap_role_statistic[zoneid][day] = [roleid,]
    else :g_iap_role_statistic[zoneid][day].append(roleid)

def add_gm_iap_by_day(zoneid, day, count):
    global g_iap_statistic
    if g_iap_statistic.get(zoneid, None) == None:
        _d = {}
        _d[day] = [0, count, 0, 0]
        g_iap_statistic[zoneid] = _d
    elif g_iap_statistic[zoneid].get(day,None) == None:
        g_iap_statistic[zoneid][day] = [0,count,0, 0]
    else :
        g_iap_statistic[zoneid][day][1] = g_iap_statistic[zoneid][day][1] + count


def add_iap_by_day(zoneid, day, count):
    global g_iap_statistic
    if g_iap_statistic.get(zoneid, None) == None:
        _d = {}
        _d[day] = [count,0,0,0]
        g_iap_statistic[zoneid] = _d
    elif g_iap_statistic[zoneid].get(day,None) == None:
        g_iap_statistic[zoneid][day] = [count,0,0,0]
    else :
        g_iap_statistic[zoneid][day][0] = g_iap_statistic[zoneid][day][0] + count

def add_rmb_by_day(zoneid, day, count):
    global g_iap_statistic
    if g_iap_statistic.get(zoneid, None) == None:
        _d = {}
        _d[day] = [0,0,count,0]
        g_iap_statistic[zoneid] = _d
    elif g_iap_statistic[zoneid].get(day,None) == None:
        g_iap_statistic[zoneid][day] = [0,0,count,0]
    else :
        g_iap_statistic[zoneid][day][2] = g_iap_statistic[zoneid][day][2] + count

def add_sandbox_by_day(zoneid, day, sandbox):
    global g_iap_statistic
    if g_iap_statistic.get(zoneid, None) == None:
        _d = {}
        _d[day] = [0,0,0,sandbox]
        g_iap_statistic[zoneid] = _d
    elif g_iap_statistic[zoneid].get(day,None) == None:
        g_iap_statistic[zoneid][day] = [0,0,0,sandbox]
    else :
        g_iap_statistic[zoneid][day][3] = g_iap_statistic[zoneid][day][3] + sandbox


def get_iap_role_count_by_zoneid_day(zoneid, day):
    global g_iap_role_statistic
    if g_iap_role_statistic.get(zoneid, None) <> None:
        if g_iap_role_statistic[zoneid].get(day, None) <> None:
            #print "set is " , set(g_iap_role_statistic[zoneid][day])
            return len(set(g_iap_role_statistic[zoneid][day]))
    return 0
    
def get_iap_count_by_zoneid_day(zoneid, day):
    global g_iap_role_statistic
    if g_iap_role_statistic.get(zoneid, None) <> None:
        if g_iap_role_statistic[zoneid].get(day, None) <> None:
            #print g_iap_role_statistic[zoneid][day]
            return len(g_iap_role_statistic[zoneid][day])
    return 0

def get_iap_count_by_zoneid_month(zoneid, month):
    totalCount = 0
    global g_iap_role_statistic
    if g_iap_role_statistic.get(zoneid, None) <> None:
        for day in sorted(g_iap_role_statistic[zoneid].keys()):
            if month == get_month_by_day(day):
                totalCount += get_iap_role_count_by_zoneid_day(zoneid, day)
    return totalCount

def get_iap_role_count_by_zoneid_month(zoneid, month):
    global g_iap_role_count_monthly_statistic
    if g_iap_role_count_monthly_statistic.get(zoneid, None) <> None:
        if g_iap_role_count_monthly_statistic[zoneid].get(month, None) <> None:
            return len(g_iap_role_count_monthly_statistic[zoneid][month].keys())

def get_rmb_by_month(zoneid, month):
    global g_iap_monthly_rmb_statistic
    if g_iap_monthly_rmb_statistic.get(zoneid,None) <> None:
        if g_iap_monthly_rmb_statistic[zoneid].get(month, None) <> None:
            return g_iap_monthly_rmb_statistic[zoneid][month]
    return 0.0
        
def handle_get_iap_count(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    datestr = logList[g_member_idx.index("date")]
    log2 = logList[g_member_idx.index("log2")]
    iapid = logList[g_member_idx.index("log1")]
    day = string.split(datestr, " ")[0]
    diamondcount = int(logList[g_member_idx.index("p4")])
    if i in [E_LOG_EVENT_IAP_SUCCESS, ]:
        #totalcount = totalcount + 1
        if diamondcount == 0:
            print "the diamond count is 0!!!!!!!!!!!!!!1"
            return 
        if log2 == "'gm add'":
            add_gm_iap_by_day(zoneid, day, diamondcount)
        else:
            rmb = 0
            #print server_cfg.iap_rmb_dict
            for iid in server_cfg.iap_rmb_dict.keys():
                if iid.find("%d"%diamondcount) > -1:
                    rmb = server_cfg.iap_rmb_dict[iid]
            if rmb == 0:
                print "unknown iapid :", iapid
            #print "get iap rmb ", rmb
            if log2 == "'sandbox'":
                add_sandbox_by_day(zoneid, day, rmb)
            else:
                add_rmb_by_day(zoneid, day, rmb)
                add_iap_by_day(zoneid, day, diamondcount)
                add_iap_role_by_zone_day(zoneid,day,userid)
        #print "here is a iap ", logList
    
def print_result():
    pass
    """global login_counts_dict
    for i in  sorted(login_counts_dict.keys()):
        print "%r: %r"%(i, login_counts_dict[i])
    global login_count_dict_by_day
    for i in  sorted(login_count_dict_by_day.keys()):
        print "%r: %r"%(i, login_count_dict_by_day[i])"""
    
def do_parse_iap(baseLogDir):
    print datetime.now()
    global g_iap_statistic
    del g_iap_statistic
    g_iap_statistic = {}
    global g_iap_role_statistic
    del g_iap_role_statistic
    g_iap_role_statistic = {}
    global g_iap_role_count_monthly_statistic
    del g_iap_role_count_monthly_statistic
    g_iap_role_count_monthly_statistic = {}
    global g_iap_monthly_rmb_statistic
    del g_iap_monthly_rmb_statistic
    g_iap_monthly_rmb_statistic = {}
    parse_all(baseLogDir, handle_get_iap_count)
    build_month_statistic()
    
    print datetime.now()
    
    print "OK"
