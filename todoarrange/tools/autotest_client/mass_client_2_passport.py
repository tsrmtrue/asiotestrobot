# -*- coding: utf8 -*-
from test_easySocket import *
import time
from datetime import datetime

g_clients_list = []
g_client_info = [
                 #["127.0.0.1", 9999, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ]


def create_client_info(c):
    global g_client_info
    for i in range(c):
        g_client_info.append(["192.168.1.32", 10001, "mac%d"%(i), "大€便€8%d"%(i), "p1000%d@qq.com"%(i), "000000"])

def create_clients():
    global g_clients_list
    global g_client_info
    
    for info in g_client_info:
        #print "create client ", time.time()
        #continue
        ip = info[0]
        port = info[1]
        mac = info[2]
        rolename = info[3]
        passport = info[4]
        pwd = info[5]
        c = XHWPassportClient(ip, port, passport, pwd)
        g_clients_list.append(c)
    
def run_all():
    global g_clients_list
    temp_list = []
    for c in g_clients_list:
        if c.run():
            #print "c.run"
            temp_list.append(c)
        else:
            print c.lastErrcode
            print c.ip,c.port
    g_clients_list = temp_list
    #print "run valid client ", len(temp_list)

def loop():
    while(1):
        run_all()
        time.sleep(1)
        
create_client_info(1)
print g_client_info
create_clients()
loop()