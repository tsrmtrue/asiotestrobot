# -*- coding: utf8 -*-
import sys
sys.path.append('../autotest_lib')
from easySocket import *
from datetime import *
import http_snap


from test_namedlist import *
from test_namedlist_coding import *
from protocol_enums import *


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
        elif (datetime.now() - self.send_msg_time).total_seconds() > 1 :
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
            self.add2send(http_get)
            
    def onParse(self):
        #print "on parse"
        return True
        
    def onRecv(self):
        if self.recvbuf <> "":
            print "RepeatSendClient recv ", self.recvbuf, " time is ", datetime.now()
            self.recvbuf = ""
        return self.onParse()

class HttpClient(easySocket):
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

    def onActiveTimer(self):
        if self.send_msg_time == None:
            self.send_msg_time = datetime.now()
        elif (datetime.now() - self.send_msg_time).total_seconds() > 1 :
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

            http_get = """GET /DSC01076.gif HTTP/1.1
Host: 127.0.0.1:80
User-Agent: ApacheBench/2.3
Accept: */*

            """
            if self.send_idx == 0:
                self.send_idx = 1
                self.add2send(http_get)
            
    def onParse(self):
        #print "on parse"
        return True
        
    def onRecv(self):
        if self.recvbuf <> "":
            print "#################", self.recvbuf, "#################", datetime.now()
            self.recvbuf = ""
        return self.onParse()



class EchoPeer(easySocket):
    def __init__(self, client):
        easySocket.__init__(self, client)

    def onRecv(self):
        #print "echopeer onrecv"
        if self.recvbuf <> "":
            print "EchoPeer recv ", self.recvbuf, " time is ", datetime.now()
            #print self.recvbuf
            easySocket.add2send(self, self.recvbuf)
            self.recvbuf = ""
        return True


class HttpPeer(easySocket):
    def __init__(self, client):
        easySocket.__init__(self, client)

    def onParse(self):
        #print "on parse"
        #print "HttpPeer recv ", self.recvbuf, " time is ", datetime.now()
        print self.recvbuf
        msgRsp = SMsg()
        msgRsp.msg = "back from mother " + self.recvbuf
        easySocket.add2send(self, getSendbuf(S_2_C_Msg_Rsp, msgRsp)[0])

        #easySocket.add2send(self, self.recvbuf)

        """
        req = http_snap.CEasyHttpReq(self.recvbuf)
        print req
        if req.action == "GET":
            cmd = req.path.split("/")
            if len(cmd >= 3):
                if cmd[0] == "control":
                    if cmd[2] == "start":
                        pass
        """
            #不许直接访问,算是一种防御吧
            #if req.path == "/":
            #    html_file = http_snap.html_test
            #    html_file_length = len(html_file)
            #    self.add2send(http_snap.http_get_rsp_template%(locals()))
            #"""
        return True

    def onRecv(self):
        #print "echopeer onrecv"
        if self.recvbuf <> "":
            if self.onParse():
                self.recvbuf = ""
        return True



