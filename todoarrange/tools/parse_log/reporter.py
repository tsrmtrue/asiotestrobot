# -*- coding: gbk -*-
import sys
sys.path.append('../')
sys.path.append('../server_status')
import time
import string
import global_path
import server_cfg
import os

os.chdir(global_path.real_path)
os.system(global_path.real_path+"init_svn.bat")
os.chdir(global_path.parse_log_path)
servername = server_cfg.servername#get_server_config.get_server_name_by_cfg(global_path.serverid_file, global_path.cfg_path+"fuwuqipeizhi_utf8.csv")
print servername
servername = servername.decode("utf8").encode("gbk")
while (1):
    #import build_login_statistic_html
    #import build_iap_statistic_html
    import build_all
    #build_login_statistic_html.build_login_statistic_html(global_path.log_path, global_path.report_path+"%(servername)s_login_s.html"%(locals()))
    #build_iap_statistic_html.build_html(global_path.log_path, global_path.report_path+"%(servername)s_iap_s.html"%(locals()))
    build_all.build_all_html(global_path.log_path, global_path.report_path+"%(servername)s_s.html"%(locals()))
    build_all.build_simple_html(global_path.log_path, global_path.report_path+"%(servername)s_统计_s.html"%(locals()))
    os.chdir(global_path.real_path)
    os.system(global_path.real_path+"auto_commit.bat")
    os.chdir(global_path.parse_log_path)
    time.sleep(500)
    
    
