# -*- coding: GBK -*-
#todo ����һ��ѡ��,�Ƿ�Ҫ���ɴ�tag��encoding decoding����
import string
import os
import codecs
import xml
from xml.dom import minidom
import re

default_member_attribute_value ={"name":None,
                                 "type":None,
                                 "count":0,
                                 "refer":None,
                                 }

"""exzample
    <type name="char"               size="1"           python_format="c"/>
    <include file="head.xml"/>
    <define name="MAX_NAME" value="4">

    <struct name="helloworld">
      <member name="hello" type="int"/>
    </struct>
    <protocol name="SERVER1_2_SERVER2_HELLOWORLD" value="1" struct="helloworld">
"""

g_define_map = {}
"""example
g_define_map = {"MAX_NAME":"4"}
"""

g_define_list = []
"""example
g_define_list = [('MAX_NAME', '4'),]
"""

g_type_map = {}
"""example
member1 = {"name":"hello","type":"int", "count":0,"refer":None}
struct1 = [member1,]
g_type_map = {"helloworld":struct1,}
"""

g_type_list = []
"""example
member1 = {"name":"hello","type":"int", "count":0,"refer":None}
memberlist1=[member1,]
typelist = [("heloworld", memberlist1), (...,...)]
"""
    
g_protocol_list = []
"""example
protocol1 = {"name":"SERVER1_2_SERVER2_HELLOWORLD", "value":"1", "struct":"helloworld", "assignment":"0L"}
g_protocol_list = [protocol1, ]
"""

g_protocol_list_list = []
"""example
g_protocol_list_list = [["SERVER1_2_SERVER2_HELLOWORLD", "1", "helloworld"],]
"""

g_struct_assignment = {}
"""example
g_struct_assignment = {"heloworld":4, }
"""

g_file_path = ""
"""example
g_file_path = 'c:\ xxx\ '
"""

g_include_files_map = {}
"""example
g_include_files_map = {"head.xml":1,}
"""

g_datatype_map = {}
"""example
datatype1 = ("char","1","c")
g_datatype_map = {"char":datatype1,}
"""

g_datatype_lst = []
"""example
g_datatype_lst = [("char","1","c"),]
"""

g_encode_fun_nam = {
                    'c':'addChar',
                    'b':'addChar',
                    'B':'addByte',
                    'h':'addShort',
                    'H':'addWord',
                    'i':'addInt',
                    'I':'addDword',
                    'l':'addInt',
                    'L':'addDword',
                    'q':'addInt64',
                    'Q':'addUint64',
                    'f':'addFloat',
                    'd':'addDouble',
                    's':'addString',
                    }

g_decode_fun_nam = {
                    'c':'getChar',
                    'b':'getChar',
                    'B':'getByte',
                    'h':'getShort',
                    'H':'getWord',
                    'i':'getInt',
                    'I':'getDword',
                    'l':'getInt',
                    'L':'getDword',
                    'q':'getInt64',
                    'Q':'getUint64',
                    'f':'getFloat',
                    'd':'getDouble',
                    's':'getString',
                    }

g_pad_size = {
              1:'0B',
              2:'0H',
              4:'0L',
              8:'0Q'}

def fun_test_print_all():
    print "g_define_map"
    print  g_define_map 

    print "g_define_list"
    print g_define_list

    print "g_type_map"
    print g_type_map

    print "g_type_list"
    print g_type_list

    print "g_protocol_list"
    print g_protocol_list

    print "g_protocol_list_list"
    print g_protocol_list_list
    
    print "g_struct_assignment"
    print g_struct_assignment
    
    print "g_file_path"
    print g_file_path

    print "g_include_files_map" 
    print g_include_files_map 

    print "g_datatype_map"
    print g_datatype_map
     
    print "g_datatype_lst" 
    print g_datatype_lst 
    
def fun_parseProtocolXml_UTF8(filename_utf8):
    dom = minidom.parse(filename_utf8)
    fun_parseProtocolXml_root(dom)
    
    