class EasyServer:
    server = None
    peerlist = []
    print_time = None
    def __init__(self, ip, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.setblocking(False)
        self.server.bind((ip, port))
        self.server.listen(100)
    
    def createPeer(self, conn):
        return HttpPeer(conn)
    
    def tryAccept(self):
        try:
            conn, addr = self.server.accept()
            conn.setblocking(False)
            p = self.createPeer(conn)
            self.peerlist.append(p)
        except socket.error,e :
            #print 'accept error ', e
            if e[0] in [10035, 11, 35]:  #windows:10035,centos:11,macos:35 
                return True
            else :
                return False
            #print 'accept error ', e

        except:
            print "unknown accept exception"
        return True
            
    def run(self):
        #print "server run"
        if self.tryAccept() == False:
            #print "try accept return false"
            return False
        else:
            pass
            #print "try accept return true"

        t = []
        for p in self.peerlist:
            try:
                if p.run() == True:
                    t.append(p)
                    #print "p run ok"
                else:
                    #print "peer run failed"
                    p.close()
            except Exception,ex:
                print "peer run exception ", Exception,":",ex 
                p.close()
        
        self.peerlist = t
        
        if self.print_time == None:
            self.print_time = datetime.now()
        elif (datetime.now() - self.print_time).total_seconds() > 10 :
            self.print_time = datetime.now()
            #print "current client count is ", len(t), " time ", datetime.now()

        return True
    def close(self):
        self.server.close()
        self.server = None
        for p in self.peerlist:
            p.close()
            p = None
        self.peerlist = None
        
import select

class SelectServer:
    server = None
    print_time = None
    timer_time = None
    rlist = []
    wlist = []
    peerDict = {}

    def __init__(self, ip, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.setblocking(False)
        self.server.bind((ip, port))
        self.server.listen(100)
        self.rlist.append(self.server)

    def onTimer(self):
        for s in self.peerDict.keys():
            self.peerDict[s].onActiveTimer()
        
    def createPeer(self, conn):
        return EchoPeer(conn)
    
    def tryAccept(self):
        #print "try accept"
        try:
            conn, addr = self.server.accept()
            conn.setblocking(False)
            p = self.createPeer(conn)
            self.rlist.append(conn)
            self.peerDict[conn] = p

        except socket.error,e :
            pass
            #print 'accept error ', e
        return True
        
    def run(self):
        #print "rlist is  ", len(self.rlist)
        readable , writable , exceptional = select.select(self.rlist, self.wlist, self.rlist, 0)

        #print "readable is ", len(readable)
        _templist = []
        for s in readable:
            if s is self.server:
                if self.tryAccept() == False:
                    #print "try accept return false"
                    return False
            else:
                peer = self.peerDict.get(s, None)
                #if peer == None:
                #    print "peer is null"
                if peer <> None and peer.tryRecv() and peer.onRecv():
                    pass
                else:
                    #print "close peer "
                    s.close()
                    _templist.append(s)

        for toD in _templist:
            if toD in self.rlist:
                self.rlist.remove(toD)
                try:
                    del self.peerDict[toD]
                except:
                    pass

        #if len(exceptional) > 0:
        #    print "exceptional count is ", len(exceptional)

        #if len(readable) > 0:
        #    print "readable count is ", len(readable)
        
        """if self.tryAccept() == False:
            return False
        t = []
        for p in self.peerlist:
            if p.run() == True:
                t.append(p)
            else:
                p.close()
        self.peerlist = t"""
        
        if self.print_time == None:
            self.print_time = datetime.now()
        elif (datetime.now() - self.print_time).total_seconds() > 10 :
            self.print_time = datetime.now()
            print "current client count is ", len(self.rlist), " time ", datetime.now()

        if self.timer_time == None:
            self.timer_time = datetime.now()
        elif (datetime.now() - self.timer_time).total_seconds() > 2 :
            self.timer_time = datetime.now()
            self.onTimer()
        return True
    
    
    def close(self):
        self.server.close()
        self.server = None
        for p in self.peerlist:
            p.close()
            p = None
        self.peerlist = None
    
class EpollEchoPeer(easySocket):
    epollServer = None
    def __init__(self, client, _epollServer):
        easySocket.__init__(self, client)
        self.epollServer = _epollServer

    def onRecv(self):
        if self.recvbuf <> "":
            print "echo recv ", self.recvbuf, " time is ", datetime.now()
            self.recvbuf = ""
            self.add2send(http_snap.http_get_rsp)
        return True

    def add2send(self, buf):
        easySocket.add2send(self, buf)
        self.epollServer.postSend(self.client.fileno())

    def needSend(self):
        return self.sendbuf == ""

import select

class EPollServer:
    server = None
    print_time = None
    timer_time = None
    peerDict = {}
    postSendList = []
    epoll = None
    def __init__(self, ip, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.setblocking(False)
        self.server.bind((ip, port))
        self.server.listen(10000)
        self.epoll = select.epoll()
        self.epoll.register(self.server.fileno(), select.EPOLLIN | select.EPOLLET)

    def onTimer(self):
        for fn in self.peerDict.keys():
            peer = self.peerDict[fn]
            peer.onActiveTimer()
        
    def tryAccept(self):
        while 1:
            try:
                conn, addr = self.server.accept()
                conn.setblocking(False)
                p = EpollEchoPeer(conn, self)
                self.peerDict[conn.fileno()] = p
                self.epoll.register(conn.fileno(), select.EPOLLIN | select.EPOLLET)
            except socket.error,e :
                #print 'accept error ', e
                break;
            except Exception, e:
                #print "try accept exception, ", e
                break
        return True

    def postSend(self, fileno):
        if not fileno in self.postSendList:
            self.postSendList.append(fileno)

    def trySendAll(self):
        _postSendList=[]
        for fileno in self.postSendList:
            peer = self.peerDict.get(fileno, None)
            if peer <> None:
                peer.trySend()
                if peer.needSend():
                    _postSendList.append(fileno)
            else :
                print "not found the peer, ",fileno
        self.postSendList = _postSendList


    def run(self):
        #处理epoll事件
        events = self.epoll.poll(0, 10000)
        for fileno, event in events:
            if fileno == self.server.fileno():
                self.tryAccept()
            elif event & select.EPOLLIN:
                peer = self.peerDict.get(fileno, None)
                if peer <> None:
                    if peer.tryRecv() and peer.onRecv():
                        pass
                    else:
                        #删除
                        self.epoll.unregister(fileno)
                        try :
                            peer.close()
                            del  self.peerDict[fileno]
                        except:
                            print "del peer exception"
                            pass
            elif event & select.EPOLLHUP:
                self.epoll.unregister(fileno)
                peer = self.peerDict.get(fileno, None)
                if peer <> None:
                    peer.close()
                    try :
                        peer.close()
                        del  self.peerDict[fileno]
                    except:
                        print "del peer exception"
                        pass

        #处理所有send
        self.trySendAll()
        #处理所有timer
        self.onTimer()
        #打印日志
        if self.print_time == None:
            self.print_time = datetime.now()
        elif (datetime.now() - self.print_time).total_seconds() > 10 :
            self.print_time = datetime.now()
            print "current client count is ", len(self.peerDict), " time ", datetime.now()

        if self.timer_time == None:
            self.timer_time = datetime.now()
        elif (datetime.now() - self.timer_time).total_seconds() > 2 :
            self.timer_time = datetime.now()
            self.onTimer()
        return True
    
    
    def close(self):
        self.server.close()
        self.server = None
        for p in self.peerlist:
            p.close()
            p = None
        self.peerlist = None

