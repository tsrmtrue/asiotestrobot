# -*- coding: utf-8 -*-

#!/usr/bin/python3
import os
import time
import datetime
import pymongo
from ro_tlog_define import g_all_tlog_define



#获取最新字段集合
def get_fields():
    fileds = {}
    for x in g_all_tlog_define:
        filed = []
        for y in g_all_tlog_define[x][3:]:
            filed.append(y[0].lower())
        fileds[x] = filed
    return fileds

#获取tlog文件中的内容并拼接
def get_tlog_contents(file_name):
    lists = []
    fileds = get_fields()
    if '.tlog' not in file_name:
        return 
    # print(file)
    try: 
        f = open( file_name,'r',encoding='utf-8')
        for line in f:
            if '|' not in line:
                #print(line)
                continue
            line = line.replace('\n','').split('|')
            try:
                # tlog库字段可以添加，但是不能删除或者修改，所以新的 日志定义 字段如果增多，匹配老的日志需要减去新加的字段
                length = len(line) - 1
                # print("record length is " , length)
                # print(line[0])
                # print(fileds[line[0]])
                value = dict(zip(fileds[line[0]][:length],line[1:]))
            except Exception as e :
                print(file)
                print(fileds[line[0]])
                print(line)
                print(e)
                #print(value)
                #raise ZeroDivisionError
                continue
            value['_eventname'] = line[0]
            lists.append(value)
        f.close()
    except Exception as e :
        print( "unhandled file " + file)

    insert_mongo(lists)

g_count = 0
#批量插入mongodb
def insert_mongo(value):
    global g_count
    # print("do send")
    print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
    myclient = pymongo.MongoClient("mongodb://192.168.0.102:27017/")
    mydb = myclient["ro_tlog_tx_test"]
    mycol = mydb['ro_tlog']
    start = 0
    total = len(value)
    print(total)
    while start < total:
        end = start + 100000
        if end > total:
            end = total
        g_count += end - start
        mycol.insert_many(value[start:end])
        start = end
        print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))

g_log_path= "/home/root/tlog-0312-0319"

def main():
    global g_log_path
    log_path = g_log_path
    #读取已经处理名单
    finished_file_name = "finished_file"
    os.system("touch %(finished_file_name)s"%(locals()))
    finished_rfd = open(finished_file_name,'r', encoding="utf-8")
    all_finished = finished_rfd.readlines()
    finished_rfd.close()
    # print(all_finished)
    #有个bug，换行会愈来愈多
    l = []
    for finished in all_finished:
        l.append(finished.replace("\n",""))
    all_finished = l

    # print(all_finished)
    file_names = os.listdir(log_path)
    for file in file_names:
        if file in all_finished:
            continue
        #解压缩临时文件
        print(file)
        os.system("tar -xzf  %(log_path)s/%(file)s"%(locals()))
        #提交到mongodb
        get_tlog_contents(file)
        #删除解压缩临时文件
        os.system("rm -f %(file)s"%(locals()))
        #记录成处理文件
        all_finished.append(file)
    
    #保存已经处理名单
    all_filename_str = "\n".join(all_finished)
    finished_wfd = open(finished_file_name,'w')
    finished_wfd.write(all_filename_str)
    finished_wfd.close()

from datetime import datetime
print(datetime.now().isoformat())

if __name__ == '__main__':
    main()
print("total send" + str(g_count))
print(datetime.now().isoformat())
