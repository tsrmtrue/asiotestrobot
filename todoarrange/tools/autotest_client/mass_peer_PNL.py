# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
from easySocket import *
from datetime import *
import http_snap


from test_namedlistPNL import *
from test_namedlist_codingPNL import *
from protocol_enums_PNL import *


class RepeatSendClient(easySocket):
    send_msg_time = None
    ip = ""
    port = 0
    send_idx=0
    def __init__(self, ip, port):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
            
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        return True

    def doSendMsg(self):
        return 
        print "send try create and bind passport "
        self.add2send("hello world fd is %d, time is %r"%( self.client.fileno() , datetime.now()))
        
    def onActiveTimer(self):
        if self.send_msg_time == None:
            self.send_msg_time = datetime.now()
        elif (datetime.now() - self.send_msg_time).total_seconds() > 20 :
            self.send_msg_time = datetime.now()
            self.doSendMsg()
            #测试发送
            """
            movetoReq = test_namedlist.SMovetoReq()
            movetoReq.x = random.randrange(0, 1280, 1)
            movetoReq.y = random.randrange(0, 320, 1)
            self.add2send(test_namedlist_coding.getSendbuf(protocol_enums.C_2_S_Moveto_Req, movetoReq)[0])
            """
            #测试发送随机字段，服务器应该踢掉
            """
            #print "add send "
            self.send_idx = self.send_idx + 1
            self.add2send("%d, %d"%(self.client.fileno(), self.send_idx))
            """
            #发送模拟httpget协议 


            http_get = """GET / HTTP/1.0
Host: 192.168.1.33:9999
User-Agent: ApacheBench/2.3
Accept: */*

            """
            sptr = SProtocolTypeRpt()
            sptr.type = 98
            sptr.version = 76
            http_get = getSendbuf(C_2_S_Protocol_Type_Rpt, sptr)[0]
            self.add2send(http_get)



            # selr = SEasyLoginReq()
            # selr.easyAccount = "hi there "
            # selr.type = 87
            # http_get = getSendbuf(C_2_S_Easy_Login_Req, selr)[0]
            # self.add2send(http_get)
            
    def onParse(self):
        #print "on parse"
        st, totalLen, msgid = getStruct(self.recvbuf)
        if msgid > 0 :
            self.recvbuf = self.recvbuf[totalLen:]
            if msgid == C_2_S_Protocol_Type_Rsp:
                print "the protocol type rsp ", st.errcode
            elif msgid == S_2_C_Easy_Login_Rsp:
                print "the easy login rsp returns ", st.roleList.easyRoleList.rolename

        return True
        
    def onRecv(self):
        if self.recvbuf <> "":
            # print "RepeatSendClient recv ", self.recvbuf, " time is ", datetime.now()
            # self.recvbuf = ""
            return self.onParse()

