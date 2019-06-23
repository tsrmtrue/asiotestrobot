# -*- coding: gbk -*-
from parse_log import *
from datetime import *
import sys
sys.path.append('../')
from protocol_enums import *

login_counts_dict = {
                    #zoneid:{userid:{"day":count,},},
                    }

login_count_dict_by_day = {
                    #zoneid:{"day":{userid:count,},},
                           }
login_count_dict_by_month = {
                    #zoneid:{"month":{userid:count,},},
                           }

register_role_day_dict = {
                         #zoneid:{userid:"day",}, 
                          }

register_day_role_dict = {
                         #zoneid:{day:[userid,], }, 
                          }

login_repeat_count_dict = {
                           #zoneid:{userid:count,},
                           }


first_day = ""

def get_login_list_by_zone_day(zoneid, day):
    global login_count_dict_by_day
    if login_count_dict_by_day.get(zoneid, None) != None:
        if login_count_dict_by_day[zoneid].get(day, None) != None:
            return sorted(login_count_dict_by_day[zoneid][day].keys())
    return []


def add_register_day_role(zoneid, day, userid):
    global register_day_role_dict
    if register_day_role_dict.get(zoneid, None) == None:
        _u = [userid, ]
        _d = {}
        _d[day] = _u
        register_day_role_dict[zoneid] = _d
    elif register_day_role_dict[zoneid].get(day, None) == None:
        register_day_role_dict[zoneid][day] = [userid, ]
    else:
        register_day_role_dict[zoneid][day].append(userid)

def get_before_day_by_delta(baseday, beforedays):
    dateList1 = string.split(baseday, "-")
    date1 = date(int(dateList1[0]), int(dateList1[1]), int(dateList1[2]))
    td = timedelta(beforedays)
    return "%s"%(date1 - td)
    
def get_register_rolelist_by_zoneid_day(zoneid, day):
    global register_day_role_dict
    if register_day_role_dict.get(zoneid, None) != None:
        if register_day_role_dict[zoneid].get(day, None) != None:
            return register_day_role_dict[zoneid][day]
    return []

def get_daydelta(d1, d2):
    dateList1 = string.split(d1, "-")
    dateList2 = string.split(d2, "-")
    date1 = date(int(dateList1[0]), int(dateList1[1]), int(dateList1[2]))
    date2 = date(int(dateList2[0]), int(dateList2[1]), int(dateList2[2]))
    datedelta1 = date2 - date1
    return datedelta1.days

def get_stay_rate(baselist, targetlist):
    #print "get_stay_rate "
    #print baselist
    #print targetlist
    stay = 0
    if len(baselist) == 0:
        return 0
    if len(targetlist) == 0:
        return 0
    for userid in baselist:
        if userid in targetlist:
            stay = stay + 1
    #print stay*1.0/len(baselist)*100

    return stay*1.0/len(baselist)*100


def add_login_count_by_day(zoneid, userid, day):
    #print "add_login_count_by_day ", zoneid, userid, day
    global login_count_dict_by_day
    if login_count_dict_by_day.get(zoneid, None) == None:
        _u = dict()
        _u[userid] = 1
        _z = dict()
        _z[day] = _u
        login_count_dict_by_day[zoneid] = _z
    else:
        if login_count_dict_by_day[zoneid].get(day, None) == None:
            _u = dict()
            _u[userid] = 1
            login_count_dict_by_day[zoneid][day] = _u
        else:
            if login_count_dict_by_day[zoneid][day].get(userid, None) == None:
                login_count_dict_by_day[zoneid][day][userid] = 1
            else:
                login_count_dict_by_day[zoneid][day][userid] = login_count_dict_by_day[zoneid][day][userid] + 1

def add_login_count_by_month(zoneid, userid, month):
    global login_count_dict_by_month
    if login_count_dict_by_month.get(zoneid, None) == None:
        login_count_dict_by_month[zoneid] = {month:{userid:1,},}
    elif login_count_dict_by_month[zoneid].get(month, None) == None:
        login_count_dict_by_month[zoneid][month] = {userid:1,}
    elif login_count_dict_by_month[zoneid][month].get(userid, None) == None:
        login_count_dict_by_month[zoneid][month][userid] = 1
    else:
        login_count_dict_by_month[zoneid][month][userid] += 1

def add_login_count(zoneid, userid, day):
    global first_day
    if first_day =="":
        first_day = day
    global login_counts_dict
    if login_counts_dict.get(zoneid, None) == None:
        _u = dict()
        _u[day] = 1
        _z = dict()
        _z[userid] = _u
        login_counts_dict[zoneid] = _z
    else:
        if login_counts_dict[zoneid].get(userid, None) == None:
            _u = dict()
            _u[day] = 1
            login_counts_dict[zoneid][userid] = _u
        else:
            if login_counts_dict[zoneid][userid].get(day, None) == None:
                login_counts_dict[zoneid][userid][day] = 1
            else:
                login_counts_dict[zoneid][userid][day] = login_counts_dict[zoneid][userid][day] + 1

