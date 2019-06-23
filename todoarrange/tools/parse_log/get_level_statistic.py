# -*- coding: gbk -*-
from parse_log import *
import sys
sys.path.append('../')
import global_path
sys.path.append(global_path.log_from_db_path)
import os
from datetime import *
g_level_dict = {}

def add_level_id(day, id, level):
    global g_level_dict
    if g_level_dict.get(day, None) == None:
        g_level_dict[day]={level:[id,]}
    elif g_level_dict[day].get(level, None) == None:
        g_level_dict[day][level] = [id, ]
    else:
        g_level_dict[day][level].append(id)

def get_level_from_list(day, rs):
    for r in rs:
        add_level_id(day, r[0], r[1])

def get_level_from_file(file):
    exec """import %(file)s"""%(locals())
    exec """rs=%(file)s.id_level_list"""%(locals())
    _l = string.split(file, "_")
    
    day = "%s_%s_%s"%(_l[1], _l[2], _l[3])
    if len(_l) >= 6:
        day = "%s_%s_%s_%s_%s"%(_l[1], _l[2], _l[3], _l[4], _l[5])
    get_level_from_list(day, rs)

def parse_files(file_path):
    global g_level_dict
    del g_level_dict
    g_level_dict = {}
    l = os.listdir(file_path)
    for f in sorted(l):
        filename,ext = string.split(f, ".")
        filenamecheck = string.split(filename, "_")
        if ext=="py" and filenamecheck[0] == "level" and len(filenamecheck)>=4:
            get_level_from_file(filename)

parse_files(global_path.log_from_db_path)
print g_level_dict.keys()