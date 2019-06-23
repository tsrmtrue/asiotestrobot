# -*- coding: gbk -*-
import sys
sys.path.append('../')
import global_path

import build_iap_statistic_html
import build_login_statistic_html
import build_online_statistic_html
import build_level_statistic_html

import get_iap_statistic
import get_login_statistics
import get_online_statistic
import get_level_statistic

def build_all_html(baseLogDir, file_name):
    get_login_statistics.do_parse_login(baseLogDir)
    get_iap_statistic.do_parse_iap(baseLogDir)
    get_online_statistic.do_parse_online(baseLogDir)
    get_level_statistic.parse_files(global_path.log_from_db_path)

    w = open(file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_iap_statistic_html.build_iap_statistic_html())
    w.write(build_login_statistic_html.build_login_statistic())
    w.write(build_online_statistic_html.build_online_statistic_html())
    w.write(build_level_statistic_html.build_level_statistic_html())
    w.close()

def build_simple_html(baseLogDir, file_name):
    get_login_statistics.do_parse_login(baseLogDir)
    get_iap_statistic.do_parse_iap(baseLogDir)
    get_online_statistic.do_parse_online(baseLogDir)
    get_level_statistic.parse_files(global_path.log_from_db_path)

    w = open(file_name, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    #w.write(build_iap_statistic_html.build_iap_statistic_simple_html())
    w.write(build_login_statistic_html.build_login_simple_statistic())
    w.write(build_online_statistic_html.build_online_statistic_html())
    w.close()
    
    
    
    