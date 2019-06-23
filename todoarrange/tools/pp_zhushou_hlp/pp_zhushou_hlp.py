# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')

sys.path.append('../autotest_client')
from datetime import *
from easySocket import *
import http_snap
import mass_server_listener

class InnerPeer(easySocket):
    serverInstance = None
    zoneid = 0
    def __init__(self, client, _serverInstance):
        easySocket.__init__(self, client)
        self.serverInstance = _serverInstance
        
    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        if msgid == protocol_enums.S_2_OS_PP_Server_Register_Req:
            print "here is the S_2_OS_PP_Server_Register_Req ", st.zoneid
            self.zoneid = st.zoneid
            self.serverInstance.addInnerPeerInstance(self.zoneid, self)
        
        elif msgid == protocol_enums.S_2_OS_PP_Server_Order_Rsp:
            print "here is the S_2_OS_PP_Server_Order_Rsp "

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
        if self.recvbuf <> "":
            #print "echopeer onrecv"
            return self.onParse()
    
    def close(self):
        self.serverInstance.delInnerPeerInstance(self.zoneid)
        return easySocket.close(self)


class PPInnerServer(mass_server_listener.EasyServer):
    dict_zoneid_2_innerPeer = {}
    
    def addInnerPeerInstance(self, zoneid, innerPeer):
        self.dict_zoneid_2_innerPeer[zoneid] = innerPeer
        
    def delInnerPeerInstance(self, zoneid):
        self.dict_zoneid_2_innerPeer[zoneid] = None
        
    def createPeer(self, conn):
        return InnerPeer(conn, self)
    
    
    
class PPPayPeer(easySocket):
    def __init__(self, client):
        easySocket.__init__(self, client)

    def onParse(self):
        return True

    def onRecv(self):
        #print "echopeer onrecv"
        if self.recvbuf <> "":
            if self.onParse():
                self.recvbuf = ""
        return True

class PPPayServer(mass_server_listener.EasyServer):
    def createPeer(self, conn):
        return InnerPeer(conn)



