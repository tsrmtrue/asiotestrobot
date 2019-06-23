# -*- coding: utf8 -*-
from easySocket_server_reporter import *
import time
from datetime import datetime

g_clients_list = []

def create_clients(startid, count):
    global g_clients_list
    for i in range(startid, startid+count, 1):
        c = ServerReportClient("127.0.0.1", 9999, "%d区 大便天下"%(i))
        g_clients_list.append(c)
    
def run_all():
    global g_clients_list
    for c in g_clients_list:
        c.run()

def loop():
    while(1):
        run_all()
        time.sleep(1)

create_clients(1, 3)
loop()