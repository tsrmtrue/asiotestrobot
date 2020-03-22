#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
os.chdir(os.getcwd()) 
import xlrd

"""
声明；现在excel放在config分支下,可以填绝对路径
"""
workbook = xlrd.open_workbook('../../../config/Table/Tools/Tlog/ro_tlog_define_2020_02_28v2.xlsx')

need_bracket = False

def BuildRowWithSize(row):
    tablename  = row[1]
    name  = row[2]
    type  = row[3]
    if isinstance(row[4], float):
        length  = int(row[4])
    else:
        length = 0
    desc  = row[5]
    #5 
    macros = ''
    if(len(row) >= 7):
        macros = row[6]
    global need_bracket
    # if (macros != ""):
    #     print macros
    if(tablename != ""):
        if (type == ""):
            type = "1.0"
        if (need_bracket):
            return """] \rg_all_tlog_define["%(tablename)s"] = [\r    ["%(name)s"], \n    ["%(type)s"],\n"""%(locals())
        else :
            need_bracket = True
            return """\rg_all_tlog_define["%(tablename)s"] = [\r    ["%(name)s"], \n    ["%(type)s"],\n"""%(locals())
    if(name == "" ):
        return ""
    return  """    ["%(name)s", "%(type)s", "%(desc)s", "%(macros)s", %(length)d], \r"""%(locals())

def BuildRow(row):
    tablename  = row[1]
    name  = row[2]
    type  = row[3]
    length = 768
    desc  = row[4]
    #5 
    macros = ''
    if(len(row) >= 7):
        macros = row[6]
    global need_bracket
    # if (macros != ""):
    #     print macros
    if(tablename != ""):
        if (type == ""):
            type = "1.0"
        if (need_bracket) :
            return """] \rg_all_tlog_define["%(tablename)s"] = [\r    ["%(name)s"], \n    ["%(type)s"],\n"""%(locals())
        else :
            need_bracket = True
            return """\rg_all_tlog_define["%(tablename)s"] = [\r    ["%(name)s"], \n    ["%(type)s"],\n"""%(locals())
    if(name == "" ):
        return ""
    return  """    ["%(name)s", "%(type)s", "%(desc)s", "%(macros)s", %(length)d], \r"""%(locals())

def BuildBySheet(define_writefd, sheet):
    print sheet.name,sheet.nrows,sheet.ncols
    for col in range(sheet.nrows):
        define_writefd.write( BuildRow(sheet.row_values(col)).encode("utf-8")  )
    define_writefd.flush()

def BuildBySheetWithSize(define_writefd, sheet):
    print sheet.name,sheet.nrows,sheet.ncols
    for col in range(sheet.nrows):
        define_writefd.write( BuildRowWithSize(sheet.row_values(col)).encode("utf-8")  )
    define_writefd.flush()


define_writefd = open("ro_tlog_define.py",'w' )
define_writefd.write("""#!/usr/bin/python
# -*- coding: utf-8 -*-
g_all_tlog_define = {}
""")
BuildBySheetWithSize(define_writefd, workbook.sheet_by_index(2))
BuildBySheet(define_writefd, workbook.sheet_by_index(3))
BuildBySheet(define_writefd, workbook.sheet_by_index(4))
BuildBySheet(define_writefd, workbook.sheet_by_index(5))
BuildBySheet(define_writefd, workbook.sheet_by_index(6))
BuildBySheet(define_writefd, workbook.sheet_by_index(7))
# BuildBySheet(define_writefd, workbook.sheet_by_index(8))
define_writefd.write("]")
define_writefd.close()




"""
./checklog -skipflag 0 -logpath /data/logplat/log/tlogd_1/test.log -charflag \| -xml novachina-log_20110511.xml -exportdir ./badlog_20110511 -gamename novachina

"""