def fun_parseProtocolXml_GBK(filename):
    file_string = file(filename,'r').read()
    file_string = string.replace(file_string, 'encoding=\"gbk\"', 'encoding=\"utf-8\"')
    #print file_string
    file_string = unicode(file_string,'gbk').encode('utf-8')
    dom = minidom.parseString(file_string)
    fun_parseProtocolXml_root(dom)

def fun_parseProtocolXml_root(dom):
    datarows = dom.getElementsByTagName("collection")
    for root in datarows:
        #����include
        fun_parseProtocolXml_includes(root)
        #����typesize
        fun_parseProtocolXml_typesize(root)
        #����defines
        fun_parseProtocolXml_defines(root)
        #����structs
        fun_parseProtocolXml_structs(root)
        #����protocols
        fun_parseProtocolXml_protocols(root)
        return#ֻ��һ��root

def fun_parseProtocolXml_includes(element):
    #include �Ĵ����ݹ����
    datarows = element.getElementsByTagName("includes")
    for rowElement in datarows:
        includeElements = rowElement.getElementsByTagName("include")
        for includeE in includeElements:
            filename = includeE.getAttribute("file")
            if g_include_files_map.get(filename, None) <> None:
                g_include_files_map[filename] = g_include_files_map[filename] + 1
            else:
                g_include_files_map[filename] = 1
                fun_parseProtocolXml_GBK(g_file_path + filename)
        return#ֻ��һ��includesԪ��

def fun_parseProtocolXml_typesize(element):
    datarows = element.getElementsByTagName("typesize")
    for rowElement in datarows:
        typeElements = rowElement.getElementsByTagName("type")
        for TE in typeElements:
            name = TE.getAttribute("name")
            size = TE.getAttribute("size")
            python_format = TE.getAttribute("python_format")
            g_datatype_map[name] = (name,size,python_format)
            g_datatype_lst.append((name,size,python_format))
        return

def fun_parseProtocolXml_defines(element):
    datarows = element.getElementsByTagName("defines")
    for rowElement in datarows:
        defineElements = rowElement.getElementsByTagName("define")
        for DE in defineElements:
            name = DE.getAttribute("name")
            value = DE.getAttribute("value")
            if g_define_map.get(name,None) <> None:
                raise NameError(name + "redifinition")
            g_define_map[name] = value
            g_define_list.append((name, value))
        return 

def fun_parseProtocolXml_structs(element):
    datarows = element.getElementsByTagName("structs")
    for rowElement in datarows:
        structElements = rowElement.getElementsByTagName("struct")
        for SE in structElements:
            structname = SE.getAttribute("name")
            memberElements = SE.getElementsByTagName("member")
            memberlist = []
            tempcheck = []
            for ME in memberElements:
                #���û�и����ԣ����ص��ǿ��ַ���""������ǿ���е�����Ӧ���Ȳ�ѯ�Ƿ����
                name = ME.getAttribute("name") 
                type = ME.getAttribute("type")
                count = ME.getAttribute("count")
                refer = ME.getAttribute("refer")
                if type == "string" and count == "":
                    raise TypeError("string count empty")
                member ={}
                member["name"] = name
                member["type"] = type
                member["count"] = count
                member['refer'] = refer
                if member["name"] in tempcheck:
                    raise NameError(member["name"] + " redundant name")
                tempcheck.append(member["name"])
                memberlist.append(member)
            g_type_map[structname] = memberlist
            g_type_list.append((structname, memberlist))
        return


def fun_parseProtocolXml_protocols(element):
    datarows = element.getElementsByTagName("protocols")
    for rowElement in datarows:
        protocolElements = rowElement.getElementsByTagName("protocol")
        for PE in protocolElements:
            name = PE.getAttribute("name")
            value = PE.getAttribute("value")
            struct = PE.getAttribute("struct")
            protocol = {}
            protocol["name"] = name
            protocol["value"]   = value
            protocol["struct"] = struct
            g_protocol_list.append(protocol)
            g_protocol_list_list.append([name,value,struct])
        return
    
