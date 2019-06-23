# -*- coding: utf8 -*-
from easySocket_server_reporter import *
import time
from datetime import datetime

g_clients_list = []
g_server_list = [
                 ["127.0.0.1", 9090],
                 #["sz1.yiyuanol.net", 9090],
                 #["sz1.yiyuanol.net", 9091],
                 ]

import smtplib   

def send_email(ip, port):
    smtp = smtplib.SMTP()   
    smtpServer = "smtp.163.com"#"gmail-smtp-in.l.google.com"
    smtpPort = "25"#"465"
    emailAccount = "tsrmtrue@163.com"#'tsrmtrue@gmail.com'
    emailPwd= "nukecusn12!@"
    smtp.connect(smtpServer, smtpPort)   
    smtp.login(emailAccount, emailPwd)   
    toEmailAccount = '150237442@qq.com'
    email = """From: %(emailAccount)s
To: %(toEmailAccount)s
Subject: this is a email from python demo%(ip)s:%(port)d

Server Down!
"""
    smtp.sendmail(emailAccount, toEmailAccount, email%(locals()))   
    smtp.quit()  


def create_clients():
    global g_clients_list
    global g_server_list
    for server in g_server_list:
        c = GMClient(server[0], server[1], "10001", "10001")
        g_clients_list.append(c)
    
def run_all():
    global g_clients_list
    temp_list = []
    for c in g_clients_list:
        if c.run():
            temp_list.append(c)
        else:
            print c.lastErrcode
            print c.ip,c.port
            send_email(c.ip,c.port)
    g_clients_list = temp_list
            

def loop():
    while(1):
        run_all()
        time.sleep(1)
#init_all_server_cfg("../../../Bin/Server/cfg/fuwuqipeizhi_utf8.csv")
create_clients()
loop()