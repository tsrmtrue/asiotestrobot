# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
from easySocket import *
from test_namedlist_passport import *
from test_namedlist_coding_passport import *
from protocol_enums_passport import *
import random
from datetime import *

import time

import test_easySocket


class PassportClient(test_easySocket.XHWClient):
    send_gm_check_time = None
    passport = ""
    pwd = ""
    mac = ""
    email = ""
    sessionId = ""
    tryLogin = False
    tryRegister = True
    tryGetServerList = False
    def __init__(self, ip, port, passport, pwd, mac, email, sessionId):
        test_easySocket.XHWClient.__init__(self, ip, port, "", "")
        self.passport = passport
        self.pwd = pwd
        self.mac = mac
        self.email = email
        self.sessionId = sessionId
        self.state = 0

    def onEvent(self, msgid, st):
        print "on event id : ", msgid
        #test_easySocket.XHWClient.onEvent(self, msgid, st)
        if msgid == PS_2_C_ServerList_Ntf:
            print "here comes the serverlist ,count is :",st.count
        return True
    
    def doRegister(self):
        registerReq = SRegisterPassportReq()
        registerReq.registerPassport.email = self.email
        registerReq.registerPassport.passport.passport = self.passport
        registerReq.registerPassport.passport.password = self.pwd        
        registerReq.macAddress.macAddress = self.mac
        self.add2send(getSendbuf(C_2_PS_Register_Passport_Req, registerReq)[0])
        print "send register by passport "
        
    def doGetServerList(self):
        req = SGetServerListReq()
        s, l = getSendbuf(C_2_PS_Get_ServerList_Req, req)
        self.add2send(s)
        print "send get server list  ", s, " len is ", l
        
            
    def doLoginPassport(self):
        loginreq = SLoginByPassportReq()
        loginreq.passport.passport = self.passport
        loginreq.passport.password = self.pwd
        loginreq.macAddress.macAddress = self.mac
        self.add2send(getSendbuf(C_2_PS_Login_By_Passport_Req, loginreq)[0])
        print "send login by passport "
        
    def onActiveTimer(self):
        #print "active timer"
        if self.tryLogin == True:
            self.tryLogin = False
            self.doLoginPassport()
            
        if self.tryRegister == True:
            self.tryRegister = False
            self.doRegister()    

        if self.tryGetServerList == 0:
            self.tryGetServerList = 1
            self.doGetServerList()    
            
        #test_easySocket.XHWClient.onActiveTimer(self)
        if self.send_gm_check_time == None:
            self.send_gm_check_time = datetime.now()
        elif (datetime.now() - self.send_gm_check_time).total_seconds() > 10 :
            self.send_gm_check_time = datetime.now()
            print "this is timer "
                   
g_clients_list = []
g_server_list = [#ip, port, passport, pwd, mac, email, sessionId
                 ["127.0.0.1", 10044, "passport90", "pwd1", "mac1", "email1", "sessionid1"],
                 #["sz1.yiyuanol.net", 9090],
                 #["sz1.yiyuanol.net", 9091],
                 ]

def create_clients():
    global g_clients_list
    global g_server_list
    for server in g_server_list:
        c = PassportClient(server[0], server[1], server[2], server[3], server[4], server[5], server[6])
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
            
def loop():
    while(1):
        run_all()
        time.sleep(1)
#init_all_server_cfg("../../../Bin/Server/cfg/fuwuqipeizhi_utf8.csv")
create_clients()
loop()