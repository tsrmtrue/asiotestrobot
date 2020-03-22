#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
os.chdir(os.getcwd()) 

from ro_tlog_define import g_all_tlog_define 

def BuildMemberRow(member):
    template = """     `%(member_name)s` %(mysql_type)s %(default)s
"""
    member_name = member[0]
    type = member[1]

    default = ""

    if (type == "string"):
        mysql_type = "varchar(768)"
        default = " NOT NULL DEFAULT ''"
    elif(type == "int" ):
        mysql_type = "int(11)"
        default = " NOT NULL DEFAULT 0 "
    elif(type in [ "bigint",'int64'] ):
        mysql_type = "bigint(20)"
        default = " NOT NULL DEFAULT 0 "
    elif(type in ["biguint",'uint64'] ):
        mysql_type = "bigint(20) unsigned"
        default = " NOT NULL DEFAULT 0 "
    elif(type == "datetime" ):
        mysql_type = "datetime "
        default = " NOT NULL DEFAULT CURRENT_TIMESTAMP "
    elif(type == "float" ):
        mysql_type = "float(5,2)"
        default = " NOT NULL DEFAULT 0 "
    else:
        print "unknown type ", type, member[0].decode('utf-8')
        raise NameError

    return template%(locals())

def BuildMemberName(member):
    template = """ ["%(member_name)s", "%(type)s"] """
    member_name = member[0]
    type = member[1]

    return template%(locals())

def GetIndex(all_member):
    need_index = [ 'vopenid']#'vRoleName','dtEventTime',  'vroleid',  
    real_index = []
    for member in all_member:
        member_name = member[0]
        if member_name in need_index:
            real_index.append(member_name)
    return real_index


def BuildCreateTable(name, all_member):
    desc = all_member[0][0]
    version = all_member[1][0]
    template = """
g_dict_create_table["%(name)s"] = \"\"\"
CREATE TABLE IF NOT EXISTS  `%(name)s`  (
%(member_rows)s
%(indexs)s
) ROW_FORMAT=DYNAMIC ENGINE=InnoDB DEFAULT CHARSET=utf8
\"\"\"

g_dict_table_colums["%(name)s"] = [%(member_name_lists)s]
"""
    # print name
    member_rows = ",".join(map(BuildMemberRow, all_member[3:]))
    real_index = GetIndex(all_member[3:])
    indexs = ""
    if len(real_index) > 0:
        indexs = ','.join(real_index)
        indexs = ",INDEX(" + indexs +")"

    member_name_lists = ",".join(map(BuildMemberName, all_member[3:]))
    return template%(locals())



define_mysql_writefd = open("../tlog-tools-easy/ro_tlog_mysql.py",'w' )
define_mysql_writefd.write("""#!/usr/bin/python
# -*- coding: utf-8 -*-

g_dict_create_table = {}

g_dict_table_colums = {}
""")

for name in g_all_tlog_define.keys():
    define_mysql_writefd.write(BuildCreateTable(name, g_all_tlog_define[name]))
define_mysql_writefd.close()


# print BuildCppStruct("ShopTradeFlow", g_all_tlog_define["ShopTradeFlow"])