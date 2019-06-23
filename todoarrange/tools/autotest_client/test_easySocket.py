# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
from easySocket import *

"""from test_namedlist import *
from test_namedlist_coding import *
from protocol_enums import *
from test_namedlist_passport import *
from test_namedlist_coding_passport import *
from protocol_enums_passport import *
"""
import test_namedlist
import test_namedlist_coding
import protocol_enums
import test_namedlist_passport
import test_namedlist_coding_passport
import protocol_enums_passport
import random


import random
from datetime import *

class XHWClient(easySocket):
    state = -1
    send_move_time = None
    ip = ""
    port = 0
    passport = ""
    password = ""
    email = ""
    mac = ""
    tryBind = False
    tryCreateAndBind = False
    loginSuccess = False
    def __init__(self, ip, port, account, new_rolename):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
        self.account = account
        self.new_rolename = new_rolename
        self.ip = ip
        self.port = port
    
    def initPassport(self, passport, pwd):
        self.passport = passport
        self.password = pwd
        self.mac = self.account
        
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        if msgid == protocol_enums.S_2_C_Protocol_Version_Ntf:
            print "the protocol ntf ", self.client
            #check state
            loginReq = test_namedlist.SEasyLoginReq()
            loginReq.type = protocol_enums.E_Login_MAC
            loginReq.easyAccount = self.mac
            self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Easy_Login_Req, loginReq)[0])
            #change state
        elif msgid == protocol_enums.S_2_C_Easy_Login_Rsp:
            #check state
            if st.roleList.count > 0:
                enterReq = test_namedlist.SEnterReq()
                enterReq.userid = st.roleList.easyRoleList[0].userid
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Enter_Req, enterReq)[0])
            else :
                #创建角色
                createReq = test_namedlist.SCreateReq()
                createReq.rolename = "role%d"%(int(random.random()*1000))
                createReq.professionId = 100001
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Create_Req, createReq)[0])
            #change state
        elif msgid == protocol_enums.S_2_C_Enter_Rsp:
            #check state
            if st.errcode == protocol_enums.E_LOGIN_ROLE_SUCCESS:
                print "5.1 recv  C_2_S_Enter_Rsp ok"
                loadFinishedReq = test_namedlist.SLoadFinishedReq()
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_LoadFinished_Req, loadFinishedReq)[0])
                self.state = 0
                self.loginSuccess = True
            if st.errcode == protocol_enums.E_LOGIN_ROLE_NORECORD:
                #需要重新发送创建角色
                print "5.3 recv  C_2_S_Enter_Rsp need create role"                    
                createReq = test_namedlist.SCreateReq()
                createReq.rolename = self.new_rolename
                createReq.professionId = 100001
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Create_Req, createReq)[0])

            #change state
        elif msgid == protocol_enums.S_2_C_Create_Rsp:
            #check state
            """if st.errcode == 0:
                loadFinishedReq = test_namedlist.SLoadFinishedReq()
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_LoadFinished_Req, loadFinishedReq)[0])
                self.loginSuccess = True

            else:
                return False
                """
            #change state
        elif msgid == protocol_enums.S_2_C_Moveto_Rsp:
            #check state
            pass
            #change state
        elif msgid == protocol_enums.S_2_C_General_Error_Ntf:
            #check state
            pass
            #change state
        elif msgid == protocol_enums.S_2_C_General_Words_Ntf:
            #check state
            pass
            #change state
        elif msgid == protocol_enums.C_2_S_Protocol_Type_Rsp:
            #check state
            pass
            #change state
        elif msgid == protocol_enums.S_2_C_Kick_Ntf:
            #check state
            pass
            #change state
        elif msgid == protocol_enums.S_2_C_Server_Load_Finished_Ntf:
            self.loginSuccess = True
            print "recv  S_2_C_Server_Load_Finished_Ntf"
        else:
            pass
            #print "unhandled msgid :", msgid
        return True
    
    def doBindPassport(self):
        
        bindReq = test_namedlist_passport.SBindPassportReq()
        bindReq.passport.passport = self.passport
        bindReq.passport.password = self.password
        #bindReq.macAddress.macAddress = self.mac
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_S_Bind_Passport_Req, bindReq)[0])
        
        #print "send try bind passport "

    def doCreateAndBind(self):
        #print "send try create and bind passport "
        
        createAndBindReq = test_namedlist_passport.SCreateAndBindPassportReq()
        createAndBindReq.registerPassport.passport.passport = self.passport
        createAndBindReq.registerPassport.passport.password = self.password
        #createAndBindReq.macAddress.macAddress = self.mac
        createAndBindReq.registerPassport.email = "tsrmtrue@163.com"
        createAndBindReq.registerPassport.qq = 23
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_S_Create_And_Bind_Passport_Req, createAndBindReq)[0])
        
        print "send try create and bind passport "
        
    def onActiveTimer(self):
        #print "on active timer"
        if self.loginSuccess <> True:
            return
        
        if self.tryBind == True:
            self.tryBind = False
            self.doBindPassport()
        
        if self.tryCreateAndBind == True:    
            self.tryCreateAndBind = False
            self.doCreateAndBind()

        if self.send_move_time == None:
            self.send_move_time = datetime.now()
        elif (datetime.now() - self.send_move_time).total_seconds() > 20 :
            self.send_move_time = datetime.now()
            
            movetoReq = test_namedlist.SMovetoReq()
            movetoReq.x = random.randrange(0, 1280, 1)
            movetoReq.y = random.randrange(0, 320, 1)
            self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Moveto_Req, movetoReq)[0])
            
            #测试发送随机字段，服务器应该踢掉
            #self.add2send("232")
            
    def onParse(self):
        #print "on parse"
        st, length, msgid = test_namedlist_coding.getStruct(self.recvbuf)
        if length==0 and st <> None:
            print "recv the length ==0 ,while msgid is ",msgid
        if st <> None:
            self.recvbuf = self.recvbuf[length:]
            return self.onEvent(msgid, st)
        #if self.state == 0:
        #    self.onActiveTimer()
        return True
        
    def onRecv(self):
        return self.onParse()