def searchBiggestSizeinType(type, count2, size):
    if count2.isdigit():
        num2 = int(count2)
    else :
        if count2 in g_define_map.keys():
            num2 = int(g_define_map[count2])
        else :
            num2 = 1
    if fun_IsBaseType(type):
        num = int(g_datatype_map[type][1])
        if num > size:size = num
    elif fun_IsDefinedType(type):
        typestruct = g_type_map[type]
        i = 0
        string = ""
        while i < num2:
            i = i +1
            for item in typestruct:
                size = searchBiggestSizeinType(item["type"], item["count"], size)
    else:
        raise TypeError(type)
    return size

def size2AlignPad(size):
    pad = g_pad_size.get(size,None)
    if None == pad:
        raise TypeError(size)
    return pad
        
def fun_addAssignmentAll():
    #Ϊ���еĽṹ ������
    global g_struct_assignment
    for type in g_type_map.keys():
        biggestsize = searchBiggestSizeinType(type, "1", 1)
        if biggestsize == 5:
            pass
        g_struct_assignment[type] = size2AlignPad(biggestsize)

def fun_addAssignment():
    #����protocolidѰ����Ҫ����Ľṹ
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        struct = protocol["struct"]
        biggestsize = searchBiggestSizeinType(struct, "1", 1)
        if biggestsize == 5:
            print name 
        protocol["assignment"] = size2AlignPad(biggestsize)

def type2defaultValue(type):
    count=1
    strtype=""
    if None != re.match("\d+", type):
        lst = re.findall("\d+|\w", type)
        count = int(lst[0])
        strtype=lst[1]        
    else:
        strtype=type
    if count==0:
        return ""
    if strtype=="s":
        return "\"\","
    retstr=""
    for i in range(0,count):
        retstr += "0,"
    return retstr
    
def type2PackFormatString(type, count2, assignment):
    #����pack������ʹ�õ�format����
    if count2.isdigit():
        num = int(count2)
    else :
        if count2 in g_define_map.keys():
            num = int(g_define_map[count2])
        else :
            num = 1
    if fun_IsBaseType(type):
        padtype = g_datatype_map[type][2]
        if num > 1 or padtype=="s":
            return "%d%s"%(num,padtype)     
        else:
            return "%s"%(padtype)
    elif fun_IsDefinedType(type):
        typestruct = g_type_map[type]
        i = 0
        string = ""
        while i < num:
            string += assignment
            i = i +1
            for item in typestruct:
                string += type2PackFormatString(item["type"], item["count"], assignment)
        return string + assignment
    raise TypeError(type)

def fun_buildFmtAllandPure(filename):
    """
    ��ӡ����ֻ��ӡ������ �ṹ ��fmt
    """
    w = open(filename, "w")
    w.writelines("MessageFmt = {\n")
    for type in g_struct_assignment.keys():
        string = type2PackFormatString(type, "1", g_struct_assignment[type])
        w.writelines("\"" + type + "\":\"" + string + "\",\n") 
    w.writelines("}")
    w.close()

