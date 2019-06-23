# -*- coding: gbk -*-
import get_level_statistic
import sys
sys.path.append('../')
import server_cfg
import global_path
print "OK"
def build_level_statistic_html():
    #global g_iap_statistic
    #print g_iap_statistic
    servername = server_cfg.servername.decode("utf8").encode("gbk")
    html_template = """
<html>
<body>
<h4 style="color:#0000CD">等级统计 %(servername)s</h4>
<table border="1">
%(level_statistic)s
</table>
</body>
</html>
"""
    level_statistic = ""
    #区总收入
    for day in sorted(get_level_statistic.g_level_dict.keys()):
        level_statistic += """
        <th style="color:#00FF00">%(day)s  </th>
<tr>
  <td style="color:#000080"> <b>等级  </b></td>
  <td style="color:#000080"> <b>人数 </b></td>
  
</tr>
"""%(locals())
        for level in get_level_statistic.g_level_dict[day].keys():
            count = len(get_level_statistic.g_level_dict[day][level])
            level_statistic += """
<tr>
  <td >  %(level)s</td>
  <td >  %(count)s</td>  
</tr>"""%(locals())    
    return html_template%(locals())
    
    
    
def build_html(html_file_name):
    get_level_statistic.parse_files(global_path.log_from_db_path)
    w = open(html_file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_level_statistic_html())
    w.close()

build_html("t.html")
