# -*- coding: utf8 -*-
import fake_player 
import time
from datetime import datetime
import random

random.seed(datetime.now())

g_clients_list = []
g_client_info = [
                 #["127.0.0.1", 9999, "fvbn", "大€便€8", "passport10001", "pwd1"],
                 ]

g_dict_client_info = {}

g_robot_mac_name = [
                    ["m000001d", "肥皂甲"],
                    ["m000002d", "太乙真人"],
                    ["m000003d", "詹尼斯"],
                    ["m000004d", "怕怕听"],
                    ["m000005d", "格里弗斯"],
                    ["m000006d", "肥皂乙"],
                    ["m000007d", "大使"],
                    ["m000008d", "龙之剑2"],
                    ["m000009d", "虎贲军"],
                    ["m000010d", "花生"],
                    ["m000011d", "打死奥拓"],
                    ["m000012d", "帮我起个名儿"],
                    ["m000013d", "梅山猪"],
                    ["m000014d", "scotty"],
                    ["m000015d", "曹小焕"],
                    ["m000016d", "我叫马桶"],
                    ["m000017d", "鲍尔默"],
                    ["m000018d", "kingAthur"],
                    ["m000019d", "冷宇"],
                    ["m000020d", "胡成敏"],
                    ["m000021d", "龙国寺"],
                    ["m000022d", "刘老爷"],
                    ["m000023d", "丁香"],
                    ["m000024d", "史迪威"],
                    ["m000025d", "任志强"],
                    ["m000026d", "潘石屹"],
                    ["m000027d", "李大嘴"],
                    ["m000028d", "泸州老杨"],
                    ["m000029d", "撕内裤"],
                    ["m000030d", "欧阳多娜"],
                    ["m000031d", "吃串串"],
                    ["m000032d", "个itv莫"],
                    ["m000033d", "是哇性格"],
                    ["m000034d", "李洪涛"],
                    ["m000035d", "大掌柜"],
                    ["m000036d", "魔风"],
                    ["m000037d", "崔健"],
                    ["m000038d", "帕伽索斯"],
                    ["m000039d", "太阳，在哪"],
                    ["m000040d", "门斗全"],
                    ["m000041d", "赌一回"],
                    ["m000042d", "马姗姗"],
                    ["m000043d", "小吕子"],
                    ["m000044d", "小王京"],
                    ["m000045d", "认真"],
                    ["m000046d", "黑非洲"],
                    ["m000047d", "永罪"],
                    ["m000048d", "无极也"],
                    ["m000049d", "女性神"],
                    ["m000050d", "马甲肥皂"],
                    ["m000051d", "高大上猛男"],
                    ["m000052d", "十块一斤要吗"],
                    ["m000053d", "东方不胜"],
                    ["m000054d", "t99"],
                    ["m000055d", "我走了"],
                    ["m000056d", "四百只狗"],
                    ["m000057d", "好一块肥皂"],
                    ["m000058d", "捡"],
                    ["m000059d", "王正恩"],
                    ["m000060d", "林志炫"],
                    ["m000061d", "求包养"],
                    ["m000062d", "大法王￥"],
                    ["m000063d", "哈利波特大"],
                    ["m000064d", "乔治白"],
                    ["m000065d", "金三世"],
                    ["m000066d", "膏蟹砂锅粥"],
                    ["m000067d", "瓜子甜"],
                    ["m000068d", "雷克杀死"],
                    ["m000069d", "栾英杰"],
                    ["m000070d", "王小胖"],
                    ["m000071d", "张鸟人"],
                    ["m000072d", "无根道人"],
                    ["m000073d", "清虚长老"],
                    ["m000074d", "萨菲螺丝"],
                    ["m000075d", "克劳狄王"],
                    ["m000076d", "尼禄敏"],
                    ["m000077d", "斯巴达克王"],
                    ["m000078d", "kof"],
                    ["m000079d", "塞维鲁李"],
                    ["m000080d", "吴大维"],
                    ["m000081d", "奥古斯都"],
                    ["m000082d", "愤怒的乔治"],
                    ["m000083d", "山本河本"],
                    ["m000084d", "混世魔王毛"],
                    ["m000085d", "五级大火球"],
                    ["m000086d", "杀死比尔"],
                    ["m000087d", "赤木河蟹"],
                    ["m000088d", "夹脚拖鞋"],
                    ["m000089d", "汉尼拔"],
                    ["m000090d", "刷西班牙"],
                    ["m000091d", "大喷头"],
                    ["m000092d", "戴克里先"],
                    ["m000093d", "君士坦提乌斯"],
                    ["m000094d", "马克西米安"],
                    ["m000095d", "哈德良"],
                    ["m000096d", "图拉真"],
                    ["m000097d", "minerva"],
                    ["m000098d", "绝地高达"],
                    ["m000099d", "卡拉卡拉"],
]