def fun_buildFmt(filename):
    """
    ����Э��ţ���ӡ��Э���Ӧ�ṹ��fmt
    """
    w = open(filename, "w")
    w.writelines("MessageFmt = {\n")
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        struct = protocol["struct"]
        string = type2PackFormatString(struct, "1", protocol["assignment"])
        w.writelines("\"" + struct + "\":\"" + string + "\",\n")
        w.writelines("\"" + name + "\":\"" + string + "\",\n")
        #w.writelines(string)
    w.writelines("\"NULL\":\"NULL\"}\n")
    #Э��id��pkg������ӳ��
    w.writelines("Messageid2pkg = {\n")
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        struct = protocol["struct"]
        w.writelines("\"" + name + "\":\"" + struct + "\",\n")
        #w.writelines(string)
    w.writelines("\"NULL\":\"NULL\"}\n")
    #Э��pkg��ʽ
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        struct = protocol["struct"]
        string = type2PackFormatString(struct, "1", protocol["assignment"])
        w.writelines(struct + " = \"" + string + "\"\n")
    #Э��id��
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        w.writelines("%s = %s\n"%(name, value))
    #Э��Ĭ�����ֵ    
    for protocol in g_protocol_list:
        name = protocol["name"]
        value = protocol["value"]
        struct = protocol["struct"]
        string = type2PackFormatString(struct, "1", protocol["assignment"])
        lst = re.findall("\d*\w", string)
        dvalue = ""
        for l in lst:
            dvalue += type2defaultValue(l)
        #�ַ�����ʽ
        w.writelines("DV_%s = \"\"\"%s\"\"\"\n"%(struct, dvalue))
        #tuple��ʽ
        w.writelines("DV_T_%s = (%s)\n"%(struct, dvalue))
    w.close()

def fun_IsDefinedType(type):
    return type in g_type_map.keys()
            
def fun_IsBaseType(type):
    return type in g_datatype_map.keys()

def fun_getString2Digital(countstring):
    num = 0
#    if countstring == ""
#        num = 0;
    if countstring.isdigit():
        num = int(countstring)
    else :
        if countstring in g_define_map.keys():
            num = int(g_define_map[countstring])
        else :
            num = 0
    return num

def fun_buildStructString(typestruct):
    string = ""
    for item in typestruct:
        num = fun_getString2Digital(item["count"])
            
        if fun_IsBaseType(item["type"]):
            if (not num == 0):
                #���Ҫ��byte�������飬���������ô����
                if item["type"] == "string":
                #�����byte���鵱���ַ���������ô����
                #if item["type"] == "byte" or item["type"] == "string":
                    string += item["name"]
                    string += ","
                else:
                    string += "%s[%d]"%(item["name"],num)    
                    string += ","                                            
            else:
                string += item["name"]
                string += ","    
        elif fun_IsDefinedType(item["type"]):
            if not num == 0:
                string += "%s=%s[%d]"%(item["name"],item["type"],num)
                string += ","
            else:
                string += "%s=%s"%(item["name"],item["type"])
                string += ","
        else:
            raise TypeError(item["type"])
    return string
            
def fun_buildPyStruct_namedlist(targetName):
    w = open(targetName, "w")
    w.writelines("import sys\n")
    w.writelines("""sys.path.append('../autotest_lib')\n""")
    w.writelines("from namedlist_Generator_lib_easy import *\n")
    for type in g_type_list:
        typename = type[0]
        typestruct = type[1]
        lst = fun_buildStructString(typestruct)
        #if lst == "":
        #    w.writelines("#%s = namedList(\"%s\", \"%s\")\n"%(typename,typename,lst))
        #else :
        w.writelines("%s = namedList(\"%s\", \"%s\")\n"%(typename,typename,lst))
            
        #if typename == "GS2PKG_ZHILIWENDA_BROADCAST_QUESTION_RPT":
        #    #print"%s len is %d"%(typename, len(typestruct))
                  
    w.close()
            
def fun_writeNline(indentTime, line):
    #��ӡ�����������ĸ���������ò��û�б��õ�
    stringt = ""
    for i in range(0, indentTime):
        stringt += "    "
    stringt += line
    stringt += "\n"
    return  stringt

def fun_type2EncodeFun(type):
    if fun_IsBaseType(type):
        return g_encode_fun_nam[g_datatype_map[type][2]]
    elif fun_IsDefinedType(type):
        return "encode_%s"%(type)
    else:
        raise TypeError(type)
    return

def fun_type2DecodeFun(type):
    if fun_IsBaseType(type):
        return g_decode_fun_nam[g_datatype_map[type][2]]
    elif fun_IsDefinedType(type):
        return "decode_%s"%(type)
    else:
        raise TypeError(type)
    return

