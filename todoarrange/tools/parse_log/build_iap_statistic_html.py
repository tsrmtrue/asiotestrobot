# -*- coding: gbk -*-
#from get_iap_statistic import *
#from get_login_statistics import *
import get_iap_statistic
import get_login_statistics
import sys
sys.path.append('../')
import server_cfg

def add_mean_statistic(_d, zoneid, month, v):
    if _d.get(zoneid, None) == None:
        _d[zoneid] = {month:[v,1],}
    elif _d[zoneid].get(month, None) == None:
        _d[zoneid][month] = [v,1]
    else:
        _d[zoneid][month][0] += v
        _d[zoneid][month][1] += 1

def get_mean_statistic(_d, zoneid, month):
    if _d.get(zoneid, None) <> None:
        if _d[zoneid].get(month, None) <> None:
            if _d[zoneid][month][1] <> 0:
                return _d[zoneid][month][0]*1.0/ _d[zoneid][month][1]
    return 0

def build_iap_statistic_html():
    #global g_iap_statistic
    #print g_iap_statistic

    _d_mean_loginarpu = {}
    _d_mean_registerarpu = {}
    _d_mean_dailyarpu = {}
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    html_template = """
<html>
<body>
<h4 style="color:#0000CD">����ͳ��</h4>
<table border="1">
%(iap_statistic)s
</table>
</body>
</html>
"""
    iap_statistic = ""
    #��������
    for zoneid in sorted(get_iap_statistic.g_iap_statistic.keys()):
        iap_statistic += """
        <th style="color:#00FF00">%(servername)s  </th>
<tr>
  <td style="color:#000080">  </td>
  <td style="color:#000080"> <b>����ҹ��� </b></td>
  <td style="color:#000080"> <b>ɳ������ҹ��� </b></td>
  <td style="color:#000080"> <b>������ʯ </b></td>
  <td style="color:#000080"> <b>gm������ʯ </b></td>
  <td style="color:#000080"> <b>���Ѵ��� </b></td>
  <td style="color:#000080"> <b>�������� </b></td>  
  <td style="color:#000080"> <b>��½���� </b></td>
  <td style="color:#000080"> <b>ע������ </b></td>
  <td style="color:#000080"> <b>������͸�� </b></td>
  <td style="color:#000080"> <b>��½arpu </b></td>
  <td style="color:#000080"> <b>ע��arpu </b></td>
  <td style="color:#000080"> <b>�ո���arpu </b></td>
  
</tr>
"""%(locals())
        for day in sorted(get_iap_statistic.g_iap_statistic[zoneid].keys()):
            sandbox = get_iap_statistic.g_iap_statistic[zoneid][day][3]
            rmb = get_iap_statistic.g_iap_statistic[zoneid][day][2]
            iapcount = get_iap_statistic.g_iap_statistic[zoneid][day][0]
            gmiapcount = get_iap_statistic.g_iap_statistic[zoneid][day][1]
            dailyPayCount = get_iap_statistic.get_iap_count_by_zoneid_day(zoneid, day)
            dailyPayRoleCount = get_iap_statistic.get_iap_role_count_by_zoneid_day(zoneid, day)
            
            _t_register_by_zoneid_day = get_login_statistics.get_register_rolelist_by_zoneid_day(zoneid, day)
            dailyRegister = len(_t_register_by_zoneid_day)
            dailyLogin = len(list(set(_t_register_by_zoneid_day + get_login_statistics.login_count_dict_by_day[zoneid][day].keys())))
                        
            fufeishentoulv = 0
            if dailyLogin <> 0:
                fufeishentoulv = dailyPayRoleCount*100.0/dailyLogin
                
            loginarpu = 0
            if dailyLogin<> 0:
                loginarpu = rmb*1.0 / dailyLogin
                
            registerarpu = 0
            if dailyRegister <> 0: 
                registerarpu = rmb*1.0 / dailyRegister
                
            dailyarpu = 0
            if dailyPayRoleCount <> 0: 
                dailyarpu = rmb*1.0 / dailyPayRoleCount
            
            month = get_iap_statistic.get_month_by_day(day)
            
            add_mean_statistic(_d_mean_loginarpu, zoneid, month, loginarpu)
            add_mean_statistic(_d_mean_registerarpu, zoneid, month, registerarpu)
            add_mean_statistic(_d_mean_dailyarpu, zoneid, month, dailyarpu)
            iap_statistic += """
<tr>
  <td >  %(day)s</td>
  <td >  %(rmb)d</td>
  <td >  %(sandbox)d</td>
  <td >  %(iapcount)d</td>
  <td >  %(gmiapcount)d</td>
  <td >  %(dailyPayCount)d</td>
  <td >  %(dailyPayRoleCount)d</td>
  <td >  %(dailyLogin)d</td>
  <td >  %(dailyRegister)d</td>
  <td >  %(fufeishentoulv).2f%%</td>
  <td >  %(loginarpu).2f</td>
  <td >  %(registerarpu).2f</td>
  <td >  %(dailyarpu).2f</td>
  
</tr>"""%(locals())
        
            
    #��������ͳ��,��
    #global g_iap_role_count_monthly_statistic
    for zoneid in sorted(get_iap_statistic.g_iap_role_count_monthly_statistic.keys()):
        iap_statistic += """
        <th style="color:#00FF00">%(servername)s </th>
<tr>
  <td style="color:#000080">  </td>
  <td style="color:#000080"> <b>�¸������� </b></td>
  <td style="color:#000080"> <b>�¸���arpu </b></td>
  <td style="color:#000080"> <b>�¸�����͸�� </b></td>
  <td style="color:#000080"> <b>�վ���½arpu </b></td>
  <td style="color:#000080"> <b>�վ�ע��arpu </b></td>
  <td style="color:#000080"> <b>�վ��ո���arpu </b></td>
  
</tr>
"""%(locals())

        for month in sorted(get_iap_statistic.g_iap_role_count_monthly_statistic[zoneid].keys()):
            monthly_pay_role_count = len(get_iap_statistic.g_iap_role_count_monthly_statistic[zoneid][month].keys())
            monthly_pay_arpu = 0
            if monthly_pay_role_count<>0:
                monthly_pay_arpu=1.0*get_iap_statistic.get_rmb_by_month(zoneid, month)/monthly_pay_role_count
            monthly_login = get_login_statistics.get_login_count_by_zone_month(zoneid, month)
            monthly_pay_shentoulv = 0
            if monthly_login <> 0:
                monthly_pay_shentoulv = monthly_pay_role_count*100.0/monthly_login
            
            mean_loginarpu = get_mean_statistic(_d_mean_loginarpu, zoneid, month)
            mean_registerarpu = get_mean_statistic(_d_mean_registerarpu, zoneid, month)
            mean_dailyarpu = get_mean_statistic(_d_mean_dailyarpu, zoneid, month)
            iap_statistic += """
<tr>
  <td >  %(month)s</td>
  <td >  %(monthly_pay_role_count)d</td>
  <td >  %(monthly_pay_arpu).2f</td>
  <td >  %(monthly_pay_shentoulv).2f%%</td>
  <td >  %(mean_loginarpu).2f</td>
  <td >  %(mean_registerarpu).2f</td>
  <td >  %(mean_dailyarpu).2f</td>
</tr>"""%(locals())
    return html_template%(locals())
    
