# -*- coding: utf8 -*-
import socket
import json
import time
import random
from test_client_lib import *

g_list_mac_address = list() #["mac1", "mac2"]

g_map_logining_peer = {} #{s:['mac',],}

g_map_authenticated_peer = {} #{s:['', ''],}

g_list_authenticated_peer = [] #[client,]

def generate_mac(count, prefix):
    global g_list_mac_address
    for i in range(count):
        g_list_mac_address.append("%(prefix)s%(i)d"%(locals()))
    print g_list_mac_address
        
def start_connection():
    global g_list_mac_address
    global g_map_logining_peer
    for mac in g_list_mac_address:
        client = socket.socket()
        client.connect(("192.168.1.111",9090))
        client.setblocking(True)
        print  "new client",client
        g_map_logining_peer[client] = [mac,-1]
    g_list_mac_address = []

def do_login():
    global g_map_logining_peer
    global g_map_authenticated_peer
    global g_list_authenticated_peer
    
    for client in g_map_logining_peer.keys():
        #chose protocol type 
        print "start protocol type rpt ", E_PROTOCOL_TYPE_JSON
        client.send(build_SProtocolTypeRpt_str(E_PROTOCOL_TYPE_JSON))
        recvstr = client.recv(1024)

        #login
        print "start login", g_map_logining_peer[client][0]
        client.send(build_SLoginReq_str("", g_map_logining_peer[client][0], "", 0))
        recvstr = client.recv(1024)
        #进入游戏
        client.send(build_SEnterReq_str())
        recvstr = client.recv(1024)
        #检查,如果提示创建则创建
        if recvstr.find('"errcode":2') <> -1:
            continue
        if recvstr.find('"errcode":1') <> -1:
            #登陆成功没有帐号,需要创建
            print "create role ", g_map_logining_peer[client][0]
            
            client.send(build_SCreateReq_str("aa"+g_map_logining_peer[client][0], 100001))
            recvstr = client.recv(1024)
        
        client.send((build_SLoadFinishedReq_str()))
        recvstr = client.recv(1024)
        client.setblocking(False)

        g_map_authenticated_peer[client] = list()
        g_list_authenticated_peer.append(client)
    

def do_login_asyn():
    global g_map_logining_peer
    global g_map_authenticated_peer
    global g_list_authenticated_peer
    #改成异步的
    for client in g_map_logining_peer.keys():
        client.setblocking(False)
        
    for client in g_map_logining_peer.keys():
        try:
            state = g_map_logining_peer[client][1]
            if state == -1:
                #set protocol type
                client.send(build_SProtocolTypeRpt_str(E_PROTOCOL_TYPE_JSON))
                print "set json", g_map_logining_peer[client][0]
                g_map_logining_peer[client][1] = state + 1
            elif state == 0:
                #login
                client.send(build_SLoginReq_str("", g_map_logining_peer[client][0], "", 0))
                print "start login", g_map_logining_peer[client][0]
                g_map_logining_peer[client][1] = state + 1
            elif state == 1:
                recvstr = client.recv(1024)
                g_map_logining_peer[client][1] = state + 1
            elif state == 2:
                #进入游戏
                client.send(build_SEnterReq_str())
                g_map_logining_peer[client][1] = state + 1
            elif state == 3:
                recvstr = client.recv(1024)
                #检查,如果提示创建则创建
                if recvstr.find('"errcode":0') <> -1:
                    #de登陆成功
                    g_map_logining_peer[client][1] = 6
                elif recvstr.find('"errcode":1') <> -1:
                    #登陆成功没有帐号,需要创建
                    g_map_logining_peer[client][1] = state + 1
                else :
                    g_map_logining_peer[client][1] = 99
                   
            elif state == 4:
                print "create role ", g_map_logining_peer[client][0]
                client.send(build_SCreateReq_str("aa"+g_map_logining_peer[client][0], 100001))
                g_map_logining_peer[client][1] = state + 1
            elif state == 5:
                recvstr = client.recv(1024)
                g_map_logining_peer[client][1] = state + 1
            elif state == 6:
                client.send((build_SLoadFinishedReq_str()))
                g_map_logining_peer[client][1] = state + 1
            elif state == 7:
                recvstr = client.recv(1024)
                g_map_logining_peer[client][1] = state + 1
                g_map_authenticated_peer[client] = list()
                g_list_authenticated_peer.append(client)
               
                
        except (socket.error, SystemExit):
            #print 
            continue
    
def run():    
    """global g_map_authenticated_peer
    for client in g_map_authenticated_peer.keys():
        sendlist = g_map_authenticated_peer[client]
        client.send((build_SMovetoReq_str(random.randrange(200, 500, 1), random.randrange(200, 300, 1))))
        recvstr = client.recv(1024)"""
    global g_test_count
    global g_list_authenticated_peer
    for client in g_list_authenticated_peer:
        try:
            if g_test_count == 0:
                g_test_count = 2
                print "send iap", build_SIapCommitReceiptReq(3, "abc")
                client.send(build_SIapCommitReceiptReq(3, "abc"))
            client.send((build_SMovetoReq_str(random.randrange(200, 500, 1), random.randrange(200, 300, 1))))
            recvstr = client.recv(1024)
        except (socket.error, SystemExit):
            #print 
            continue

        
g_test_count = 0        

SYNC_RUN = 1
ASYNC_RUN = 2
g_run_syn = ASYNC_RUN

def main():
    random.seed(time.time())
    generate_mac(1, "testmac")
    start_connection()
    time.sleep(2)

    if g_run_syn == ASYNC_RUN:
        for i in range(1,10000):
            do_login_asyn()
            run()
            time.sleep(1)
    elif g_run_syn == SYNC_RUN:
        socket.setdefaulttimeout(10)
        do_login()
        for i in range(1,10000):
            run()
            time.sleep(1)
    
main()