#todo bfun_type2DecodeFun('buf')����ʲô����������Ҫ�ĵ�
def fun_buildEncodeStringFromItem(item, n):
    #����tag��֧ѡ��
    #if need_tag:
    #    tag_prediction = "    if has_tag(st, %(n)d):\n    "
    #else:
    #    tag_prediction = ""
    fun = fun_type2EncodeFun(item['type'])
    name = item['name']
    count = item['count']
    if item['refer'] <> "":
        count = "st."+item['refer']
    
    if fun_IsDefinedType(item['type']):
        idx_ptr = "[i]"
        if count == "":
            idx_ptr = ""
            count = "1"
        template = """
    for i in range(%(count)s):
        _tempstr = %(fun)s(st.%(name)s%(idx_ptr)s)
        str += _tempstr

"""     
        return  template%(locals())
    if item['count'] <> "":
        fun = fun_type2EncodeFun(item['type'])
        name = item['name']
        if item['type'] == 'byte':
            fun = fun_type2EncodeFun('buf')
            return "    str += %(fun)s(st.%(name)s, %(count)s)\n"%locals()
#        if not fun_IsBaseType(item['type']):
        if item["type"] in ('string', 'char'):
            fun = "addString"
            return "    str += %(fun)s(st.%(name)s)\n"%locals()
        return "    for i in range(%(count)s):\n        str += %(fun)s(st.%(name)s[i])\n"%locals()
    return "    str += %(fun)s(st.%(name)s)\n"%locals()

#����tag������n��ʾ�ǵڼ�����������0��ʼ  -2011-03-01
def fun_buildDecodeStringFromItem(item, n):
    #todo ����tagѡ���֧
    #if need_tag:
    #    tag_prediction = "    if has_tag(st, %(n)d):\n    "
    #else:
    #    tag_prediction = ""
    fun = fun_type2DecodeFun(item['type'])
    name = item['name']
    count = item['count']
    if item['refer'] <> "":
        count = "st."+item['refer']
    if fun_IsDefinedType(item['type']):
        idx_ptr = "[i]"
        if count == "":
            idx_ptr=""
            count = "1"
        template = """
    for i in range(%(count)s):
        st.%(name)s%(idx_ptr)s,length = %(fun)s(buf[pos:])\n    
        pos += length

"""
        return  template%(locals())

    if item['count'] <> "":
        fun = fun_type2DecodeFun(item['type'])
        name = item['name']
        if item['type'] == 'byte':
            fun = fun_type2DecodeFun('buf')
            return "    t,length = %(fun)s(buf[pos:], %(count)s)\n    for i in range(len(t)):\n        st.%(name)s[i]=t[i]\n        pos += length\n"%locals()
#        if not fun_IsBaseType(item['type']):
        if item["type"] in ('string', 'char'):
            fun = "getString"
            return "    st.%(name)s,length = %(fun)s(buf[pos:])\n    pos += length\n"%locals()
        return "    for i in range(%(count)s):\n        st.%(name)s[i],length = %(fun)s(buf[pos:])\n        pos += length\n"%locals()
    return "    st.%(name)s,length = %(fun)s(buf[pos:])\n    pos += length\n"%locals()

def fun_buildEncodeStringFromTypestruct(typestruct, typeclass=""):
    str = ''
    i=0
    for item in typestruct:
        str += fun_buildEncodeStringFromItem(item, i)
        i += 1
    return str

def fun_buildDecodeStringFromTypestruct(typestruct, typeclass=""):
    str = ''
    i=0
    for item in typestruct:
        str += fun_buildDecodeStringFromItem(item, i)
        i += 1
    return str


