# -*- coding: gbk -*-
#from get_login_statistics import *
import sys
sys.path.append('../')
import server_cfg
import get_login_statistics
import get_iap_statistic

def build_register_login_statistic():
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    register_login_dict = {
                           #zoneid:{day:count,},
                           }
    register_count_dict = {
                           #zoneid:count,
                           }
    #global login_counts_dict
    for zoneid in sorted(get_login_statistics.login_counts_dict.keys()):
        for userid in sorted(get_login_statistics.login_counts_dict[zoneid].keys()):
            register_day = get_login_statistics.get_register_role_day(zoneid, userid)
            if register_day <> None:
                for loginday in sorted(get_login_statistics.login_counts_dict[zoneid][userid].keys()):
                    deltaday = get_login_statistics.get_daydelta(register_day, loginday)
                    if register_login_dict.get(zoneid, None) == None:
                        register_login_dict[zoneid] = {}
                    if register_login_dict[zoneid].get(deltaday, None) == None:
                        register_login_dict[zoneid][deltaday] = 1
                    else:
                        register_login_dict[zoneid][deltaday] = register_login_dict[zoneid][deltaday]+ 1
    
    #print "here is the register login statistic"
    #print register_login_dict
    register_login_statistic = ""
    register_login_template = """
    <th style="color:#00FF00">开始时间 %(firstday)s  </th>
    <th style="color:#00FF00">%(servername)s</th>
    <th style="color:#00FF00">总注册人数  %(total_register_count)s  </th>
<tr>
  
  <td></td>
  <td style="color:#000080"> <b>次日留存 </b></td>
  <td style="color:#000080"> <b>三日留存 </b></td>
  <td style="color:#000080"> <b>七日留存 </b></td>
</tr>


%(day_delta_statistic)s

    """
    day_delta_statistic = ""
    #global first_day
    firstday= get_login_statistics.first_day
    for zoneid in sorted(register_login_dict.keys()):
        total_register_count = get_login_statistics.get_register_role_count(zoneid)
        if total_register_count == 0:
            continue
        #day_delta_statistic = ""
        for dayDelta in sorted(register_login_dict[zoneid].keys()):
            if dayDelta > 0 and dayDelta < 10:
                count = register_login_dict[zoneid][dayDelta]
                leave_rate = count*100.0/total_register_count
                
                #day_delta_statistic += "<tr>  <td>    %(dayDelta)d </td>  <td> %(count)d</td> <td>%(leave_rate)r</td></tr>"%(locals())
        #register_login_statistic = register_login_template%(locals())
    #global login_count_dict_by_day
    for zoneid in sorted(get_login_statistics.login_count_dict_by_day.keys()):
        total_register_count = get_login_statistics.get_register_role_count(zoneid)
        for day in sorted(get_login_statistics.login_count_dict_by_day[zoneid].keys()):
            _l_0 = get_login_statistics.get_login_list_by_zone_day(zoneid, day)
            _r_m_1 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,1))
            _r_m_2 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,2))
            _r_m_3 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,3))
            _r_m_4 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,4))
            _r_m_5 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,5))
            _r_m_6 = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, get_login_statistics.get_before_day_by_delta(day,6))
            
            
            stayrate_1 = get_login_statistics.get_stay_rate(_r_m_1, _l_0)
            _b = list(set(_r_m_1).union(set(_r_m_2), set(_r_m_3)))
            stayrate_3 = get_login_statistics.get_stay_rate(_b, _l_0)
            _b = list(set(_b).union(set(_r_m_4), set(_r_m_5), set(_r_m_5)))
            stayrate_7 = get_login_statistics.get_stay_rate(_b, _l_0)
            day_delta_statistic += "<tr>  <td>%(day)s</td><td>    %(stayrate_1).2f%% </td>  <td> %(stayrate_3).2f%%</td> <td>%(stayrate_7).2f%%</td></tr>"%(locals())
        register_login_statistic = register_login_template%(locals())
            
    return register_login_statistic
    
    
    