class XHWEchoPeer(easySocket):
    def __init__(self, client):
        easySocket.__init__(self, client)

    def onRecv(self):
        self.add2send(self.recvbuf)
        #print "echo recv ", self.recvbuf
        self.recvbuf = ""
        return True

    
class XHWServer:
    server = None
    peerlist = []
    print_time = None
    def __init__(self, ip, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setblocking(False)
        self.server.bind((ip, port))
        self.server.listen(1)
    
    def tryAccept(self):
        try:
            conn, addr = self.server.accept()
            p = XHWEchoPeer(conn)
            self.peerlist.append(p)
        except socket.error,e :
            pass
            #print 'accept error ', e
        return True
        
    def run(self):
        if self.tryAccept() == False:
            return False
        t = []
        for p in self.peerlist:
            if p.run() == True:
                t.append(p)
            else:
                p.close()
        
        self.peerlist = t
        
        if self.print_time == None:
            self.print_time = datetime.now()
        elif (datetime.now() - self.print_time).total_seconds() > 10 :
            self.print_time = datetime.now()
            print "current client count is ", len(t)

        return True
    def close(self):
        self.server.close()
        self.server = None
        for p in self.peerlist:
            p.close()
            p = None
        self.peerlist = None
        
class XHWPassportClient(easySocket):
    state = -1
    ip = ""
    port = 0
    passport = ""
    password = ""
    serverList = None
    random_action_time = None
    def __init__(self, ip, port, passport, pwd ):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
        self.ip = ip
        self.port = port
        self.passport = passport
        self.password = pwd
            
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        if msgid == protocol_enums_passport.PS_2_C_ServerList_Ntf:
            self.on_serverlist_ntf(st)
            if self.state == -1:
                self.do_login_by_passport()
        elif msgid == protocol_enums_passport.PS_2_C_Login_By_Passport_Rsp:
            self.on_login_by_passport(st)
        elif msgid == protocol_enums_passport.PS_2_C_Choose_Server_Rsp:
            self.on_choose_server(st)
        elif msgid == protocol_enums_passport.PS_2_C_Register_Passport_Rsp:
            self.on_register_passport(st)
        elif msgid == protocol_enums_passport.PS_2_C_Login_By_SessionId_Rsp:
            pass
        elif msgid == protocol_enums_passport.PS_2_C_EnterGame_Notify_Rsp:
            self.on_enter_game(st)
        elif msgid == protocol_enums_passport.PS_2_C_Logoff_Passport_Rsp:
            pass
        return True
    
    def on_serverlist_ntf(self, st):
        print "on server list ntf"
        self.serverList = st
        #self.state = 0
        #self.do_login_by_passport()
    
    def do_login_by_passport(self):
        print "do login by passport"
        loginByPassportReq = test_namedlist_passport.SLoginByPassportReq()
        loginByPassportReq.passport.passport = self.passport
        loginByPassportReq.passport.password = self.password
        #loginByPassportReq.macAddress.macAddress = ""
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_Login_By_Passport_Req, loginByPassportReq)[0])
    
    def on_login_by_passport(self, st):
        print "on login by passport"
        if st.errcode == protocol_enums_passport.E_PASSPORT_ABOUT_FAILED_NO_SUCH_PASSPORT:
            #发送创建
            self.do_register_passport()
        elif st.errcode == protocol_enums_passport.E_PASSPORT_ABOUT_OK:
            #登陆成功
            self.state = 1
            #self.do_choose_server()
        elif st.errcode == protocol_enums_passport.E_PASSPORT_ABOUT_FAILED_PASSWORD_ERROR:
            #密码错误
            pass
    
    def do_register_passport(self):
        print "do register passport"
        registerPassportReq = test_namedlist_passport.SRegisterPassportReq()
        registerPassportReq.registerPassport.passport.passport = self.passport
        registerPassportReq.registerPassport.passport.password = self.password
        registerPassportReq.registerPassport.email = ""
        registerPassportReq.registerPassport.qq = 0
        #registerPassportReq.macAddress.macAddress = ""
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_Register_Passport_Req, registerPassportReq)[0])

    def on_register_passport(self, st):
        print "on register passport"
        if st.errcode == protocol_enums_passport.E_PASSPORT_ABOUT_OK:
            #重新登陆
            self.do_login_by_passport()
            
    
    def do_enter_game(self):
        print "do enter game ntf req"
        if self.serverList <> None and self.serverList.count > 0:
            enterGameNotifyReq = test_namedlist_passport.SEnterGameNotifyReq()
            enterGameNotifyReq.serverid = self.serverList.list[0].serverid
            self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_EnterGame_Notify_Req, enterGameNotifyReq)[0])
        
    def on_enter_game(self, st):
        print "on enter game "
        pass
    
    def do_choose_server(self):
        print "do choose server",self.serverList.count, "  ", self.serverList.list[0].serverid
        if self.serverList <> None and self.serverList.count > 0:
            chooseServerReq = test_namedlist_passport.SChooseServerReq()
            chooseServerReq.serverid = self.serverList.list[0].serverid
            self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_Choose_Server_Req, chooseServerReq)[0])
    
    def do_get_server_list(self):
        getServerListReq = test_namedlist_passport.SGetServerListReq()
        getServerListReq.page = 0
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_Get_ServerList_Req, getServerListReq)[0])
        
    def do_get_server_desc(self):
        getServerDescReq = test_namedlist_passport.SGetServerDescReq()
        getServerDescReq.serverid = self.serverList.list[0].serverid
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_PS_Get_Server_Desc_Req, getServerDescReq)[0])
            
    def on_choose_server(self, st):
        #发起进入游戏包
        print "on choose server"
        #self.do_enter_game()

    def onActiveTimer(self):
        if self.state < 0:
            return True
        if self.random_action_time == None:
            self.random_action_time = datetime.now()
        elif (datetime.now() - self.random_action_time).total_seconds() > 2 :
            self.random_action_time = datetime.now()
            self.do_get_server_list()
            self.do_choose_server()
            self.do_get_server_desc()
        return True
    
    def onParse(self):
        #print "on parse"
        st, length, msgid = test_namedlist_coding_passport.getStruct(self.recvbuf)
        if length==0 and st <> None:
            print "recv the length ==0 ,while msgid is ",msgid
        if st <> None:
            self.recvbuf = self.recvbuf[length:]
            return self.onEvent(msgid, st)
        return True
        
    def onRecv(self):
        return self.onParse()

