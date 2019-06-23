# -*- coding: utf8 -*-
from test_easySocket import *
import time
from datetime import datetime

g_clients_list = []
g_client_info = [
                 #["192.168.1.32", 9090, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ["192.168.1.114", 9091, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 #["192.168.1.114", 9092, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ]

class TerminateClient(XHWClient):
    sendTerminate = False
    def doTerminate(self):
        gmreq = test_namedlist.SGmcmdReq()
        gmreq.cmd = "terminateserver"
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_GmCmd_Req, gmreq)[0])
        print "send reporter server gmcmd "

    def onActiveTimer(self):
        print " on active timer"
        if self.loginSuccess <> True:
            return
        if self.sendTerminate == False:
            self.sendTerminate = True
            self.doTerminate()

def create_clients():
    global g_clients_list
    global g_client_info
    
    for info in g_client_info:
        ip = info[0]
        port = info[1]
        mac = info[2]
        rolename = info[3]
        passport = info[4]
        pwd = info[5]
        c = TerminateClient(ip, port, mac, rolename)
        c.initPassport(passport, pwd)
        g_clients_list.append(c)
    
def run_all():
    global g_clients_list
    temp_list = []
    for c in g_clients_list:
        if c.run():
            #print "c.run, ", len(g_clients_list)
            temp_list.append(c)
        else:
            print c.lastErrcode
            print c.ip,c.port
    g_clients_list = temp_list

def loop():
    while(1):
        run_all()
        time.sleep(1)

create_clients()
loop()