def build_login_statistic():
    servername = server_cfg.servername.decode("utf8").encode("gbk")

    html_template = """
<html>

<body>

<h4 style="color:#0000CD">每日登录数</h4>
<table border="1">
%(zones)s
%(register_login_statistic)s
%(repeat_login_total_count)s
</table>
</body>
</html>
"""
    register_login_statistic = build_register_login_statistic()

    #global login_count_dict_by_day
    #print "XXXXXXXXXlogin_count_dict_by_day", get_login_statistics.login_count_dict_by_day
    zones = ""
    for zoneid in get_login_statistics.login_count_dict_by_day.keys():
        zone_template = """
<th style="color:#00FF00">%(servername)s</th>
<tr>
  <td > </td>
  <td style="color:#000080"> <b>今日登陆数</b></td>
  <td style="color:#000080"> <b>今日注册数 </b></td>
</tr>

%(days)s
"""     
    
        days = ""
        for day in sorted(get_login_statistics.login_count_dict_by_day[zoneid].keys()):
            day_template = """
<tr>
  <td style="color:#000080"> <b>%(day)s </b></td>
  <td style="color:#000080"> <b>%(todaylogin)d </b></td>
  <td style="color:#000080"> <b>%(todayregister)d </b></td>
</tr>
""" 
            """
<tr>
<td>角色id</td><td>登录次数</td><td>是否注册</td>
</tr>
    %(userids)s
"""
            #print "login_count_dict_by_day"
            #print get_login_statistics.login_count_dict_by_day
            #print "get_register_role_day"
            #print get_login_statistics.get_register_role_day
            _t_register_by_zoneid_day = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, day)
            todayregister = len(_t_register_by_zoneid_day)
            todaylogin = len(list(set(_t_register_by_zoneid_day + get_login_statistics.login_count_dict_by_day[zoneid][day].keys())))
            
            userids = ""
            for userid in get_login_statistics.login_count_dict_by_day[zoneid][day].keys():
                userid_template = """
<tr>
  <td>    %(userid)d</td>
  <td>     %(count)d</td>
  <td  style="color:#000080">     %(isregister)s</td>
  
</tr>    
"""
                isregister = ""
                count = get_login_statistics.login_count_dict_by_day[zoneid][day][userid]
                #if day == get_login_statistics.get_register_role_day(zoneid, userid):
                #    isregister = "是"
                #    todayregister = todayregister + 1
                userids += userid_template%(locals())
            days += day_template%(locals())
        zones = zone_template%(locals())
    repeat_login_total_count = build_login_statistic_repeat_login_total_count()
    return html_template%(locals())

def build_login_statistic_repeat_login_total_count():
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    repeat_login_template = """
    <th style="color:#00FF00">截止目前重复登录过的玩家数量</th>
%(repeat_login_statistic)s
    """
    repeat_login_statistic = ""
    #global first_day
    for zoneid in sorted(get_login_statistics.login_repeat_count_dict.keys()):
        repeat_login_template = """
<tr>
  <td></td>
  <td style="color:#000080"> <b>%(zoneid)r区</b></td>
  <td style="color:#000080"> <b>2次或以上</b></td>
  <td style="color:#000080"> <b>%(repeat_login_2_more)d</b></td>
</tr>

        """
        repeat_login_2_more = 0
        _d = get_login_statistics.login_repeat_count_dict[zoneid]
        for userid in _d.keys():
            if _d[userid] > 1:
                repeat_login_2_more = repeat_login_2_more + 1
        repeat_login_statistic += repeat_login_template%(locals())
            
    return repeat_login_statistic

def build_login_simple_statistic():
    servername = server_cfg.servername.decode("utf8").encode("gbk")

    html_template = """
<html>

<body>

<h4 style="color:#0000CD">每日登录数</h4>
<table border="1">
%(zones)s
</table>
</body>
</html>
"""

    #global login_count_dict_by_day
    #print "XXXXXXXXXlogin_count_dict_by_day", get_login_statistics.login_count_dict_by_day
    zones = ""
    for zoneid in get_login_statistics.login_count_dict_by_day.keys():
        zone_template = """
<th style="color:#00FF00">%(servername)s</th>
<tr>
  <td > </td>
  <td style="color:#000080"> <b>今日注册数 </b></td>
  <td style="color:#000080"> <b>付费次数 </b></td>
  <td style="color:#000080"> <b>付费人数 </b></td>  
  <td style="color:#000080"> <b>人民币估算 </b></td>
</tr>

%(days)s
"""     
    
        days = ""
        for day in sorted(get_login_statistics.login_count_dict_by_day[zoneid].keys()):
            day_template = """
<tr>
  <td style="color:#000080"> <b>%(day)s </b></td>
  <td style="color:#000080"> <b>%(todayregister)d </b></td>
  <td >  %(dailyPayCount)d</td>
  <td >  %(dailyPayRoleCount)d</td>
  <td >  %(rmb)d</td>  
</tr>
""" 
            todayregister = 0
            for userid in get_login_statistics.login_count_dict_by_day[zoneid][day].keys():
                isregister = ""
                count = get_login_statistics.login_count_dict_by_day[zoneid][day][userid]
                if day == get_login_statistics.get_register_role_day(zoneid, userid):
                    isregister = "是"
                    todayregister = todayregister + 1
            rmb = 0
            if None <> get_iap_statistic.g_iap_statistic.get(zoneid,None):
                if None <> get_iap_statistic.g_iap_statistic[zoneid].get(day, None):
                    rmb = get_iap_statistic.g_iap_statistic[zoneid][day][2]
            dailyPayCount = get_iap_statistic.get_iap_count_by_zoneid_day(zoneid, day)
            dailyPayRoleCount = get_iap_statistic.get_iap_role_count_by_zoneid_day(zoneid, day)
            days += day_template%(locals())
        zones = zone_template%(locals())
    return html_template%(locals())


def build_login_statistic_html(baseLogDir, file_name):
    get_iap_statistic.do_parse_iap(baseLogDir)
    get_login_statistics.do_parse_login(baseLogDir)
    w = open(file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_login_statistic())
    w.close()

#build_login_statistic_html("login_s.html")
