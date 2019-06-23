# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
sys.path.append('../autotest_client')
from easySocket import *
from test_namedlist import *
from test_namedlist_coding import *
from protocol_enums import *
import random
from datetime import *

import build_server_status_4_client
from get_server_config import *

import test_easySocket

class ServerReportClient(easySocket):
    send_report_time = None
    def __init__(self, ip, port, servername):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((ip, port))
        s.setblocking(False)
        easySocket.__init__(self, s)
        self.servername = servername

    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        return True
        
    def onActiveTimer(self):
        if self.send_report_time == None:
            self.send_report_time = datetime.now()
        elif (datetime.now() - self.send_report_time).total_seconds() > 1 :
            self.send_report_time = datetime.now()
            rep = SServerStatusReporter()
            rep.servername = self.servername
            rep.ip = "%r"
            rep.port = "%r"
            rep.globalntf = "公共厕所"
            rep.serverstatus = "%d"%(random.randrange(0, 100, 1))
            self.add2send(getSendbuf(S_2_S_Server_Status_Reporter, rep)[0])
            print "send reporter status %s"%(rep.serverstatus)
                   
    def onParse(self):
        st, length, msgid = getStruct(self.recvbuf)
        if st <> None:
            self.recvbuf = self.recvbuf[length:]
            return self.onEvent(msgid, st)
        self.onActiveTimer()
        return True
        
    def onRecv(self):
        return self.onParse()

class ServerReportMasterPeer(easySocket):
    def __init__(self, client):
        easySocket.__init__(self, client)

    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        if msgid == S_2_S_Server_Status_Reporter:
            global g_ss_dict
            if g_ss_dict.get(st.servername, None) <> None:
                g_ss_dict[st.servername][3] = st.serverstatus
                #仅仅替换这个
            build_server_status_4_client.build_xml_file("ss.xml", g_ss_dict)
        return True

    def onRecv(self):
        #print "onrecv"
        st, length, msgid = getStruct(self.recvbuf)
        if st <> None:
            self.recvbuf = self.recvbuf[length:]
            return self.onEvent(msgid, st)
        return True

    
class ServerReportListener:
    server = None
    peerlist = []
    def __init__(self, ip, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setblocking(False)
        self.server.bind((ip, port))
        self.server.listen(1)
    
    def init_all_server_cfg(self, configFileName):
        init_master_server_status(configFileName)
        global g_ss_dict
        print g_ss_dict.keys()
    
    def tryAccept(self):
        try:
            conn, addr = self.server.accept()
            p = ServerReportMasterPeer(conn)
            self.peerlist.append(p)
        except socket.error,e :
            if e[0] in [10035,]:
                return True
            print 'accept error ', e
            return False
        return True
        
    def run(self):
        t = []
        #print "len of self.peerlist is ", len(self.peerlist)
        
        for p in self.peerlist:
            if p.run() == True:
                t.append(p)
            else:
                print "close "
                p.close()
        #print "len of t is ", len(t)
        self.peerlist = t
        if self.tryAccept() == False:
            return False
        return True
    def close(self):
        self.server.close()
        self.server = None
        for p in self.peerlist:
            p.close()
            p = None
        self.peerlist = None
        
class GMClient(test_easySocket.XHWClient):
    send_gm_check_time = None
    def __init__(self, ip, port, account, new_role):
        test_easySocket.XHWClient.__init__(self, ip, port, account, new_role)

    def onEvent(self, msgid, st):
        #print "on event id : ", msgid
        test_easySocket.XHWClient.onEvent(self, msgid, st)
        if msgid == S_2_C_Server_Status_Ntf:
            global g_ss_dict
            if g_ss_dict.get(st.servername, None) <> None:
                if st.maxLoad <> 0:
                    status = 0
                    if st.currentLoad*100/st.maxLoad > 20:
                        status = 1
                    g_ss_dict[st.servername][3] = status
                    print "here comes the server report", st.servername, "curload ", st.currentLoad, " maxload ",st.maxLoad 
                    #仅仅替换这个
                    build_server_status_4_client.build_xml_file("ss.xml", g_ss_dict)
        return True
        
    def onActiveTimer(self):
        #test_easySocket.XHWClient.onActiveTimer(self)
        if self.send_gm_check_time == None:
            self.send_gm_check_time = datetime.now()
        elif (datetime.now() - self.send_gm_check_time).total_seconds() > 100 :
            self.send_gm_check_time = datetime.now()
            
            gmreq = SGmcmdReq()
            gmreq.cmd = "reportserver"
            self.add2send(getSendbuf(C_2_S_GmCmd_Req, gmreq)[0])
            print "send reporter server gmcmd "
                   
def init_all_server_cfg( configFileName):
    init_master_server_status(configFileName)
    global g_ss_dict
    print g_ss_dict.keys()