def fun_buildCodingFun_namedlist(codingFunFileName, version, namedlistfilename):
    targetFileName = "%s_%s.py"%(codingFunFileName, version)
    w = open(targetFileName, "w")
    w.writelines("# -*- coding: GBK -*-\n")
    w.writelines("import sys\n")
    w.writelines("""sys.path.append('../autotest_lib')\n""")    
    w.writelines("from coder_hlp_lib import *\n")
    w.writelines("from %s import *\n"%(namedlistfilename))
    w.writelines("g_decode_fun = {}\n")    
    w.writelines("g_encode_fun = {}\n")    
    for define in g_define_list:
        w.writelines('%s = %s\n'%(define[0], define[1]))
    for protocol in g_protocol_list_list:
        w.writelines('%s = %s\n'%(protocol[0],protocol[1]))
    for type in g_type_list:
        typename = type[0]
        typestruct = type[1]
        typeclass = ""
        encode_lst = fun_buildEncodeStringFromTypestruct(typestruct,typeclass)
        #����tag������-2011-03-01
        encode_tags = ""#"    for i in range(%d):str += addByte(st._tag[i])"%(len(typestruct)/8+1)
        #todo ���ӷ�֧�жϣ�û��tag
        #if not need_tag :
        #    encode_tags = ""
        encode_fun = "\ndef encode_%s(st):\n    str=''\n%s\n%s    return str\n"%(typename,encode_tags,encode_lst)
        w.writelines(encode_fun)
        #print encode_fun

        decode_lst = fun_buildDecodeStringFromTypestruct(typestruct,typeclass)
        #����tag������-2011-03-01
        decode_tags = ""#"    for i in range(%d):\n        st._tag[i],length = getByte(buf[pos:])\n        pos += length"%(len(typestruct)/8+1)
        #todo ���ӷ�֧�жϣ�û��tag
        #if not need_tag :
        #    decode_fun = ""
        decode_fun = "\ndef decode_%s(buf):\n    st=%s()\n    pos=0\n%s\n%s    return st,pos\n"%(typename,typename,decode_tags,decode_lst)
        w.writelines(decode_fun)
        #print decode_fun
    
    for protocol in g_protocol_list_list:
        w.writelines("g_decode_fun[%s] = decode_%s\n"%(protocol[0], protocol[2]))    
        w.writelines("g_encode_fun[%s] = encode_%s\n"%(protocol[0], protocol[2]))    
    w.close()
    
    w = open("%s.py"%codingFunFileName, "w")
    realcodingFunFileName = string.split(codingFunFileName, "/")[-1]
    print "real coding funfile name is ",codingFunFileName
    w.writelines("from %s_%s import *"%(realcodingFunFileName, version))
    fun_str = """
def getEncodebufByMsgid(msgid, st):
    encode_fun = g_encode_fun.get(msgid,None)
    if encode_fun == None:
        return None
    return encode_fun(st)
def getStructByMsgid(msgid, buf):
    decode_fun = g_decode_fun.get(msgid,None)
    if decode_fun == None:
        return None,0
    return decode_fun(buf)
    
def getSendbuf(msgid, st):
    s= getEncodebufByMsgid(msgid, st)
    length = len(s)
    headbuf, headlen = EncodeMsgHead_Gate(msgid, length)
    return (headbuf+s, headlen+length)
def getStruct(buf):
    msgid, structlen, headlen = DecodeMsgHead_Gate(buf)
    if headlen == 0 or headlen+structlen>len(buf):
        return None,0,0
    st,length = getStructByMsgid(msgid, buf[headlen:headlen+structlen])
    return st, structlen+headlen, msgid
    """
    w.writelines(fun_str)
    w.close()
                

            


"""
test
"""
"""
fun_parseProtocolXml_GBK("example.xml")
fun_addAssignmentAll()
fun_addAssignment()
fun_buildFmtAllandPure("test_fmt.py")
fun_buildFmt("test_fmt2.py")
fun_buildPyStruct_namedlist("test_namedlist.py")
fun_buildCodingFun_namedlist("test_namedlist_coding.py", "0_001")
fun_test_print_all()
"""
