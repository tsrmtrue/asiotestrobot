#-*- coding:GBK -*-
import sys
sys.path.append('../')

"""
      1.����һ�������sql��䣬����һ��c++�ṹ���Լ�һ�����ṹ��ֵ�ĺ�
      2.����һ��field��list������һ��c++�ṹ���Լ�һ�������ṹ��ֵ�ĺ�
"""
import MySQLdb
import re
import string

def get_fields(create_str):
    #s = create_str.replace('\r\n', '')
    #[field,type,(count)]
    pat = re.compile('^[ ]*`(\w+)`[ ]+(\w+)(\(\d+\))?[ ]+(UNSIGNED)?', re.MULTILINE)
    result = pat.findall(create_str)
    print result
    return result

def get_valid_fields(fields):
    templist = []
    for f in fields:
        if f[0] in ['CREATE','PRIMARY','UNIQUE','KEY','ENGINE']:
            pass
        else:
            templist.append(f)
    #print "get valid fields"
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
        print valid_fields
        return None
    return temp_list

def build_select_all_str(table_name):
    return '#define SELECT_SQL_%s_ALL \"SELECT * FROM %s  \"\n'%(table_name.upper(),table_name)

def get_field_name(field):
    return field[0]

def get_condition(field):
    name = field[0]
    format = get_cpp_format(field)
    return "%(name)s=%(format)s"%(locals())

def get_select_struct_members(field):
    name = field[0]
    if field[1] in ['BLOB', 'CHAR', "VARCHAR"]:
        #extendname = get_extend_member_name(name)
        return '_%(name)s'%(locals())
        #return 'm_pMyConn->EscapeString((const char*)(st.%(name)s), st.%(extendname)s)'%(locals())
    return 'st.%(name)s'%(locals())

def build_select_str(needfields, byfields, table_name, operation, all=False):
    table_name = table_name.upper()
    operation = operation.upper()
    conditions = string.join(map(get_condition, byfields), " AND ")
    if len(byfields) > 0:
        conditions = "WHERE " + conditions
    structMembers = string.join(map(get_select_struct_members, byfields), ',')
    if len(byfields) > 0:
        structMembers = ", "+structMembers
    if all:
        needs = "*"
    else:
        needs = string.join(map(get_field_name, needfields), ',')
    select_template = """
#define SELECT_SQL_%(table_name)s_%(operation)s(st) "SELECT %(needs)s FROM %(table_name)s %(conditions)s"%(structMembers)s
"""
    return select_template%(locals())

def build_limit_select_str(needfields, byfields, table_name, operation, orderby, isdesc, limit, all=False):
    table_name = table_name
    operation = operation.upper()
    wherecondition = ""
    structMembers = ""
    if byfields <> None and len(byfields) > 0:
        wherecondition = string.join(map(get_condition, byfields), " AND ")
        wherecondition = "WHERE "+wherecondition
        structMembers = string.join(map(get_select_struct_members, byfields), ',')
        structMembers = ", "
    if all:
        needs = "*"
    else:
        needs = string.join(map(get_field_name, needfields), ',')
    order = "DESC"
    if not isdesc:
        order = "ASC"
    limit_str = ""
    if limit <> None and limit <> "" and limit <> "0":
        limit_str = "limit %s"%(limit)
    select_template = """
#define %(operation)s_LIMIT %(limit)s 
#define SELECT_SQL_%(table_name)s_%(operation)s(st) "SELECT %(needs)s FROM %(table_name)s %(wherecondition)s order by %(orderby)s %(order)s %(limit_str)s"%(structMembers)s
"""
    return select_template%(locals())


def get_cpp_format(field):
    #print "get cpp format"
    #print field
    #print g_sql_2_cpp_type[field[1]]
    #print get_member_count(field) 
    if field[1] in ['BLOB',]:#datetime ����Ϊchar���飬���ݿ��������ַ���
        return "'%s'"
    elif g_sql_2_cpp_type[field[1]] in ['char', ] and get_member_count(field) <> '':
        return "'%s'"
    elif field[1] in ['BIGINT',]:
        return "'%llu'"
    if field[3] == 'UNSIGNED':
        return "'%u'"
    else :
        return "'%d'"
    

def get_update_str(field):
    field_name = field[0]
    type = get_cpp_format(field)
    return '%(field_name)s=%(type)s'%(locals())


def build_update_str(updateFields, constraintFields, table_name, operation):
    #print fields
    #print map(get_update_str, fields)
    table_name = table_name.upper()
    operation = operation.upper()
    updates = string.join(map(get_update_str, updateFields), ',')
    constraints = string.join(map(get_update_str, constraintFields), ',')
    updateValues = string.join(map(get_update_fields, updateFields), ',')
    constraintValues = string.join(map(get_update_fields, constraintFields), ',')
    update_template = """
#define UPDATE_SQL_%(table_name)s_%(operation)s "UPDATE %(table_name)s SET %(updates)s  WHERE %(constraints)s", %(updateValues)s,%(constraintValues)s
"""
    return update_template%(locals())

def get_update_fields(field):
    name = field[0]
    if field[1] in ['BLOB', 'CHAR', "VARCHAR"]:
        #extendname = get_extend_member_name(name)
        return '_%(name)s'%(locals())
        #return 'm_pMyConn->EscapeString((const char*)(st.%(name)s), st.%(extendname)s)'%(locals())
    return 'st.%(name)s'%(locals())

def get_escap_fields(field):
    if field[1] in ['BLOB', 'CHAR', "VARCHAR"]:
        name = field[0]
        length = "1024*50"
        sourceLength = ""
        if field[2] <> '':
            length = field[2][1:-1]
            sourceLength = "strlen(st.%(name)s)"%(locals())
        else :
            extendname = get_extend_member_name(name)
            sourceLength = "st.%(extendname)s"%(locals())
        return 'char _%(name)s[(%(length)s)*2 + 1]="";m_pMyConn->EscapeString((const char*)(st.%(name)s), %(sourceLength)s, _%(name)s, sizeof(_%(name)s));'%(locals())
        #return 'm_pMyConn->EscapeString((const char*)(st.%(name)s), st.%(extendname)s)'%(locals())
    return ""
    