g_player_name = []
for robot in g_robot_mac_name:
     g_player_name.append(robot[1])


def create_client_info(c):
    global g_client_info
    global g_robot_mac_name
    global g_dict_client_info
    if c > len(g_robot_mac_name):
        c = len(g_robot_mac_name)
    for i in range(c):
        #ip = "192.168.1.32"
        ip = "192.168.1.32"
        port = 8018
        info = [ip, port, g_robot_mac_name[i][0], g_robot_mac_name[i][1], "passport100%d"%(i), "pwd1"]
        g_client_info.append(info)
        g_dict_client_info[g_robot_mac_name[i][1]] = info
    

g_dict_current_online = {}

def random_create_client():
    global g_dict_client_info
    global g_dict_current_online
    global g_player_name
    global g_total_player_limit
    if len(g_dict_current_online.keys()) >= g_total_player_limit:
        return 
    current_role_list = g_dict_current_online.keys()
    left_role_list = list(set(g_player_name) - set(current_role_list))
    left_count = len(left_role_list)
    if left_count == 0:
        return 
    chosenOne = int(random.random() * 100) % left_count
    print "the chosenOne is ", chosenOne, "  ", left_role_list[chosenOne]
    print g_dict_client_info
    info = g_dict_client_info[left_role_list[chosenOne]]
    
    ip = info[0]
    port = info[1]
    mac = info[2]
    rolename = info[3]
    passport = info[4]
    pwd = info[5]
    c = fake_player.LJFakePlayer(ip, port, mac, rolename)
    c.initPassport(passport, pwd)
    g_dict_current_online[rolename] = c
    
def random_close_client():
    global g_dict_current_online
    for rolename in g_dict_current_online.keys():
        c = g_dict_current_online[rolename]
        if c.getLiveTime()>60*60*2:
            #在线2小时以上，考虑换人
            c.close()
            print "close client, ", rolename
            try:
                del g_dict_current_online[rolename]
            except:
                pass
            return
        
        

g_create_player_time = datetime.now()
    
def run_all():
    global g_dict_current_online
    temp_dict = {}
    for k in g_dict_current_online.keys():
        c = g_dict_current_online[k]
        if c.run():
            #print "c.run"
            temp_dict[c.new_rolename] = c
        else:
            print c.lastErrcode
            print c.ip,c.port
            c.close()
    g_dict_current_online = temp_dict
    #print "run valid client ", len(temp_list)

def loop():
    global g_create_player_time
    while(1):
        if (datetime.now() - g_create_player_time).total_seconds() > 2:
            g_create_player_time = datetime.now()
            random_create_client()
            random_close_client()
        run_all()
        time.sleep(0.1)
        
def close_all_client():
    global g_dict_current_online
    for k in g_dict_current_online.keys():
        c = g_dict_current_online[k]
        c.close()

create_client_info(100)
g_total_player_limit = 1
print g_client_info
try:
    loop()
except KeyboardInterrupt :
    print "catch ctrl c"
close_all_client()

print "all ok"