def build_iap_statistic_simple_html():
    #global g_iap_statistic
    #print g_iap_statistic

    _d_mean_loginarpu = {}
    _d_mean_registerarpu = {}
    _d_mean_dailyarpu = {}
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    html_template = """
<html>
<body>
<h4 style="color:#0000CD">����ͳ��</h4>
<table border="1">
%(iap_statistic)s
</table>
</body>
</html>
"""
    iap_statistic = ""
    #��������
    for zoneid in sorted(get_iap_statistic.g_iap_statistic.keys()):
        iap_statistic += """
        <th style="color:#00FF00">%(servername)s  </th>
<tr>
  <td style="color:#000080">  </td>
  <td style="color:#000080"> <b>ע������ </b></td>  
  <td style="color:#000080"> <b>���Ѵ��� </b></td>
  <td style="color:#000080"> <b>�������� </b></td>  
  <td style="color:#000080"> <b>����ҹ��� </b></td>
</tr>
"""%(locals())
        for day in sorted(get_iap_statistic.g_iap_statistic[zoneid].keys()):
            rmb = get_iap_statistic.g_iap_statistic[zoneid][day][2]
            dailyPayCount = get_iap_statistic.get_iap_count_by_zoneid_day(zoneid, day)
            dailyPayRoleCount = get_iap_statistic.get_iap_role_count_by_zoneid_day(zoneid, day)
            dailyLogin = get_login_statistics.get_login_count_by_zone_day(zoneid, day)
            dailyRegister = get_login_statistics.get_register_count_by_zone_day(zoneid, day)
            iap_statistic += """
<tr>
  <td >  %(day)s</td>
  <td >  %(dailyRegister)d</td>
  <td >  %(dailyPayCount)d</td>
  <td >  %(dailyPayRoleCount)d</td>
  <td >  %(rmb)d</td>  
</tr>"""%(locals())
        
    return html_template%(locals())
    
    
    
def build_html(baseLogDir, file_name):
    get_login_statistics.do_parse_login(baseLogDir)
    get_iap_statistic.do_parse_iap(baseLogDir)
    w = open(file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_iap_statistic_html())
    w.close()