def build_escaping_macro(fields, table_name, operation):
    """�õ�cpp�ṹ�Ĳ����б�
    """
    op = operation.upper()
    tb_name = table_name.upper()
    fields = string.join(map(get_escap_fields, fields), ';')
    return "#define MACRO_ESCAPE_FIELDS_%(op)s_%(tb_name)s(st) %(fields)s  \n"%(locals())
    
    
    
def build_cpp_insert_fields_macro(fields, table_name, operation):
    """�õ�cpp�ṹ�Ĳ����б�
    """
    op = operation.upper()
    tb_name = table_name.upper()
    fields = string.join(map(get_update_fields, fields), ',')
    return "#define MACRO_STRUCT_FIELDS_%(op)s_%(tb_name)s(st) %(fields)s  \n"%(locals())

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
    
#����cpp�ṹ
g_sql_2_cpp_type = {
                    'BIGINT':'long long',
                    'BIGINT UNSIGNED':'unsigned long long',
                    'VARCHAR':'char',
                    'CHAR':'char',
                    'char':'char',
                    'SMALLINT':'unsigned short',
                    'TINYINT':'unsigned char',
                    'INTEGER':'int',
                    'INTEGER UNSIGNED' : 'unsigned int',
                    'MEDIUMINT':'int',
                    'BLOB':'unsigned char',
                    'DATETIME':'char',
                    'TIMESTAMP':'unsigned int',
                    'timestamp':'unsigned int',
                    }
def get_member_count(field):
    global g_blob_length
    if field[1] == 'VARCHAR':
        return '[%s]'%(field[2][1:-1])
    elif field[1] == 'BLOB':
        size = g_blob_length.get(field[0], None)
        return '[%s]'%(size)
    elif field[1] == 'DATETIME':
        return '[32]'
    elif field[1] == 'CHAR':
        return '[%s]'%(field[2][1:-1])
    return ''

def get_extend_member_name(name):
    return '_current_%s_length'%(name)

def get_extend_member(type, field):
    if type in ['BLOB']:
        return 'int %s;'%(get_extend_member_name(field))
    return ''


def get_member(f):
    global g_sql_2_cpp_type
    type = f[1]
    if f[3] <> '':
        type = type + " " +f[3]
    type = g_sql_2_cpp_type.get(type, None)
    if type == None:
        print 'errrrrrrrrrrrrrrrrrrrrrrror', f
    field = f[0]
    count = get_member_count(f)
    extend = get_extend_member(f[1], field)
    return '%(type)s %(field)s%(count)s;%(extend)s'%(locals())

g_struct_name_list = list()

def build_cpp_struct(valid_fields, sqlname):
    struct_template = """struct %(struct_name)s
{
    %(members)s
};
"""
    struct_name = sqlname
    global g_struct_name_list
    g_struct_name_list.append("%(struct_name)s"%(locals()))
    #print valid_fields
    #print map(get_member, valid_fields)
    try :
        members = string.join(map(get_member, valid_fields), '\n    ')
    except KeyError, e:
        print valid_fields;
        raise e
    except :
        print "err7777", valid_fields
    return struct_template%(locals()) 


def build_convert_field(field):
    field_name = field[0]
    if field[1] in ['BLOB',]:#datetime ����Ϊchar���飬���ݿ��������ַ���
        extend = get_extend_member_name(field_name)
        return 'getFieldLength(RC, _i,(st.%(extend)s));autoAssignChunck(RC,_i++, st.%(field_name)s, (st.%(extend)s));'%(locals())
    elif g_sql_2_cpp_type[field[1]] == 'char' and get_member_count(field) <> '':
        return 'autoAssign(RC,_i++, st.%(field_name)s, sizeof(st.%(field_name)s));'%(locals())
    else :
        return 'autoAssign(RC,_i++,st.%(field_name)s,0);'%(locals())


def build_convert_macro(fields, name):
    #������ֵ�ĺ�
    convert_template = """
#define CONVERT_RECORD_%(operation)s(RC,st) \\
int _i = 0;\\
%(member)s

"""
    operation = name.upper()
    member = string.join(map(build_convert_field, fields), '\\\n') + '\n'
    return convert_template%(locals())

#�����sql����Ǵ����ݿ�õ��Ľ�����䣬��������ͼ�ν�����ɽ���Ȼ��ֱ����ȡsql��䣬���������Ժ�ֱ������c++�Ľṹ
g_sql_map = {} #{tblname:create_table_sql}}
g_blob_length={
               'itemsPacket': 'MAX_PACKET_CAPACITY_BLOB_LENGTH', #20*120
               'taskFinished':'MAX_TASK_FINISHED_COUNT_BLOB_LENGTH', #1200+128   4*300
               'taskCurrent':'MAX_CURRENT_TASK_COUNT_BLOB_LENGTH',#16*30, 480+128
               'equipmentStrengthen':'MAX_EQUIPMENT_STRENGTHEN_CAPACITY_BLOB_LENGTH', #12*800,9600+128
               'wingPage':'MAX_WING_PAGE_BLOB_LENGTH', #20*8,160+128
               'mates':"MAX_MATE_BLOB_LENGTH", #184*100, 18400+128
               'randomRecruit':'MAX_RANDOM_RECRUIT_BLOB_LENGTH', #4*10,40+128
               'challengeRecord': 'MAX_CHALLENGE_RECORD_BLOB_LENGTH', #55320*5,��ʱ����,
               'strengthenInfo': 'MAX_STRENGTH_INFO_BLOB_LENGTH', #12*1,12+128
               'wingCompoundStar':'MAX_WING_COMPOUNDER_BLOB_LENGTH', #8*8  64+128
               'todayFubenRecord':'MAX_TODAY_FUBEN_BLOB_LENGTH', #4*100,400+128
               'todayPrizeRecord':'MAX_TODAY_PRIZE_BLOB_LENGTH', #4*128,512+128
               'prizeRecord':'MAX_PRIZE_BLOB_LENGTH', #4*256,1024+128
               'easyMateArray':'MAX_EASY_MATE_ARRAY_BLOB_LENGTH', #24*1,24+128
               'misc':'MAX_MISC_BLOB_LENGTH', #1024*1,1024
               'ranklist':'MAX_RANK_BLOB_LENGTH',#82*100 + 2+4
               'affairs': 'MAX_GANG_AFFAIRS_BLOB_LENGTH',
               'roleList': 'MAX_GANG_ROLELIST_BLOB_LENGTH',
               'taskOrItemOrGems': 'MAX_GANG_TASKORITEMORGEMS_BLOB_LENGTH',
               'joinList':'MAX_GANG_JOINLIST_BLOB_LENGTH',
               'friends':'2048',
               'friendsApply':'2048',
               'gangMisc':'100',
               'gangPublicDailyTask':'100',
               'playerTalks':'1024',
               'scenesdiscuss':'MAX_DISCUSS_SCENE_BLOG',
               'coachs':'MAX_COACH_BLOB_LENGTH',
               'roleClubCondition':'MAX_CLUBCONDITION_BLOB_LENGTH',
               'roleIntoGameData':'MAX_INTOGAMEDATA_BLOB_LENGTH',
               'arrayEquipment':'MAX_ARRAY_BLOB_LENGTH',
               'refreshItemArray':'MAX_REFRESHITEM_MAXCOUNT',
               'playerGuideRecord':'MAX_PLAYERRECORD_MAXLENGTH',
               "package":"MAX_TREASURE_CAPACITY_BLOB_LENGTH",
               "titles":"2048",
               "footmark":"2048",
               "paremeterNow":"2048",
               "paremeterMin":"2048",
               "paremeterMax":"2048",
               }

