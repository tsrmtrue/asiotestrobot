#-*- coding:GBK -*-
"""
todo：1.给定一个建表的sql语句，生成一个c++结构，以及一个给结构赋值的宏
      2.给定一个field的list，生成一个c++结构，以及一个给定结构赋值的宏
"""
import MySQLdb
import re
import string

def get_fields(create_str):
    #s = create_str.replace('\r\n', '')
    #[field,type,(count)]
    pat = re.compile('^[ ]*[`]?(\w+)[`]?[ ]+(\w+)(\(\d+\))?', re.MULTILINE)
    result = pat.findall(create_str)
    #print result
    return result

def get_valid_fields(fields):
    templist = []
    for f in fields:
        if f[0] in ['CREATE','PRIMARY','UNIQUE','KEY','ENGINE']:
            pass
        else:
            templist.append(f)
    #print templist
    return templist

def get_valid_fields_filter(valid_fields, filter_fields):
    temp_list = []
    for vf in valid_fields:
        if vf[0] in filter_fields:
            temp_list.append(vf)
            filter_fields.remove(vf[0])
    if len(filter_fields) <> 0:
        print "not valid field(s) :", filter_fields
        return None
    return temp_list

def build_select_all_str(table_name):
    return '#define SELECT_SQL_%s_ALL \"SELECT * FROM %s  \"\n'%(table_name.upper(),table_name)

def get_field_name(field):
    return field[0]

def build_select_str(fields, table_name, operation):
    return '#define SELECT_SQL_%s_%s \"SELECT %s FROM %s  \"\n'%(table_name.upper(), operation.upper(), string.join(map(get_field_name, fields), ', '), table_name)

def get_cpp_format(field):
    if field[1] in ['blob',]:#datetime 定义为char数组，数据库里存的是字符串
        return "'%s'"
    elif g_sql_2_cpp_type[field[1]] == 'char' and get_member_count(field) <> '':
        return "'%s'"
    return "'%u'"
    

def get_update_str(field):
    field_name = field[0]
    type = get_cpp_format(field)
    return '%(field_name)s=\'%(type)s\''%(locals())


def build_update_str(fields, table_name, operation):
    #print fields
    #print map(get_update_str, fields)
    return '#define UPDATE_SQL_%s_%s \"UPDATE %s SET %s  \"\n'%(table_name.upper(), operation.upper(), table_name, string.join(map(get_update_str, fields), ', '))

def get_update_fields(field):
    if field[1] == 'blob':
        name = field[0]
        extendname = get_extend_member_name(name)
        return 'GetEscapeString((const char*)(st.%(name)s), st.%(extendname)s, poDBConn).c_str()'%(locals())
    return 'st.'+field[0]
    
def build_cpp_fields_macro(fields, table_name, operation):
    """得到cpp结构的参数列表
    """
    op = operation.upper()
    tb_name = table_name.upper()
    fields = string.join(map(get_update_fields, fields), ',')
    return "#define MACRO_STRUCT_FIELDS_%(op)s_%(tb_name)s(st,poDBConn) %(fields)s  "%(locals())

def get_field_name(field):
    return field[0]

def build_insert_str(fields, table_name, operation):
    #print fields
    #print map(get_update_str, fields)
    OP = operation.upper()
    TB_NAME = table_name.upper()
    fields_name = string.join(map(get_field_name, fields), ',')
    values = string.join(map(get_cpp_format, fields), ',')
    return '#define INSERT_SQL_%(OP)s_%(TB_NAME)s \"INSERT INTO %(table_name)s (%(fields_name)s) VALUES(%(values)s) \"\n'%(locals())
    
    
#创建cpp结构
g_sql_2_cpp_type = {
                    'bigint':'unsigned long long',
                    'varchar':'char',
                    'smallint':'unsigned short',
                    'tinyint':'unsigned char',
                    'int':'int',
                    'mediumint':'int',
                    'blob':'unsigned char',
                    'datetime':'char',
                    'timestamp':'unsigned int',
                    }
def get_member_count(field):
    if field[1] == 'varchar':
        return '[%s]'%(field[2][1:-1])
    elif field[1] == 'blob':
        return '[16384]'
    elif field[1] == 'datetime':
        return '[32]'
    return ''

def get_extend_member_name(name):
    return '_current_%s_length'%(name)

def get_extend_member(type, field):
    if type in ['blob']:
        return 'int %s;'%(get_extend_member_name(field))
    return ''


def get_member(f):
    type = g_sql_2_cpp_type[f[1]]
    if type == None:
        print 'errrrrrrrrrrrrrrrrrrrrrrror', f
    field = f[0]
    count = get_member_count(f)
    extend = get_extend_member(f[1], field)
    return '%(type)s %(field)s%(count)s;%(extend)s'%(locals())

