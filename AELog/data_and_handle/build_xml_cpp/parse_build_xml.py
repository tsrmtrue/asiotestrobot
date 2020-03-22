#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
os.chdir(os.getcwd()) 

from ro_tlog_define import g_all_tlog_define 

def BuildMacro(macro):
    name = macro[0]
    value = macro[1]
    template = """        <macro name="%(name)s"      value="%(value)s" desc=""/>
"""
    return template%(locals())

def ParseMacro(macro):
    macro_list = list()
    pairs = macro.split("|")
    for pair in pairs:
        macro_list.append(pair.split(":"))
    # print macro_list
    return macro_list

def BuildMacrogroup(member):
    name = member[0]
    type = member[1]
    desc = member[2]
    macrogroup = member[3]
    if(macrogroup == ""):
        return ""
    template = """<macrosgroup name="%(name)s" desc="%(desc)s">
%(all_macros)s    </macrosgroup>  
    """ 
    all_macros = "".join(map(BuildMacro, ParseMacro(macrogroup)))
    return template%(locals())

def BuildEntry(member):
    template = """        <entry  name="%(name)s"          type="%(type)s"        %(size)s  %(index)s  %(defaultvalue)s    desc="%(desc)s"/>
"""
    name = member[0]
    type = member[1]
    desc = member[2]
    #[3] 是宏定义
    length = member[4]
    index = ""

    size = ""
    if (type == "string"):
        size = """size="%(length)d" """%(locals())

    defaultvalue = ""
    if(type == "int" ):
        defaultvalue = """defaultvalue="0" """
    elif(type == "string"):
        defaultvalue = """defaultvalue="NULL" """
    return template%(locals())

def BuildXmlStruct(name, all_member):
    desc = all_member[0][0]
    version = all_member[1][0]
    template = """
    %(macrogroups)s
    <struct  name="%(name)s" filter="1"  version="%(version)s" desc="%(desc)s">
%(all_entry)s    </struct>
"""
    # print name
    macrogroups = "".join(map(BuildMacrogroup, all_member[3:]))

    all_entry = "".join(map(BuildEntry, all_member[3:]))
    return template%(locals())

define_auto_writefd = open("ro_tlog_define_auto.xml",'w' )
define_auto_writefd.write("""<metalib tagsetversion="1" name="Log" version="1">
""")

for name in g_all_tlog_define.keys():
    define_auto_writefd.write(BuildXmlStruct(name, g_all_tlog_define[name]))
define_auto_writefd.write("</metalib>")
define_auto_writefd.close()


# print BuildCppStruct("ShopTradeFlow", g_all_tlog_define["ShopTradeFlow"])