create_roleinfo = """
CREATE TABLE `role` (
  `userid` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `accountid` INTEGER(11) UNSIGNED NOT NULL ,  
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `level` INTEGER(11) DEFAULT '1',
  `professionId` INTEGER(11) UNSIGNED DEFAULT '100001' COMMENT 'see the document for profession',
  `exp` INTEGER(11) DEFAULT '0' COMMENT 'experience,for  current level',
  `popularity` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'popularity',
  `expTotal` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'total experience from birth',
  `starlevel` INTEGER(11) DEFAULT '0' COMMENT 'star level',
  `currentGuid` INTEGER(11) UNSIGNED DEFAULT '2' COMMENT 'current guid for all objects owned by one role',
  `money` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'money',
  `diamond` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'diamond,rmb',
  `exploit` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'exploit',
  `vigor` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'vigor for role ',
  `isInit` INTEGER(11) DEFAULT '0' COMMENT 'if it is 0,it should be initialized',
  `loginCount` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'login count',
  `showLevel` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'show level',
  `itemsPacket` BLOB COMMENT 'packet for items',
  `currentArrayId` INTEGER(11) UNSIGNED DEFAULT '111101' COMMENT 'current array id',
  `taskFinished` BLOB COMMENT 'finished task record',
  `taskCurrent` BLOB COMMENT 'detail info of the undergoing task',
  `equipmentStrengthen` BLOB COMMENT 'strengthen record for equipment',
  `wingPage` BLOB COMMENT 'wing page,store guids for show',  PRIMARY KEY (`userid`),
  `mates` BLOB COMMENT 'array of mates ,including train info,packets,level , and so on',
  `randomRecruit` BLOB COMMENT 'random recruit record',
  `challengeRecord` BLOB COMMENT 'max 5 challenge record',
  `wingCompoundStar` BLOB COMMENT 'wing compound star record',
  `todayFubenRecord` BLOB COMMENT 'today hard Fuben play record',
  `todayPrizeRecord` BLOB COMMENT 'today get prize record, shall be refresh everyday',
  `prizeRecord` BLOB COMMENT 'obtain prize record,',
  `misc` BLOB COMMENT 'misc info  ,', 
  `friends` BLOB DEFAULT NULL COMMENT 'friend info  ,', 
  `friendsApply` BLOB DEFAULT NULL COMMENT 'friend apply info  ,',   
  `playerTalks` BLOB DEFAULT NULL COMMENT 'player talks',   
  `nobility` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'nobility',
  `lastLogoffTime` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'lastLogoffTime',
  `scenesdiscuss` BLOB DEFAULT NULL COMMENT 'discuss info  ,',
  `coachs` BLOB DEFAULT NULL COMMENT 'coach info  ,',
  `roleClubCondition` BLOB DEFAULT NULL COMMENT 'roleClubCondition info  ,',
  `roleIntoGameData` BLOB DEFAULT NULL COMMENT 'roleIntoGameData info  ,',
  `arrayEquipment` BLOB DEFAULT NULL COMMENT 'arrayEquipment info  ,',
  `refreshItemArray` BLOB DEFAULT NULL COMMENT 'refreshItemArray info  ,',
  `playerGuideRecord` BLOB DEFAULT NULL COMMENT 'playerGuideRecord info  ,',
  UNIQUE KEY `userid` (`userid`),
  UNIQUE KEY `idx_rolename` (`rolename`),
  KEY `idx_accountid` (`accountid`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_roleinfo_biogame = """
