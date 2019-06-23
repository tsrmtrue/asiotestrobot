# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
sys.path.append('../autotest_client')
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
from datetime import *
random.seed(datetime.now())

g_npc_pos = [
             [700, 150],
             [500, 150],
             [1100, 150],
             [1480, 150],
             [200, 150],
             [1280, 150],
             ]

STATE_UNINIT   = -1
STATE_IN_FUBEN = 0
STATE_IN_LOBBY = 1
STATE_IN_FAKE_FIGHT = 2

class LJFakePlayer(easySocket):
    #状态机控制
    loginSuccess = False
    state = STATE_UNINIT
    current_fight_count = 0
    #时间片控制
    trigger_time = None
    #基本信息
    ip = ""
    port = 0
    passport = ""
    password = ""
    email = ""
    mac = ""
    active_time = None
    new_rolename = ""
    first_login = False
    level = 0
    fuben_id = 0
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
                createReq.rolename = self.new_rolename#"roleyy%d"%(int(random.random()*1000))
                createReq.professionId = random.randrange(100001, 100004)
                self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Create_Req, createReq)[0])
                self.first_login = True
            #change state
        elif msgid == protocol_enums.S_2_C_Enter_Rsp:
            #check state
            if st.errcode == protocol_enums.E_LOGIN_ROLE_SUCCESS:
                print "5.1 recv  C_2_S_Enter_Rsp ok"
                self.doSendLoadFinishedReq()
                self.level = st.roles[0].roleBasic.level
                print "self level is ", self.level
                self.loginSuccess = True
                self.state = STATE_IN_LOBBY
            if st.errcode == protocol_enums.E_LOGIN_ROLE_NORECORD:
                #需要重新发送创建角色
                print "5.3 recv  C_2_S_Enter_Rsp need create role"                    
                createReq = test_namedlist.SCreateReq()
                createReq.rolename = self.new_rolename
                createReq.professionId = random.randrange(100001, 100004)
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
            self.active_time = datetime.now()
            print "recv  S_2_C_Server_Load_Finished_Ntf"
            self.state = STATE_IN_LOBBY
        elif msgid == protocol_enums.S_2_C_LeaveFuben_Rsp :
            self.doSendLoadFinishedReq()
            
        elif msgid == protocol_enums.S_2_C_EnterFuben_Rsp :
            self.state = STATE_IN_FUBEN
            self.current_fight_count = 0
            
        elif msgid == protocol_enums.S_2_C_Fight_Rsp :
            self.doGotoFightSceneReq()
            self.doLeaveFightSceneReq()
        elif msgid == protocol_enums.S_2_C_Refresh_All_Prize_Ntf:
            self.onPrizeNtfAll(st)
        elif msgid == protocol_enums.S_2_C_Refresh_Prize_Ntf:
            self.onPrizeNtf(st)
        else:
            pass
            #print "unhandled msgid :", msgid
        return True
        
    def onActiveTimer(self):
        #print "on active timer"
        if self.loginSuccess <> True:
            return

        if self.trigger_time == None:
            self.trigger_time = datetime.now()
        elif (datetime.now() - self.trigger_time).total_seconds() > 10 :
            self.trigger_time = datetime.now()
            self.doStateMachine()
            return 
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
    
    def doSendLoadFinishedReq(self):
        loadFinishedReq = test_namedlist.SLoadFinishedReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_LoadFinished_Req, loadFinishedReq)[0])

        
    def onRecv(self):
        return self.onParse()

    def doStateMachine(self):
        if self.state == STATE_IN_LOBBY:
            if self.first_login:
                self.first_login = False
                self.state = STATE_IN_FAKE_FIGHT
                self.doShowFakeFight()
                print "first login show fake fight"
            else:
                #在大厅,随机执行, 跑到npc身边, 跑到任意地点, 进入副本
                if int(random.random() * 100) % 100 < 10:
                    if self.level >10:
                        self.doPlunder()
                if int(random.random() * 100) % 100 < 90:
                    fubenid = self.getFuben2Fight()
                    print "goto fuben ", fubenid
                    self.doEnterFuben(fubenid)
                elif int(random.random() * 100) % 100 < 50:
                    x, y = self.randomChoosePoint()#randomChooseNPC
                    self.doMove(x, y)
                else:
                    x, y = self.randomChooseNPC()#
                    self.doMove(x, y)
                    

        elif self.state == STATE_IN_FUBEN:
            #在副本中,顺序进行 3波攻击, 然后回归主城
            if self.current_fight_count < 2:
                #发送攻击指令
                self.doFight()
                self.current_fight_count = self.current_fight_count + 1
            else :
                #发送回城指令
                self.doLeaveFuben()
        elif self.state == STATE_IN_FAKE_FIGHT:
            self.doLeaveFuben()
    
    def doMove(self, x, y):
        movetoReq = test_namedlist.SMovetoReq()
        movetoReq.x = x
        movetoReq.y = y
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Moveto_Req, movetoReq)[0])
            
    def doEnterFuben(self, fubenid):
        enterFubenReq = test_namedlist.SEnterFubenReq()
        enterFubenReq.fubenid = fubenid
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_EnterFuben_Req, enterFubenReq)[0])
        
    def doFight(self):
        fightReq = test_namedlist.SFightReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Fight_Req, fightReq)[0])

    def doLeaveFuben(self):
        leaveFubenReq = test_namedlist.SLeaveFubenReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_LeaveFuben_Req, leaveFubenReq)[0])
        
    def randomChooseNPC(self):
        global g_npc_pos
        return g_npc_pos[int(random.random()*100)%len(g_npc_pos)]
    
    def randomChoosePoint(self):
        x = random.randrange(50, 1000)
        y = random.randrange(50, 140)
        return (x,y)
        
    def getFuben2Fight(self):
        fubenid = self.fuben_id %(16010020-16010001) + 16010001
        self.fuben_id = self.fuben_id + 1
        return fubenid
        
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

    def doGotoFightSceneReq(self):
        goToFightSceneReq = test_namedlist.SGoToFightSceneReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_GoToFightScene_Req, goToFightSceneReq)[0])

    def doLeaveFightSceneReq(self):
        leaveFightSceneReq = test_namedlist.SLeaveFightSceneReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_LeaveFightScene_Req, leaveFightSceneReq)[0])
        
    def doShowFakeFight(self):
        showFakeFightReq = test_namedlist.SShowFakeFightReq()
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Show_Fake_Fight_Req, showFakeFightReq)[0])

    def getLiveTime(self):
        if self.active_time <> None:
            return (datetime.now() - self.active_time).total_seconds()
        return 0
    
    def onPrizeNtf(self, st):
        for i in range(0, st.count):
            self.doGetPrize(st.s[i])
    
    def onPrizeNtfAll(self, st):
        for i in range(0, st.count):
            self.doGetPrize(st.s[i])
            
    def doGMCmd(self, str):
        gmcmdReq = test_namedlist.SGmcmdReq()
        gmcmdReq.cmd = str
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_GmCmd_Req, gmcmdReq)[0])
        
        
    def doGetPrize(self, st):
        #print "do get prize "
        if st.f == 1 and st.id < 200000:
            print st
            getPrizeReq = test_namedlist.SGetPrizeReq()
            getPrizeReq.id = st.id
            self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Get_Prize_Req, getPrizeReq)[0])
        
    def doPlunder(self):
        plunderTerritoryPrizeReq = test_namedlist.SPlunderTerritoryPrizeReq()
        fubenid = random.randrange(16010001, 16010020)
        plunderTerritoryPrizeReq.id = fubenid
        self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Plunder_Territory_Prize_Req, plunderTerritoryPrizeReq)[0])
        
"""
    //福利
    S_2_C_Refresh_All_Prize_Ntf, //SAllPrizeNtf,客户端删除所有哦信息,然后刷新界面
    C_2_S_Get_Prize_Req, //SGetPrizeReq.
    S_2_C_Get_Prize_Rsp, //SGetPrizeRsp关闭菊花用,没有实际作用
    S_2_C_Refresh_Prize_Ntf, //SPrizeNtf客户端根据id更新条目,添加或者更改


    //在线奖励
    S_2_C_OnlineGift_Ntf, //SOnlineGiftNtf在线奖励倒计时，单位为秒，收到本协议才显示按钮
    C_2_S_OnlineGift_Get_Req, //SOnlineGiftGetReq请求得到奖励
    
    //掠夺
    C_2_S_Plunder_Territory_Prize_Req,//SPlunderTerritoryPrizeReq

"""