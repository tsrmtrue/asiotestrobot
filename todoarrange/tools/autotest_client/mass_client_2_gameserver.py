# -*- coding: utf8 -*-
from test_easySocket import *
import time
from datetime import datetime

g_clients_list = []
g_client_info = [
                 #["192.168.1.32", 9090, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ]


def create_client_info(c):
    global g_client_info
    for i in range(c):
        g_client_info.append(["192.168.1.32", 8004, "mm%05d"%(i), "大€便€8%d"%(i), "passport100%d"%(i), "pwd1"])

def create_clients():
    global g_clients_list
    global g_client_info
    count = 0
    for info in g_client_info:
        ip = info[0]
        port = info[1]
        mac = info[2]
        rolename = info[3]
        passport = info[4]
        pwd = info[5]
        c = XHWClient(ip, port, mac, rolename)
        c.initPassport(passport, pwd)
        g_clients_list.append(c)
        count = count+1
        if count %100 == 0:
            time.sleep(1)
    
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

def loop():
    while(1):
        run_all()
        time.sleep(0.01)
        
create_client_info(1000)
print g_client_info
create_clients()
loop()