CREATE TABLE `role` (
  `userid` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `accountid` INTEGER(11) UNSIGNED NOT NULL ,  
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `professionId` INTEGER(11) UNSIGNED DEFAULT '100001' COMMENT 'see the document for profession',
  `money` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'money',
  `diamond` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'diamond,rmb',
  `vigor` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'vigor for role ',
  `isInit` INTEGER(11) DEFAULT '0' COMMENT 'if it is 0,it should be initialized',
  `loginCount` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'login count',
  `lastLogoffTime` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'lastLogoffTime',
  `currentGuid` INTEGER(11) UNSIGNED DEFAULT '2' COMMENT 'current guid for all objects owned by one role',
  `todayFubenRecord` BLOB COMMENT 'today hard Fuben play record',
  `todayPrizeRecord` BLOB COMMENT 'today get prize record, shall be refresh everyday',
  `prizeRecord` BLOB COMMENT 'obtain prize record,',
  `taskFinished` BLOB COMMENT 'finished task record',
  `taskCurrent` BLOB COMMENT 'detail info of the undergoing task',
  `misc` BLOB COMMENT 'misc info  ,', 
  `friends` BLOB DEFAULT NULL COMMENT 'friend info  ,', 
  `friendsApply` BLOB DEFAULT NULL COMMENT 'friend apply info  ,',
  `package` BLOB DEFAULT NULL COMMENT 'all items,',
  `titles` BLOB DEFAULT NULL COMMENT 'all titles ,',
  `footmark` BLOB DEFAULT NULL COMMENT 'recent things happened ,',  
  `paremeterNow` BLOB DEFAULT NULL COMMENT 'life record of role  ,',
  `paremeterMin` BLOB DEFAULT NULL COMMENT 'life record of role  ,',
  `paremeterMax` BLOB DEFAULT NULL COMMENT 'life record of role  ,',

  UNIQUE KEY `userid` (`userid`),
  UNIQUE KEY `idx_rolename` (`rolename`),
  KEY `idx_accountid` (`accountid`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""


create_rank = """
CREATE TABLE `rank` (
  `rankid` INTEGER(11) UNSIGNED NOT NULL unique COMMENT 'just convenient for sql',
  `ranklist` BLOB COMMENT 'rank list like int array',
  `lastupdateTime` INTEGER(11) UNSIGNED DEFAULT '0'
)ENGINE=MyISAM,
AUTO_INCREMENT=1 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""
create_account = """
CREATE TABLE `account` (
  `accountid` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `macAddress` CHAR(20) COLLATE utf8_general_ci DEFAULT NULL,
  `emailAccount` VARCHAR(32) COLLATE utf8_general_ci DEFAULT NULL COMMENT 'email account for login',
  `pwd` VARCHAR(32) COLLATE utf8_general_ci DEFAULT NULL COMMENT 'password',
  `qq` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'qq number for login used',
  `account91` CHAR(64) COLLATE utf8_general_ci DEFAULT NULL,
  UNIQUE KEY `accountid` (`accountid`),
  UNIQUE KEY `idx_macAddress` (`macAddress`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_iap_transaction = """
CREATE TABLE `iap_transaction_id` (
  `id` INTEGER(11) NOT NULL AUTO_INCREMENT,
  `userid` INTEGER(11) NOT NULL DEFAULT '0',
  `transactionId` BIGINT(20) NOT NULL DEFAULT '0',
  `buyDate` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `purchaseDate` CHAR(20) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `obtained` INTEGER(11) DEFAULT '0' COMMENT '0 means not obtained',
  `productId` CHAR(128) COLLATE utf8_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""


create_gang = """
CREATE TABLE `gang` (
  `id` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `createTime` INTEGER(11) UNSIGNED DEFAULT NULL,
  `ownerUserId` INTEGER(11) UNSIGNED DEFAULT NULL,
  `state` INTEGER(11) UNSIGNED DEFAULT '0' ,
  `level` INTEGER(11) UNSIGNED DEFAULT '0',
  `popularity` INTEGER(11) UNSIGNED DEFAULT '0' ,
  `coffers` INTEGER(11) DEFAULT '0' ,
  `power` INTEGER(11) UNSIGNED DEFAULT '0' ,
  `name` VARCHAR(32) COLLATE utf8_general_ci DEFAULT NULL,
  `annoucement` VARCHAR(128) COLLATE utf8_general_ci DEFAULT NULL ,
  `declaration` VARCHAR(64) COLLATE utf8_general_ci DEFAULT NULL ,
  `affairs` BLOB DEFAULT NULL COMMENT '' ,
  `roleList` BLOB DEFAULT NULL COMMENT '',
  `taskOrItemOrGems` BLOB DEFAULT NULL COMMENT '',
  `joinList` BLOB DEFAULT NULL COMMENT '',
  `gangMisc` BLOB DEFAULT NULL COMMENT '',
  `gangPublicDailyTask` BLOB DEFAULT NULL COMMENT '',  
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';"""


create_iapppay = """
CREATE TABLE `iapppay` (
  `id` INTEGER(11) NOT NULL AUTO_INCREMENT,
  `userid` INTEGER(11) NOT NULL DEFAULT '0',
  `ordNO` CHAR(50) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `buyDate` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `purchaseDate` CHAR(20) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `payState` INTEGER(11) DEFAULT '0',
  `productId` INTEGER(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_passport = """
CREATE TABLE `passport` (
  `passportid` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `pwd` CHAR(32) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `passport` CHAR(32) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `email` CHAR(32) COLLATE utf8_general_ci DEFAULT NULL,
  `qq` BIGINT(20) UNSIGNED DEFAULT NULL,
  `ingot` INTEGER(11) UNSIGNED DEFAULT NULL,
  `macAddress` CHAR(20) COLLATE utf8_general_ci DEFAULT NULL,
  `sessionid` CHAR(32) COLLATE utf8_general_ci DEFAULT NULL,
  `lastActiveTime` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'last session id active time',
  PRIMARY KEY (`passportid`),
  UNIQUE KEY `idx_passport` (`passport`),
  UNIQUE KEY `passportid` (`passportid`),
  KEY `idx_email` (`email`),
  KEY `idx_qq` (`qq`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_lj_role = """
CREATE TABLE `lj_role` (
  `passportId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `zoneId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `level` INTEGER(11) UNSIGNED DEFAULT '0',
  `userId` INTEGER(11) UNSIGNED DEFAULT NULL,
  KEY `idx_passportId_ZoneId` (`passportId`, `zoneId`),
  KEY `idx_passportId` (`passportId`),
  KEY `idx_userId_zoneId` (`userId`, `zoneId`)
)ENGINE=MyISAM,
CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""


create_pp_passport = """
CREATE TABLE `pp_passport` (
  `ppPassportId` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `ppUserName` CHAR(32) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`ppPassportId`),
  UNIQUE KEY `idx_ppusername` (`ppusername`),
  UNIQUE KEY `ppPassportId` (`ppPassportId`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_lj_pp_role = """
CREATE TABLE `lj_pp_role` (
  `ppPassportId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `zoneId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `level` INTEGER(11) UNSIGNED DEFAULT '0',
  `userId` INTEGER(11) UNSIGNED DEFAULT NULL,
  KEY `idx_PPPassportId_ZoneId` (`ppPassportId`, `zoneId`),
  KEY `idx_PPPassportId` (`ppPassportId`),
  KEY `idx_userId_zoneId` (`userId`, `zoneId`)
)ENGINE=MyISAM,
CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_91_passport = """
CREATE TABLE `91_passport` (
  `PassportId91` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Uin` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`PassportId91`),
  UNIQUE KEY `idx_Uin` (`Uin`),
  UNIQUE KEY `PassportId91` (`PassportId91`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""
create_lj_91_role = """
CREATE TABLE `lj_91_role` (
  `PassportId91` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `zoneId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `level` INTEGER(11) UNSIGNED DEFAULT '0',
  `userId` INTEGER(11) UNSIGNED DEFAULT NULL,
  KEY `idx_91PassportId_ZoneId` (`PassportId91`, `zoneId`),
  KEY `idx_91PassportId` (`PassportId91`),
  KEY `idx_userId_zoneId` (`userId`, `zoneId`)
)ENGINE=MyISAM,
CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

create_ky_passport = """
CREATE TABLE `ky_passport` (
  `kyPassportId` INTEGER(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `guid` CHAR(32) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`kyPassportId`),
  UNIQUE KEY `idx_guid` (`guid`),
  UNIQUE KEY `kyPassportId` (`kyPassportId`)
)ENGINE=MyISAM,
AUTO_INCREMENT=1 ROW_FORMAT=FIXED CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""
create_lj_ky_role = """
CREATE TABLE `lj_ky_role` (
  `kyPassportId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `zoneId` INTEGER(11) UNSIGNED NOT NULL DEFAULT '0',
  `rolename` VARCHAR(64) COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `level` INTEGER(11) UNSIGNED DEFAULT '0',
  `userId` INTEGER(11) UNSIGNED DEFAULT NULL,
  KEY `idx_kyPassportId_ZoneId` (`kyPassportId`, `zoneId`),
  KEY `idx_kyPassportId` (`kyPassportId`),
  KEY `idx_userId_zoneId` (`userId`, `zoneId`)
)ENGINE=MyISAM,
CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';
"""

g_sql_map['role'] = create_roleinfo_biogame

g_sql_map['rank'] = create_rank

g_sql_map['account'] = create_account

g_sql_map['iap_transaction_id'] = create_iap_transaction

g_sql_map['gang'] = create_gang

g_sql_map['passport'] = create_passport

g_sql_map['lj_role'] = create_lj_role

g_sql_map['iapppay'] = create_iapppay

g_sql_map['pp_passport'] = create_pp_passport

g_sql_map['lj_pp_role'] = create_lj_pp_role

g_sql_map['91_passport'] = create_91_passport

g_sql_map['lj_91_role'] = create_lj_91_role

g_sql_map['ky_passport'] = create_ky_passport

g_sql_map['lj_ky_role'] = create_lj_ky_role

g_sql_map['biogame_role'] = create_roleinfo_biogame




def build_create_table_sql(create_sql, table_name):
    return '#define CREATE_TABLE_%s  '%table_name.upper() + '\"' + create_sql.replace('`', '').replace('\n', '\\\n') + '\"\n'

def build_sql_by_createsql(targetList):
    str = ''
    str = '\n/****************************************************************************/\n'
    for table_name in targetList:
        if table_name not in g_sql_map.keys():
            continue
        print table_name
        valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
        str += build_create_table_sql(g_sql_map[table_name], table_name)
        str += build_cpp_struct(valid_fields, 'Sql_SelectAll_'+table_name+'')
        str += build_convert_macro(valid_fields, table_name+'_selectall')
        #str += build_select_all_str(table_name)
    return str

def build_select_sql_by_field_list(needfieldlist, byfieldlist, table_name, operation):
    """ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������select�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_by = get_valid_fields_filter(valid_fields, byfieldlist)
    valid_fields_need = get_valid_fields_filter(valid_fields, needfieldlist)
    #print valid_fields
    str += build_cpp_struct(valid_fields_need, 'Sql_Select_'+table_name+'_'+operation)
    str += build_convert_macro(valid_fields_need, table_name+'_'+operation)
    str += build_escaping_macro(valid_fields_by, table_name, operation)
    str += build_select_str(valid_fields_need, valid_fields_by, table_name, operation)
    return str

def build_select_sql_by_field_list_limit(needfieldlist, byfieldlist, table_name, operation, orderby, limit, isdesc=False):
    """limit�汾 ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������select�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_by = get_valid_fields_filter(valid_fields, byfieldlist)
    valid_fields_need = get_valid_fields_filter(valid_fields, needfieldlist)
    #print valid_fields
    str += build_cpp_struct(valid_fields_need, 'Sql_Select_'+table_name+'_'+operation)
    str += build_convert_macro(valid_fields_need, table_name+'_'+operation)
    str += build_escaping_macro(valid_fields_by, table_name, operation)
    str += build_limit_select_str(valid_fields_need,valid_fields_by, table_name, operation, orderby, isdesc, limit, False)
    return str


def build_select_sql_all_by_field_list(byfieldlist, table_name, operation):
    """ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������select�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_by = get_valid_fields_filter(valid_fields, byfieldlist)
    #print valid_fields
    str += build_cpp_struct(valid_fields_by, 'Sql_SelectAll_'+table_name+'_'+operation)
    #str += build_convert_macro(valid_fields_specified, table_name+'_'+operation)    
    str += build_escaping_macro(valid_fields_by, table_name, operation)
    str += build_select_str([],valid_fields_by, table_name, operation, True)
    return str

def build_limit_select_sql_all_by_field_list(byfieldlist, table_name, operation, orderby, limit, isdesc=False):
    """ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������select�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_by = get_valid_fields_filter(valid_fields, byfieldlist)
    #print valid_fields
    str += build_cpp_struct(valid_fields_by, 'Sql_SelectAll_'+table_name+'_'+operation)
    #str += build_convert_macro(valid_fields_specified, table_name+'_'+operation)
    str += build_escaping_macro(valid_fields_by, table_name, operation)
    str += build_limit_select_str([],valid_fields_by, table_name, operation, orderby, isdesc, limit, True)
    return str


def build_update_sql_by_field_list(updateFieldList, constraintFieldList, table_name, operation):
    """ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������update�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_update = get_valid_fields_filter(valid_fields, updateFieldList)
    valid_fields_constraint = get_valid_fields_filter(valid_fields, constraintFieldList)
    valid_fields_total = []
    for l in valid_fields_update:
        valid_fields_total.append(l)
    for l in valid_fields_constraint:
        if l not in valid_fields_update:
            valid_fields_total.append(l)
    #print  valid_fields_specified
    str += build_cpp_struct(valid_fields_total, 'Sql_Update_'+table_name+'_'+operation)
    str += build_escaping_macro(valid_fields_update, table_name, operation)
    str += build_update_str(valid_fields_update, valid_fields_constraint, table_name, operation)
    #str += build_cpp_insert_fields_macro(valid_fields_specified, table_name, operation)
    return str

def build_insert_sql_by_field_list(fieldlist, table_name, operation):
    """ָ����񣬻���field�б����ж�field�����ǲ��ǺϷ���Ȼ������sql��䣬��ֵ�꣬fields��Ӧ�����ݽṹ
    operationӦ���ǰ��������;�����¼�������,select_entergame,insert_newrole
    ����������insert�����ص�"""
    str = '\n/****************************************************************************/\n'
    valid_fields = get_valid_fields(get_fields(g_sql_map[table_name]))
    valid_fields_specified = get_valid_fields_filter(valid_fields, fieldlist)
    #print  valid_fields_specified
    str += build_cpp_struct(valid_fields_specified, 'Sql_Insert_'+table_name+'_'+operation)
    str += build_insert_str(valid_fields_specified, table_name, operation)
    str += build_escaping_macro(valid_fields_specified, table_name, operation)
    str += build_cpp_insert_fields_macro(valid_fields_specified, table_name, operation)#����ṹ�ı����������һ����
    return str

def build_wrap_member(struct_name):
    return "        %(struct_name)s st_%(struct_name)s;"%(locals())

def build_wrap_struct(module_name):
    global g_struct_name_list
    wrap_struct_template = """struct SDB_Wrap%(module_name)s
{
    int socket;//����Ѱ�ҷ�������
    int operateId;//����id
    int operateType;
    int operateUserData;
    int rcCount;//���ؽ���Ķ���,0,û�н��,1,һ�����,2,����...
    int dbErrcode;//����ֵ
    unsigned long long insertId;//�����insert�����������Ƿ��ز���id
    unsigned int dbId;//�������ĸ�db����Ҫ�������ļ�֧��
    union{
%(member)s
        char temp[512]; //���������ʹ��
        } _u;
};
"""
    member = string.join(map(build_wrap_member, g_struct_name_list), '\n')
    return wrap_struct_template%(locals())

def build_db_operator_enum_member(struct_name):
    enum_name = string.upper(struct_name)[4:]#�ѵ�һ��Sql_ȥ��
    return "        DB_OPRATOR_%(enum_name)s,"%(locals())

def build_operation_enum(model_name):
    global g_struct_name_list
    operator_enum_template="""
enum {
        NONE_OPERATION%(model_name)s=0,
%(members)s
    };
"""
    members = string.join(map(build_db_operator_enum_member, g_struct_name_list), '\n') + '\n'
    return operator_enum_template%(locals())

#���ݿ����
#1  ��mac��ַ��¼,�����û�
#2  ע���ʺ�����,��mac��ַ��,����Ƿ��Ѿ���¼
#3  ���ʺ������¼,�����û�
#4  ���ʺ�����mac��ַ��¼,�������

def main(sqlHelpHFile):
    global g_struct_name_list
    g_struct_name_list = []
    str = ''
    str += build_sql_by_createsql(['account', 'role', 'rank', 'iap_transaction_id', "gang", "iapppay", "biogame_role"])
    #-----------------------�ʺ�����
    #########mac ��½
    #mac��ַ��ѯ
    str += build_select_sql_all_by_field_list(['macAddress', ], 'account', 'login_by_MAC')
    #mac��ַע��
    str += build_insert_sql_by_field_list(['macAddress', ], 'account','create_account_by_MAC') 
    #�������accountid
    str += build_limit_select_sql_all_by_field_list([], 'account', "get_max_accountid_limit", "accountid", "1", True)
    #�������е�mac��ַ�˺�
    str += build_insert_sql_by_field_list(['accountid', 'macAddress', ], 'account','insert_account_by_id_and_mac') 
    #�ʺ�����mac��ַ��----����ʹ��
    #str += build_update_sql_by_field_list(['emailAccount','pwd',], ['accountid',], 'account','register_account')
    #�ʺŲ���----����ʹ��
    #str += build_select_sql_all_by_field_list(['emailAccount'], 'account', 'check_account_exist')
    #�ʺ������½��ѯ----����ʹ��
    #str += build_select_sql_all_by_field_list(['emailAccount', 'pwd'], 'account','login_by_account') 
    #�ʺ�����mac��ַ��ѯ----����ʹ��
    #str += build_select_sql_all_by_field_list(['emailAccount', 'pwd', 'macAddress'], 'account','login_by_account_MAC') 
    
    
  

    
    #-----------------------��ɫ����
    #�û�������
    str += build_select_sql_all_by_field_list(['rolename'], 'role', 'check_rolename_exist')
    #������ɫ,����mac��ַ��Ӧ��account������ɫ
    str += build_insert_sql_by_field_list(['rolename', 'accountid', 'professionId', ], 'role','create_role_by_accountid')
    #������ɫ,ʹ��ͨ��֤��¼�Ĵ�����ɫ
    str += build_insert_sql_by_field_list(['rolename', 'accountid', 'professionId', ], 'role','create_role_by_passport')
    #���ʺ���֤�ɹ��Ժ�ʹ��accountid, userid��½ 
    str += build_select_sql_all_by_field_list(['accountid', 'userid'], 'role', 'get_role_by_accountid_userid')
    #���ʺ���֤�ɹ��Ժ�ʹ��accountid����,���ҵ�һ�λ��
    str += build_select_sql_all_by_field_list(['accountid',], 'role', 'get_role_by_accountid_first')
    #��¼�����ݿ�
    str += build_update_sql_by_field_list([ "accountid", "rolename", "professionId", "money", "diamond", "vigor", "isInit", "loginCount", "lastLogoffTime", "todayFubenRecord", "todayPrizeRecord", "prizeRecord", "misc", "friends", "friendsApply", "package", "titles", "footmark", 'taskFinished', 'taskCurrent', 'currentGuid', 'paremeterMin', 'paremeterMax', 'paremeterNow' ], ['userid',], 'role','save_role_by_userid')
    #str += build_update_sql_by_field_list([ "accountid", "professionId", "showLevel", "loginCount", "equipmentStrengthen", "misc", 'todayPrizeRecord', 'prizeRecord', 'todayFubenRecord', 'wingCompoundStar', 'isInit',  'vigor', 'challengeRecord', 'exploit', 'diamond', 'money', 'itemsPacket', 'expTotal', 'popularity', 'exp', 'level', 'taskFinished', 'taskCurrent', 'currentGuid', 'wingPage', 'mates', 'randomRecruit', 'friends', 'friendsApply', 'playerTalks','nobility', 'lastLogoffTime', 'scenesdiscuss','coachs','roleClubCondition','roleIntoGameData','arrayEquipment','refreshItemArray','playerGuideRecord'], ['userid',], 'role','save_role_by_userid')
    #��ս��¼д�����ݿ�
    #str += build_update_sql_by_field_list([ 'challengeRecord', ], ['userid',], 'role','save_role_challenge_record_by_userid')
    #��������������д�����ݿ�
    #str += build_update_sql_by_field_list([ 'popularity', ], ['userid',], 'role','save_role_popularity_by_userid')
    #��ս��������ʱ��,��Ҫ������˵���Ϣ,
    #str += build_select_sql_all_by_field_list(['userid',], 'role', 'get_challenge_target_role_by_userid')
    #ʹ��userid��½,
    str += build_select_sql_all_by_field_list(['userid',], 'role', 'get_role_by_userid')
    #�������userid
    str += build_limit_select_sql_all_by_field_list([], 'role', "get_max_userid_limit", "userid", "1", True)
    #�����ֳɵĽ�ɫ
    #str += build_insert_sql_by_field_list(["accountid", 'challengeRecord', 'currentGuid', 'currentArrayId', 'diamond', 'exp', "equipmentStrengthen", 'exploit', 'expTotal', 'isInit',  'itemsPacket', "loginCount", 'level', "misc", 'money', 'mates', 'prizeRecord', "professionId", 'popularity', 'randomRecruit', 'rolename', "showLevel", 'starlevel', 'taskFinished', 'taskCurrent', 'todayPrizeRecord', 'todayFubenRecord', 'vigor', "userid", 'wingPage', 'wingCompoundStar', 'friends', 'friendsApply', 'playerTalks','nobility', 'lastLogoffTime','scenesdiscuss','coachs','roleClubCondition','roleIntoGameData','arrayEquipment','refreshItemArray','playerGuideRecord'], 'role','insert_role_all')
    #��ȡ����
    str += build_select_sql_by_field_list(['userid', 'professionId', 'rolename', 'lastLogoffTime', "misc", "friends"], [], "role", "get_all_role_snapshot")
    #����mac��ַ��ȡ��ɫ�б�
    str += build_select_sql_by_field_list_limit(["userid", "rolename"], ["accountid"], "role", "get_rolelist_by_accountid", "userid", "10", True)
    #��ɫ������
    str += build_update_sql_by_field_list([ 'rolename', ], ['userid',], 'role','update_role_change_rolename_by_userid')
    
    
    #-----------------------����������
    #���������Ϣ,ǰ8��
    str += build_limit_select_sql_all_by_field_list([], 'rank', "get_all_rank_limit", "rankid", "30", False)
    #��þ�������������
    str += build_select_sql_all_by_field_list(['rankid',], 'rank', 'get_rank')
    #��������¼�����ݿ�
    str += build_update_sql_by_field_list(['ranklist','lastupdateTime'], ['rankid',], 'rank','save_rank')
    #����������¼
    str += build_insert_sql_by_field_list(['ranklist', 'rankid'], 'rank','insert_rank')
    #������ݿⱣ��
    str += build_select_sql_all_by_field_list(['rankid'], 'rank','check_rank_count')
    #-----------------------iap transaction�����¼
    #��iap��¼�����ݿ��ȡ
    str += build_select_sql_by_field_list(["userid", "transactionId"], [], "iap_transaction_id", "get_this_week_iap_transaction")
    #����iap�����¼
    str += build_insert_sql_by_field_list(['userid', 'transactionId', 'purchaseDate', 'obtained', 'productId'], 'iap_transaction_id','insert_iap_transaction')
    #�����ݿ��ȡ��δ���ŵĳ�ֵ��� 
    str += build_select_sql_all_by_field_list(['obtained',], 'iap_transaction_id', 'get_not_obtained_iap')
    #����ȡ��¼�����ݿ�
    str += build_update_sql_by_field_list(['obtained'], ['id',], 'iap_transaction_id','save_obtain_iap')
    #-----------------------����
    #��ǰ100�����ɴ����ݿ��ȡ
    str += build_limit_select_sql_all_by_field_list([], 'gang', "get_all_gang_limit", "id", "100", False)
    #�����°��
    str += build_insert_sql_by_field_list(['joinList', 'createTime', 'ownerUserId', 'state', 'level', 'popularity', 'coffers', 'power', "name", "annoucement", "declaration", 'affairs', 'roleList', 'taskOrItemOrGems'], 'gang','insert_new_gang')
    #���°������
    str += build_update_sql_by_field_list(['joinList', 'createTime', 'ownerUserId', 'state', 'level', 'popularity', 'coffers', 'power', "name", "annoucement", "declaration",'affairs', 'roleList', 'taskOrItemOrGems', "gangPublicDailyTask", "gangMisc"], ['id',], 'gang','update_gang_by_id')
    
    #-------------------����֧��
    #�����µ�֧������
    str += build_insert_sql_by_field_list(['userid', 'ordNO', 'purchaseDate', 'payState', 'productId'], 'iapppay', "insert_new_iapppay_record")
    #��ѯ��ֵ����
    str += build_limit_select_sql_all_by_field_list(['payState'], 'iapppay', "select_undefined_state_iapppay" , 'id', "100")
    #���³�ֵ����
    str += build_update_sql_by_field_list(['purchaseDate', 'payState'], ['ordNO'], 'iapppay', 'update_iapppay')
    #��ѯָ������
    #str += build_limit_select_sql_all_by_field_list(['ordNO'], 'iapppay', 'select_ordNO_Info_iapppay','id', "100")
       
    str += "\n\n"
    str += build_wrap_struct("")
    str += build_operation_enum("")
    #test==============
    
    file_template = """#ifndef DBSERVER_SQL_OPERATION_HLP_H
#define DBSERVER_SQL_OPERATION_HLP_H
/*made automatically,do NOT change manually*/
#include "protocols.h"
%s

#endif
"""
    w = open(sqlHelpHFile, "w")
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(file_template%str)
    w.close()
    print "OK"
    #print file_template%str

def main_passport(sqlHelpHFile):
    global g_struct_name_list
    g_struct_name_list = []
    str = ''
    str += build_sql_by_createsql(["passport", "lj_role","pp_passport","lj_pp_role","91_passport","lj_91_role","ky_passport","lj_ky_role"])
    #-----------------------ͨ��֤����
    #���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['passport'], 'passport','get_passport_by_passport')
    #�ڵ�½���������ͨ��֤����
    str += build_insert_sql_by_field_list(['pwd', 'passport', 'email', 'qq', 'ingot', 'macAddress', 'sessionid', 'lastActiveTime'], 'passport','create_passport') 
    #����Ϸ���洴����ͨ��֤����
    str += build_insert_sql_by_field_list(['pwd', 'passport', 'email', 'qq', 'ingot', 'macAddress', 'sessionid', 'lastActiveTime'], 'passport','create_passport_and_bind_userid') 
    #����ͨ��֤��sessionid��time
    str += build_update_sql_by_field_list(['macAddress', 'sessionid', 'lastActiveTime'], ['passportid',], 'passport','update_sessionid_activetime_by_passportid')
    #���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['passport'], 'passport','check_passport_by_passport')
    #Ϊ�󶨽�ɫ���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['passport'], 'passport','get_passport_by_passport_and_bind')
    #����ͨ��֤�˺ţ����sessionid
    str += build_select_sql_all_by_field_list(['passport'], 'passport','check_sessionid_by_passport')

    #-----------------------������ɫ������
    #������ݿⱣ��
    str += build_select_sql_all_by_field_list(['passportId'], 'lj_role','check_lj_role_count')
    #����½�ض������Ľ�ɫ����
    str += build_select_sql_all_by_field_list(['passportId', 'zoneId'], 'lj_role','get_roleinfo_by_passportid_and_zoneid')
    #��ӽ�ɫ���˺�����
    str += build_insert_sql_by_field_list(['passportId', 'zoneId', 'rolename', 'level', 'userId'], 'lj_role','bind_passport_2_role') 
    #����ض�������ɫ�Ƿ����
    str += build_select_sql_all_by_field_list(['userId', 'zoneId'], 'lj_role','get_roleinfo_by_userid_and_zoneid')
    #����ض�������ɫ�Ƿ����,���Ҵ����˺�
    str += build_select_sql_all_by_field_list(['userId', 'zoneId'], 'lj_role','get_roleinfo_by_userid_and_zoneid_2_create_passport')
    
    #-----------------------PP����ͨ��֤
    #���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['ppUserName'], 'pp_passport','get_pppassportid_by_ppusername')
    #���PP��֤ͨ����ͨ��֤�˺�
    str += build_insert_sql_by_field_list(['ppUserName'], 'pp_passport','create_pp_passport')

 
    #-----------------------PP����������ɫ������
    #ͨ��id����PPͨ��֤
    str += build_select_sql_all_by_field_list(['ppPassportId'], 'lj_pp_role','get_lj_pp_role_by_pppassportid') 
    #��ӽ�ɫ���˺�����
    str += build_insert_sql_by_field_list(['ppPassportId', 'zoneId', 'rolename', 'level', 'userId'], 'lj_pp_role','bind_pp_passport_2_role')
    #����½�ض������Ľ�ɫ����
    str += build_select_sql_all_by_field_list(['ppPassportId', 'zoneId'], 'lj_pp_role','get_roleinfo_by_pppassportid_and_zoneid')
    #����ض�������ɫ�Ƿ����
    str += build_select_sql_all_by_field_list(['userId', 'zoneId'], 'lj_pp_role','get_roleinfo_by_userid_and_zoneid')
    
    
    #-----------------------91ͨ��֤
    #���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['Uin'], '91_passport','get_91passportid_by_Uin')
    #���PP��֤ͨ����ͨ��֤�˺�
    str += build_insert_sql_by_field_list(['Uin'], '91_passport','create_91_passport')

 
    #-----------------------91������ɫ������
    #ͨ��id����91ͨ��֤
    str += build_select_sql_all_by_field_list(['PassportId91'], 'lj_91_role','get_lj_91_role_by_91passportid') 
    #��ӽ�ɫ���˺�����
    str += build_insert_sql_by_field_list(['PassportId91', 'zoneId', 'rolename', 'level', 'userId'], 'lj_91_role','bind_91_passport_2_role')
    #����½�ض������Ľ�ɫ����
    str += build_select_sql_all_by_field_list(['PassportId91', 'zoneId'], 'lj_91_role','get_roleinfo_by_91passportid_and_zoneid')
    #����ض�������ɫ�Ƿ����
    str += build_select_sql_all_by_field_list(['userId', 'zoneId'], 'lj_91_role','get_roleinfo_by_userid_and_zoneid')
    
    #-----------------------����ͨ��֤
    #���ͨ��֤�˺�
    str += build_select_sql_all_by_field_list(['guid'], 'ky_passport','get_kypassportid_by_guid')
    #���PP��֤ͨ����ͨ��֤�˺�
    str += build_insert_sql_by_field_list(['guid'], 'ky_passport','create_ky_passport')

 
    #-----------------------����������ɫ������
    #ͨ��id���ҿ���ͨ��֤
    str += build_select_sql_all_by_field_list(['kyPassportId'], 'lj_ky_role','get_lj_ky_role_by_kypassportid') 
    #��ӽ�ɫ���˺�����
    str += build_insert_sql_by_field_list(['kyPassportId', 'zoneId', 'rolename', 'level', 'userId'], 'lj_ky_role','bind_ky_passport_2_role')
    #����½�ض������Ľ�ɫ����
    str += build_select_sql_all_by_field_list(['kyPassportId', 'zoneId'], 'lj_ky_role','get_roleinfo_by_kypassportid_and_zoneid')
    #����ض�������ɫ�Ƿ����
    str += build_select_sql_all_by_field_list(['userId', 'zoneId'], 'lj_ky_role','get_roleinfo_by_userid_and_zoneid')
    
    str += "\n\n"
    str += build_wrap_struct("_passport")
    str += build_operation_enum("_PASSPORT")
    #test==============
    
    file_template = """#ifndef DBSERVER_SQL_OPERATION_HLP_PASSPORT_H
#define DBSERVER_SQL_OPERATION_HLP_PASSPORT_H
/*made automatically,do NOT change manually*/
#include "protocols.h"
#include "protocolPassport.h"
%s

#endif
"""
    w = open(sqlHelpHFile, "w")
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(file_template%str)
    w.close()
    print "OK"
    #print file_template%str

def main_test(sqlHelpHFile):
    global g_struct_name_list
    g_struct_name_list = []
    str = ''
    # 'role', 'rank', 'iap_transaction_id', 
    str += build_sql_by_createsql(['account', "gang", ])
    print str
    
#main_test('../../common_interface/SqlOperationHlp.h')