def add_register_role_day(zoneid, userid, day):
    #print "here is  register ",zoneid, userid, day
    global register_role_day_dict
    if register_role_day_dict.get(zoneid, None) == None:
        _z = dict()
        _z[userid] = day
        register_role_day_dict[zoneid] = _z
    else:
        if register_role_day_dict[zoneid].get(userid, None) == None:
            register_role_day_dict[zoneid][userid] = day
        
def get_register_role_day(zoneid, userid):
    global register_role_day_dict
    if register_role_day_dict.get(zoneid, None) <> None:
        return register_role_day_dict[zoneid].get(userid,None)
    return None

def get_register_role_count(zoneid):
    global register_role_day_dict
    if register_role_day_dict.get(zoneid, None) <> None:
        return len(register_role_day_dict[zoneid].keys())
    return 0

def get_login_count_by_zone_day(zoneid, day):
    return len(get_login_list_by_zone_day(zoneid, day))

def get_login_count_by_zone_month(zoneid, month):
    global login_count_dict_by_month
    if login_count_dict_by_month.get(zoneid, None) <> None:
        if login_count_dict_by_month[zoneid].get(month, None) <> None:
            return len(login_count_dict_by_month[zoneid][month].keys())
    return 0

def get_register_count_by_zone_day(zoneid, day):
    return len(get_register_rolelist_by_zoneid_day(zoneid, day))

def get_register_count_by_zone_month(zoneid, month):
    totalCount = 0
    global register_day_role_dict
    for zoneid in register_day_role_dict.keys():
        for day in register_day_role_dict[zoneid]:
            if month == get_month_by_day(day):
                totalCount += get_register_count_by_zone_day(zoneid, day)
    return totalCount


def get_month_by_day(day):
    dateList1 = string.split(day, "-")
    return "%s-%s"%(dateList1[0], dateList1[1])

def add_repeat_login_count(zoneid, userid):  
    """ 
    login_repeat_count_dict = {
                           #zoneid:{userid:count,},
                           }
                           """
    global login_repeat_count_dict
    if login_repeat_count_dict.get(zoneid, None) == None:
        login_repeat_count_dict[zoneid] = {userid:1}
    else:
        _user_2_count_dict = login_repeat_count_dict[zoneid]
        if _user_2_count_dict.get(userid, None) == None:
            login_repeat_count_dict[zoneid][userid] = 1
        else:
            login_repeat_count_dict[zoneid][userid] = login_repeat_count_dict[zoneid][userid] + 1


def handle_get_login_count(logList, zoneid):
    if len(logList) <= 1:
        return
    global g_member_idx
    #print logList
    i = int(logList[g_member_idx.index("eventid")])
    userid = int(logList[g_member_idx.index("userid")])
    datestr = logList[g_member_idx.index("date")]
    day = string.split(datestr, " ")[0]
    if i in [E_LOG_EVENT_LOGIN, ]:
        #totalcount = totalcount + 1
        #print "here is a login %d"%(userid)
        add_login_count(zoneid, userid, day)
        add_login_count_by_day(zoneid, userid, day)
        add_login_count_by_month(zoneid, userid, get_month_by_day(day))
        add_repeat_login_count(zoneid, userid)
        
    if i == E_LOG_EVENT_RIGISTER_ROLE:
        add_register_role_day(zoneid, userid, day)
        add_register_day_role(zoneid, day, userid)
        
        #print "here is register", logList
    
def print_result():
    print "login_count_dict_by_day", login_count_dict_by_day
    """global login_counts_dict
    for i in  sorted(login_counts_dict.keys()):
        print "%r: %r"%(i, login_counts_dict[i])
    global login_count_dict_by_day
    for i in  sorted(login_count_dict_by_day.keys()):
        print "%r: %r"%(i, login_count_dict_by_day[i])
    """
    
def do_parse_login(logBaseDir):
    global login_counts_dict
    login_counts_dict = {}
    global login_count_dict_by_day
    login_count_dict_by_day = {}
    global register_role_day_dict
    register_role_day_dict = {}
    global register_day_role_dict
    register_day_role_dict = {}
    global login_repeat_count_dict
    login_repeat_count_dict = {}

    print datetime.now()
    parse_all(logBaseDir, handle_get_login_count)
    #print_result()
    print datetime.now()
    print "OK"