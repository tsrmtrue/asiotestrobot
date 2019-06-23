# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
sys.path.append('../autotest_client')

from easySocket import *
from datetime import *
import test_namedlist
import test_namedlist_coding
import protocol_enums
import test_namedlist_passport
import test_namedlist_coding_passport
import protocol_enums_passport
import random
import time

class MasterControlClient(easySocket):
    send_msg_time = None
    ip = ""
    port = 0
    mission_cmd=[]
    cmd_rsp=[]
    def __init__(self, ip, port):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
                
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        if msgid == protocol_enums_passport.S_2_C_Master_Control_Rsp:
            #print "here comes the rsp ", st.errcode
            self.cmd_rsp.remove(st.errcode)

        return True

    def doSendCmd(self, missionCmd):
        masterControlReq = test_namedlist_passport.SMasterControlReq()
        masterControlReq.cmd = missionCmd
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_S_Master_Control_Req, masterControlReq)[0])
        
    def onActiveTimer(self):
        for cmd in self.mission_cmd:
            self.doSendCmd(cmd)
            print "send the cmd ", cmd
        self.mission_cmd = []
    def onParse(self):
        #print "on parse"
        st, length, msgid = test_namedlist_coding_passport.getStruct(self.recvbuf)
        #print "on parse, ", st, length, msgid
        if length==0 and st <> None:
            print "recv the length ==0 ,while msgid is ",msgid
        if st <> None:
            self.recvbuf = self.recvbuf[length:]
            return self.onEvent(msgid, st)
        #if self.state == 0:
        #    self.onActiveTimer()
        return True
        
    def onRecv(self):
        if self.recvbuf <> "":
            #print " onrecv"
            return self.onParse()
        return True
    
    #------业务
    def addCmd(self, cmd):
        self.mission_cmd.append(cmd)
        self.cmd_rsp.append(cmd)
        
    def checkTaskFinish(self):
        return len(self.cmd_rsp) == 0

    
def doMasterControl(ip, port, cmdList):    
    if len(cmdList) == 0:
        return
    c = MasterControlClient(ip, port)
    for cmd in cmdList:
        c.addCmd(cmd)
    
    try:
        while(1):
            c.run()
            time.sleep(1)
            if c.checkTaskFinish():
                break;
    except KeyboardInterrupt :
        pass
    print "all task finished"
    c.close()
    print "all ok"

""""l = list()
l.append(protocol_enums_passport.E_M_C_C_Stop_Server)
doMasterControl("192.168.1.32", 20001, l)
"""


