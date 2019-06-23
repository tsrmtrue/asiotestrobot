# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
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
    mission_cmd=[
                 protocol_enums_passport.E_M_C_C_Reload_Configure,
                 protocol_enums_passport.E_M_C_C_Stop_Server,
                 ]
    def __init__(self, ip, port):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
            
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        return True

    def doSendCmd(self, missionCmd):
        masterControlReq = test_namedlist_passport.SMasterControlReq()
        masterControlReq.cmd = missionCmd
        self.add2send(test_namedlist_coding_passport.getSendbuf(protocol_enums_passport.C_2_S_Master_Control_Req, masterControlReq)[0])
        
    def onActiveTimer(self):
        for cmd in self.mission_cmd:
            self.doSendCmd(cmd)
        self.mission_cmd = []
    def onParse(self):
        #print "on parse"
        return True
        
    def onRecv(self):
        if self.recvbuf <> "":
            print "echo recv ", self.recvbuf, " time is ", datetime.now()
            self.recvbuf = ""
        return self.onParse()
c = MasterControlClient("192.168.1.90", 18004)
try:
    while(1):
        c.run()
        time.sleep(1)
except KeyboardInterrupt :
    pass
c.close()

