# -*- coding: gbk -*-
import get_online_statistic
import sys
sys.path.append('../')
import server_cfg
print "OK"
def build_online_statistic_html():
    #global g_iap_statistic
    #print g_iap_statistic
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    html_template = """
<html>
<body>
<h4 style="color:#0000CD">在线人数统计</h4>
<table border="1">
%(online_statistic)s
</table>
</body>
</html>
"""
    online_statistic = ""
    #区总收入
    for zoneid in sorted(get_online_statistic.g_online_dict.keys()):
        online_statistic += """
        <th style="color:#00FF00">%(servername)s  </th>
<tr>
  <td style="color:#000080"> <b>时间 </b></td>
  <td style="color:#000080"> <b>人数 </b></td>
  
</tr>
"""%(locals())
        for online in reversed(get_online_statistic.g_online_dict[zoneid]):
            time = online[0]
            onlinecount = online[1]
            online_statistic += """
<tr>
  <td >  %(time)s</td>
  <td >  %(onlinecount)s</td>  
</tr>"""%(locals())    
    return html_template%(locals())
    
    
    
def build_html(baseLogDir, file_name):
    build_online_statistic_html.do_parse_online(baseLogDir)
    w = open(file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_iap_statistic_html())
    w.close()

#build_html("../../../report/iap_s.html")
