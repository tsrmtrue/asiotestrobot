# -*- coding: utf8 -*-
from test_namedlist import *
from test_namedlist_coding import *
from protocol_enums import *
import socket
import time
import random
from datetime import datetime
import os


g_list_mac_address = list() #["mac1", "mac2"]

g_map_logining_peer = {} #{s:['mac',,],}

g_map_authenticated_peer = {} #{s:['', ''],}

g_list_authenticated_peer = [] #[client,]

g_login_steps = {
                 #"step1":count
                 }

def add_login_step(step):
    global g_login_steps
    r = g_login_steps.get(step, None)
    if r == None:
        g_login_steps[step] = 1
    else :
        g_login_steps[step] = r+1

def print_login_step():
    global g_login_steps
    for k in sorted(g_login_steps.keys()):
        print "%r, %r"%(k ,g_login_steps[k])

def generate_mac(count, prefix):
    global g_list_mac_address
    i=0
    while i<count:
    #for i in range(count):
        g_list_mac_address.append("%(prefix)s%(i)d"%(locals()))
        i=i+1
    print g_list_mac_address
        
def start_connection():
    global g_list_mac_address
    global g_map_logining_peer
    for mac in g_list_mac_address:
        client = socket.socket()
        client.connect(("192.168.1.106",9090))
        client.setblocking(True)
        print  "new client",client
        g_map_logining_peer[client] = [mac,-1, -1]
    g_list_mac_address = []

def do_login():
    global g_map_logining_peer
    global g_map_authenticated_peer
    global g_list_authenticated_peer
    
    for client in g_map_logining_peer.keys():

        recvstr = client.recv(1024)
        #login
        print "start login", g_map_logining_peer[client][0]
        
        loginReq = SLoginReq()
        loginReq.type = E_Login_MAC_ONLY
        loginReq.account = "" 
        loginReq.pwd = ""
        loginReq.mac = g_map_logining_peer[client][0]
        
        client.send(getSendbuf(C_2_S_Login_Req, loginReq)[0])
        recvstr = client.recv(1024)
        #������Ϸ
        print "start enter"
        enterReq = SEnterReq()
        client.send(getSendbuf(C_2_S_Enter_Req, enterReq)[0])
        recvstr = client.recv(1024*100)
        #���,�����ʾ�����򴴽�
        enterRsp, totalLen, msgid = getStruct(recvstr)
        print enterRsp
        if enterRsp.errcode == 2:
            continue
        if enterRsp.errcode == 1:
            print "create role ", g_map_logining_peer[client][0]
            createReq = SCreateReq()
            createReq.rolename = "aa"+g_map_logining_peer[client][0]
            createReq.professionId = 100001

            
            client.send(getSendbuf(C_2_S_Create_Req, createReq)[0])
            recvstr = client.recv(1024)
            
        time.sleep(2)

        print "start loadfinish"
        loadFinishedReq = SLoadFinishedReq()
        client.send(getSendbuf(C_2_S_LoadFinished_Req, loadFinishedReq)[0])
        recvstr = client.recv(1024*100)
        client.setblocking(False)

        g_map_authenticated_peer[client] = list()
        g_list_authenticated_peer.append(client)
    
g_former_idx = {
                0:-1,
                1:0,
                2:1,
                3:2,
                6:3,
                4:3,
                5:4,
                }