def build_cpp_struct(valid_fields, sqlname):
    struct_template = """typedef struct %(struct_name)s
{
    %(members)s
};
"""
    struct_name = sqlname
    #print valid_fields
    #print map(get_member, valid_fields)
    members = string.join(map(get_member, valid_fields), '\n    ')
    return struct_template%(locals())


def build_convert_field(field):
    field_name = field[0]
    if field[1] in ['blob',]:#datetime 定义为char数组，数据库里存的是字符串
        extend = get_extend_member_name(field_name)
        return 'ConvRcFieldLength(pRC, _i,&st.%(extend)s);ConvRcChunk(pRC,_i++, st.%(field_name)s, sizeof(st.%(field_name)s));'%(locals())
    elif g_sql_2_cpp_type[field[1]] == 'char' and get_member_count(field) <> '':
        return 'ConvRc(pRC,_i++, st.%(field_name)s, sizeof(st.%(field_name)s));'%(locals())
    else :
        return 'ConvRc(pRC,_i++,&st.%(field_name)s,0);'%(locals())


def build_convert_macro(fields, name):
    #创建赋值的宏
    convert_template = """
#define CONVERT_RECORD_%(operation)s(pRC,st) \\
int _i = 0;\\
%(member)s

"""
    operation = name.upper()
    member = string.join(map(build_convert_field, fields), '\\\n') + '\n'
    return convert_template%(locals())

#这里的sql语句是从数据库得到的建表语句，可以是在图形界面完成建表，然后直接提取sql语句，放在这里以后，直接生成c++的结构
g_sql_map = {} #{tblname:create_table_sql}}
create_role_test_db = """
CREATE TABLE roleinfo_test_test (
  RoleId bigint(20) unsigned NOT NULL auto_increment,
  RoleName varchar(25) NOT NULL,
  PTID varchar(21) NOT NULL,
  DigitID varchar(21) NOT NULL,
  Level smallint(3) unsigned NOT NULL,
  Sex tinyint(1) unsigned NOT NULL,
  Career tinyint(1) unsigned NOT NULL,
  Hair tinyint(2) unsigned NOT NULL,
  Face tinyint(2) unsigned NOT NULL,
  Body tinyint(2) unsigned NOT NULL,
  Hand tinyint(2) unsigned NOT NULL,
  Leg tinyint(2) unsigned NOT NULL,
  Foot tinyint(2) unsigned NOT NULL,
  Helmet tinyint(2) unsigned NOT NULL,
  Mask tinyint(2) unsigned NOT NULL,
  Cloth tinyint(2) unsigned NOT NULL,
  ShoulderLeft tinyint(2) unsigned NOT NULL,
  Back tinyint(2) unsigned NOT NULL,
  Res blob NOT NULL,
  ExtPro1 blob NOT NULL,
  CreateTime datetime NOT NULL default '0000-00-00 00:00:00',
  DeleteTime datetime NOT NULL default '0000-00-00 00:00:00',
  UnDelTime datetime NOT NULL default '0000-00-00 00:00:00',
  UpdateTime datetime NOT NULL default '0000-00-00 00:00:00',
  RoleDeleted tinyint(1) default NULL,
  PRIMARY KEY  (RoleId),
  UNIQUE KEY RoleName (RoleName),
  KEY PTID (PTID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
"""
#g_sql_map['roleinfo_test_test'] = create_role_test_db

create_roleinfo = """
CREATE TABLE `roleinfo` (
  `RoleId` bigint(20) unsigned NOT NULL auto_increment,
  `RoleName` varchar(24) NOT NULL,
  `PTID` varchar(48) NOT NULL,
  `DigitID` varchar(48) NOT NULL,
  `Level` smallint(3) unsigned NOT NULL,
  `Sex` tinyint(1) unsigned NOT NULL,
  `Career` tinyint(1) unsigned NOT NULL,
  `Hair` tinyint(2) unsigned NOT NULL,
  `Face` tinyint(2) unsigned NOT NULL,
  `Body` tinyint(2) unsigned NOT NULL,
  `Hand` tinyint(2) unsigned NOT NULL,
  `Leg` tinyint(2) unsigned NOT NULL,
  `Foot` tinyint(2) unsigned NOT NULL,
  `Helmet` tinyint(2) unsigned NOT NULL,
  `Mask` tinyint(2) unsigned NOT NULL,
  `Cloth` tinyint(2) unsigned NOT NULL,
  `ShoulderLeft` tinyint(2) unsigned NOT NULL,
  `Back` tinyint(2) unsigned NOT NULL,
  `Res` blob NOT NULL,
  `ExtPro1` blob NOT NULL,
  `CreateTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `DeleteTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `UnDelTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `UpdateTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `RoleDeleted` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`RoleId`),
  UNIQUE KEY `RoleName` (`RoleName`),
  KEY `PTID` (`PTID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
"""

