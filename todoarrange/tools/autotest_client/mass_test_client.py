# -*- coding: utf8 -*-
import mass_server_listener
import time
from datetime import datetime

import mass_peer_PNL
g_clients_list = []
g_client_info = [
                 #["127.0.0.1", 9999, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ]


def create_client_info(c):
    global g_client_info
    for i in range(c):
        g_client_info.append(["192.168.126.128", 25341])

def create_all_clients():
    global g_clients_list
    global g_client_info
    
    for info in g_client_info:
        #print "create client ", time.time()
        #continue
        ip = info[0]
        port = info[1]
        c = mass_peer_PNL.RepeatSendClient(ip, port)
        g_clients_list.append(c)

def close_all_client():
    global g_clients_list
    for c in g_clients_list:
        c.close()
        print "close on control c"

    
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
    try:
        while(1):
            run_all()
            time.sleep(0.1)
    except KeyboardInterrupt :
        close_all_client()
        
create_client_info(1)
#print g_client_info
create_all_clients()
loop()