def do_login_asyn():
    global g_map_logining_peer
    global g_map_authenticated_peer
    global g_list_authenticated_peer
    #�ĳ��첽��
    for client in g_map_logining_peer.keys():
        client.setblocking(False)
        
    for client in g_map_logining_peer.keys():
        try:
            state = g_map_logining_peer[client][1]
            if state == -1:
                #print "recv -1"
                recvstr = client.recv(1024)
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("1 recv protocol ver")
            
            elif state == 0:
                #login
                #print "start login", g_map_logining_peer[client][0]
                
                loginReq = SLoginReq()
                loginReq.type = E_Login_MAC_ONLY
                loginReq.account = "" 
                loginReq.pwd = ""
                loginReq.mac = g_map_logining_peer[client][0]
                
                client.send(getSendbuf(C_2_S_Login_Req, loginReq)[0])
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("2 send C_2_S_Login_Req")

            elif state == 1:
                #print "recv 1"
                recvstr = client.recv(1024)
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("3 recv C_2_S_Login_Rsp")

            elif state == 2:
                #������Ϸ
                enterReq = SEnterReq()
                client.send(getSendbuf(C_2_S_Enter_Req, enterReq)[0])
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("4 send  C_2_S_Enter_Req")
                
            elif state == 3:
                #print "recv 3"
                recvstr = client.recv(1024*100)
                #���,�����ʾ�����򴴽�
                enterRsp, totalLen, msgid = getStruct(recvstr)
                #print enterRsp                
                if enterRsp.errcode == 0:
                    add_login_step("5.1 recv  C_2_S_Enter_Rsp ok")
                    g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                    g_map_logining_peer[client][1] = 6
                elif enterRsp.errcode == 2:
                    add_login_step("5.2 recv  C_2_S_Enter_Rsp error")
                    g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                    g_map_logining_peer[client][1] = 99
                elif enterRsp.errcode == 1:
                    add_login_step("5.3 recv  C_2_S_Enter_Rsp need create role")                    
                    g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                    g_map_logining_peer[client][1] = state + 1
                   
            elif state == 4:
                #print "create role ", g_map_logining_peer[client][0]
                createReq = SCreateReq()
                createReq.rolename = "aa"+g_map_logining_peer[client][0]
                createReq.professionId = 100001
                client.send(getSendbuf(C_2_S_Create_Req, createReq)[0])
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("6 send  C_2_S_Create_Req")                    
            elif state == 5:
                #print "recv 5"
                recvstr = client.recv(1024)
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("7 recv  C_2_S_Create_Rsp")                    
            elif state == 6:
                #print "send SLoadFinishedReq"
                loadFinishedReq = SLoadFinishedReq()
                client.send(getSendbuf(C_2_S_LoadFinished_Req, loadFinishedReq)[0])
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                add_login_step("8 send  C_2_S_LoadFinished_Req")                    
            elif state == 7:
                #print "recv 7"
                recvstr = client.recv(1024)
                g_map_logining_peer[client][2] = g_map_logining_peer[client][1]
                g_map_logining_peer[client][1] = state + 1
                #del g_map_logining_peer[client]
                g_map_authenticated_peer[client] = list()
                g_list_authenticated_peer.append(client)
                add_login_step("9 recv  C_2_S_LoadFinished_Rsp")                    
                
        except socket.error,e :
            print e
            #print "EXceptions"
            #g_map_logining_peer[client][1] = g_map_logining_peer[client][2]
            continue
    
def run(validCount):    
    """global g_map_authenticated_peer
    for client in g_map_authenticated_peer.keys():
        sendlist = g_map_authenticated_peer[client]
        client.send((build_SMovetoReq_str(random.randrange(200, 500, 1), random.randrange(200, 300, 1))))
        recvstr = client.recv(1024)"""
    #print "runing"
    global g_test_count
    global g_list_authenticated_peer
    i=0
    run_count = 0
    temp_authenticated_peer = []
    for client in g_list_authenticated_peer:
        i = i+1
        if len(g_list_authenticated_peer) > i + validCount:
            temp_authenticated_peer.append(client)
        else: 
            try:
                """if g_test_count == 0:
                    g_test_count = 2
                    print "send iap", build_SIapCommitReceiptReq(3, "abc")
                    client.send(build_SIapCommitReceiptReq(3, "abc"))"""
                movetoReq = SMovetoReq()
                movetoReq.x = random.randrange(0, 1280, 1)
                movetoReq.y = random.randrange(0, 320, 1)
                
                sendbuf,l = getSendbuf(C_2_S_Moveto_Req, movetoReq)
                client.send(sendbuf)
                #print "send l ", l
                recvstr = client.recv(1024)
                run_count = run_count+1
                temp_authenticated_peer.append(client)
            except socket.error, e:
                print e
                if e[0] == 10035:
                    temp_authenticated_peer.append(client)

                #raise ValueError, 'nvalid argument'
    g_list_authenticated_peer = temp_authenticated_peer
                
    print "this loop run count ",run_count
    

        
g_test_count = 0        

SYNC_RUN = 1
ASYNC_RUN = 2
g_run_syn = ASYNC_RUN

def main():
    random.seed(time.time())
    generate_mac(1000, "3test")
    start_connection()
    time.sleep(2)
    global g_list_authenticated_peer
    if g_run_syn == ASYNC_RUN:
        #i=0
        while 1:
        #for i in range(1,10000):
            print "start send move,connections count ",len(g_list_authenticated_peer)
            print datetime.now()
            do_login_asyn()
            run(10)
            print datetime.now()
            time.sleep(1)
            print_login_step()
            #i = i+1
    elif g_run_syn == SYNC_RUN:
        socket.setdefaulttimeout(10)
        do_login()
        i=0
        while i<10000:
        #for i in range(1,10000):
            run(1000)
            time.sleep(2)
            i = i+1
    
main()
