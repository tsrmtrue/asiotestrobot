#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
os.chdir(os.getcwd()) 

from ro_tlog_define import g_all_tlog_define 

g_total_names={}

def ParseTable(table_name, d):
    global g_total_names
    for p in d:
        if len(p) >=5 :
            name = p[0]
            type = p[1] 
            paras = g_total_names.get(name, None)
            if paras <> None and paras[1] <> p[1]:
                print table_name , p
                raise TypeError
            g_total_names[name] = p

for k in g_all_tlog_define.keys():
    ParseTable(k, g_all_tlog_define[k][3:])



define_writefd = open("ro_tlog_kudu_table",'w' )
for k, v in g_total_names.items():
    define_writefd.write(v[0])
    define_writefd.write(",  ")
    define_writefd.write(v[1])
    define_writefd.write("\n")
    
define_writefd.close()