g_sql_map['roleinfo'] = create_roleinfo

def build_create_table_sql(create_sql, table_name):
    return '#define CREATE_TABLE_%s  '%table_name.upper() + '\"' + create_sql.replace('`', '').replace('\n', '\\\n') + '\"\n'

def build_sql_by_createsql():
    str = ''
    for table_name in g_sql_map.keys():
        valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
        str = '\n/****************************************************************************/\n'
        str += build_create_table_sql(g_sql_map[table_name], table_name)
        str += build_cpp_struct(valid_fields, 'stSELECT_'+table_name+'_ALL')
        str += build_convert_macro(valid_fields, table_name+'_selectall')
        str += build_select_all_str(table_name)
    return str

def build_select_sql_by_field_list(fieldlist, table_name, operation):
    """指定表格，还有field列表，将判断field名字是不是合法，然后生成sql语句，赋值宏，fields对应的数据结构
    operation应该是包含操作和具体的事件，比如,select_entergame,insert_newrole
    本函数生成select语句相关的"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_specified = get_valid_fields_filter(valid_fields, fieldlist)
    #print valid_fields
    str += build_cpp_struct(valid_fields_specified, 'st_'+table_name+'_'+operation)
    str += build_convert_macro(valid_fields_specified, table_name+'_'+operation)
    str += build_select_str(valid_fields_specified, table_name, operation)
    return str

def build_update_sql_by_field_list(fieldlist, table_name, operation):
    """指定表格，还有field列表，将判断field名字是不是合法，然后生成sql语句，赋值宏，fields对应的数据结构
    operation应该是包含操作和具体的事件，比如,select_entergame,insert_newrole
    本函数生成update语句相关的"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_specified = get_valid_fields_filter(valid_fields, fieldlist)
    #print  valid_fields_specified
    str += build_cpp_struct(valid_fields_specified, 'st_'+table_name+'_'+operation)
    str += build_update_str(valid_fields_specified, table_name, operation)
    str += build_cpp_fields_macro(valid_fields_specified, table_name, operation)
    return str

def build_insert_sql_by_field_list(fieldlist, table_name, operation):
    """指定表格，还有field列表，将判断field名字是不是合法，然后生成sql语句，赋值宏，fields对应的数据结构
    operation应该是包含操作和具体的事件，比如,select_entergame,insert_newrole
    本函数生成insert语句相关的"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_specified = get_valid_fields_filter(valid_fields, fieldlist)
    #print  valid_fields_specified
    str += build_cpp_struct(valid_fields_specified, 'st_'+table_name+'_'+operation)
    str += build_insert_str(valid_fields_specified, table_name, operation)
    str += build_cpp_fields_macro(valid_fields_specified, table_name, operation)#这个结构的变量表次序是一样的
    return str

def main():
    str = ''
    str += build_sql_by_createsql()
    #str += build_select_sql_by_field_list(['RoleId','RoleName','DigitID','Level','Career','Face','Body','Leg','Foot','Helmet'], 'roleinfo_test_test', 'getLogininfo')
    str += build_select_sql_by_field_list(['RoleId', 'PTID', 'DigitID', 'Level', 'Sex', 'Career', 'Hair', 'Face', 'Body', 'Hand', 'Leg', 'Foot', 'Helmet', 'Mask', 'Cloth', 'ShoulderLeft', 'Back', 'ExtPro1'], 'roleinfo','get_roleinfo')
    str += build_update_sql_by_field_list(['Level', 'Sex', 'Career', 'Hair', 'Face', 'Body', 'Hand', 'Leg', 'Foot', 'Helmet', 'Mask', 'Cloth', 'ShoulderLeft', 'Back', 'ExtPro1'], 'roleinfo','save_roleinfo')
    #test==============
    str += build_insert_sql_by_field_list(['RoleName', 'PTID', 'DigitID', 'Level', 'Sex', 'Career', 'Hair', 'Face', 'Body', 'Hand', 'Leg', 'Foot', 'Helmet', 'Mask', 'Cloth', 'ShoulderLeft', 'Back', 'CreateTime', 'UpdateTime'], 'roleinfo','new_roleinfo')
    #test==============
    
    file_template = """#ifndef DBSERVER_SQL_OPERATION_HLP_H
#define DBSERVER_SQL_OPERATION_HLP_H
/*made automatically,do NOT change manually*/

%s

#endif
"""
    w = open('sql_operation_hlp.h', 'w')
    w.write(file_template%str)
    w.close()
    
main()


