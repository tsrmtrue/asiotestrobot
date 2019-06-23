# -*- coding: utf-8 -*-
import sys
sys.path.append('../')
from protocol_enums import *
import os
import string

g_member_idx = ['date', 'userid', 'eventid', 'tickcount', 'p1','p2','p3','p4','filename', 'fileno', 'log1', 'log2']

def get_month_by_day(day):
    dateList1 = string.split(day, "-")
    return "%s-%s"%(dateList1[0], dateList1[1])


def parse_log_file(filename, handler, zoneid):
    statinfo = os.stat(filename)
    #print "handle file "+filename+ "  size %d"%(statinfo.st_size) +"   "+zoneid
    f = open(filename, 'r')
    s = f.readline()
    global g_member_idx
    while s <> "":
        #print s
        r = string.split(s, ',')
        #print r
        if len(r) < len(g_member_idx):
            s = f.readline()
            continue
        handler(r, zoneid)
        s = f.readline()

def parse_dir(logpath, handler, zoneid):
    l = os.listdir(logpath)
    for f in sorted(l):
        parse_log_file(logpath + '/'+f, handler, zoneid)
    
def parse_all(rootPath, handler):
    l = os.listdir(rootPath)
    for f in sorted(l):
        if os.path.isdir(rootPath+'/'+f):
            parse_dir(rootPath+'/'+f, handler, f)
            break
        

def handle_no(lineOfLog, zoneid):
    pass
    
#parse_all('../../../Bin/Server/log/', handle_no)