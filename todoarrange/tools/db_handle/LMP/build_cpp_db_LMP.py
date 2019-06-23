# -*- coding: utf8 -*-
import sys
sys.path.append('../')

import parse_sql_base

#这里的sql语句是从数据库得到的建表语句，可以是在图形界面完成建表，然后直接提取sql语句，放在这里以后，直接生成c++的结构


g_blob_length={
               'itemsPacket': 'MAX_PACKET_CAPACITY_BLOB_LENGTH', #20*120
               'taskFinished':'MAX_TASK_FINISHED_COUNT_BLOB_LENGTH', #1200+128   4*300
               'taskCurrent':'MAX_CURRENT_TASK_COUNT_BLOB_LENGTH',#16*30, 480+128
               'equipmentStrengthen':'MAX_EQUIPMENT_STRENGTHEN_CAPACITY_BLOB_LENGTH', #12*800,9600+128
               'wingPage':'MAX_WING_PAGE_BLOB_LENGTH', #20*8,160+128
               'mates':"MAX_MATE_BLOB_LENGTH", #184*100, 18400+128
               'randomRecruit':'MAX_RANDOM_RECRUIT_BLOB_LENGTH', #4*10,40+128
               'challengeRecord': 'MAX_CHALLENGE_RECORD_BLOB_LENGTH', #55320*5,暂时不做,
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


parse_sql_base.set_blob_length(g_blob_length)

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

g_sql_map = {} #{tblname:create_table_sql}}

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

parse_sql_base.set_sql_map(g_sql_map)

#数据库操作
#1  用mac地址登录,试玩用户
#2  注册帐号密码,和mac地址绑定,检查是否已经登录
#3  用帐号密码登录,试玩用户
#4  用帐号密码mac地址登录,正常玩家

def main(sqlHelpHFile):
    str = ''
    str += parse_sql_base.build_sql_by_createsql(['account', 'role', 'rank', 'iap_transaction_id', "gang", "iapppay", "biogame_role"])
    #-----------------------帐号数据
    #########mac 登陆
    #mac地址查询
    global g_sql_map
    str += parse_sql_base.build_select_sql_all_by_field_list(['macAddress', ], 'account', 'login_by_MAC')
    #mac地址注册
    str += parse_sql_base.build_insert_sql_by_field_list(['macAddress', ], 'account','create_account_by_MAC') 
    #获得最大的accountid
    str += parse_sql_base.build_limit_select_sql_all_by_field_list([], 'account', "get_max_accountid_limit", "accountid", "1", True)
    #插入现有的mac地址账号
    str += parse_sql_base.build_insert_sql_by_field_list(['accountid', 'macAddress', ], 'account','insert_account_by_id_and_mac') 

    
    #-----------------------角色数据
    #用户名测试
    str += parse_sql_base.build_select_sql_all_by_field_list(['rolename'], 'role', 'check_rolename_exist')
    #创建角色,根据mac地址对应的account创建角色
    str += parse_sql_base.build_insert_sql_by_field_list(['rolename', 'accountid', 'professionId', ], 'role','create_role_by_accountid')
    #创建角色,使用通行证登录的创建角色
    str += parse_sql_base.build_insert_sql_by_field_list(['rolename', 'accountid', 'professionId', ], 'role','create_role_by_passport')
    #简单帐号验证成功以后，使用accountid, userid登陆 
    str += parse_sql_base.build_select_sql_all_by_field_list(['accountid', 'userid'], 'role', 'get_role_by_accountid_userid')
    #简单帐号验证成功以后，使用accountid创建,并且第一次获得
    str += parse_sql_base.build_select_sql_all_by_field_list(['accountid',], 'role', 'get_role_by_accountid_first')
    #记录回数据库
    str += parse_sql_base.build_update_sql_by_field_list([ "accountid", "rolename", "professionId", "money", "diamond", "vigor", "isInit", "loginCount", "lastLogoffTime", "todayFubenRecord", "todayPrizeRecord", "prizeRecord", "misc", "friends", "friendsApply", "package", "titles", "footmark", 'taskFinished', 'taskCurrent', 'currentGuid', 'paremeterMin', 'paremeterMax', 'paremeterNow' ], ['userid',], 'role','save_role_by_userid')
    #str += build_update_sql_by_field_list([ "accountid", "professionId", "showLevel", "loginCount", "equipmentStrengthen", "misc", 'todayPrizeRecord', 'prizeRecord', 'todayFubenRecord', 'wingCompoundStar', 'isInit',  'vigor', 'challengeRecord', 'exploit', 'diamond', 'money', 'itemsPacket', 'expTotal', 'popularity', 'exp', 'level', 'taskFinished', 'taskCurrent', 'currentGuid', 'wingPage', 'mates', 'randomRecruit', 'friends', 'friendsApply', 'playerTalks','nobility', 'lastLogoffTime', 'scenesdiscuss','coachs','roleClubCondition','roleIntoGameData','arrayEquipment','refreshItemArray','playerGuideRecord'], ['userid',], 'role','save_role_by_userid')
    #挑战记录写回数据库
    #str += build_update_sql_by_field_list([ 'challengeRecord', ], ['userid',], 'role','save_role_challenge_record_by_userid')
    #竞技场奖励声望写回数据库
    #str += build_update_sql_by_field_list([ 'popularity', ], ['userid',], 'role','save_role_popularity_by_userid')
    #挑战竞技场的时候,需要获得他人的信息,
    #str += build_select_sql_all_by_field_list(['userid',], 'role', 'get_challenge_target_role_by_userid')
    #使用userid登陆,
    str += parse_sql_base.build_select_sql_all_by_field_list(['userid',], 'role', 'get_role_by_userid')
    #获得最大的userid
    str += parse_sql_base.build_limit_select_sql_all_by_field_list([], 'role', "get_max_userid_limit", "userid", "1", True)
    #插入现成的角色
    #str += build_insert_sql_by_field_list(["accountid", 'challengeRecord', 'currentGuid', 'currentArrayId', 'diamond', 'exp', "equipmentStrengthen", 'exploit', 'expTotal', 'isInit',  'itemsPacket', "loginCount", 'level', "misc", 'money', 'mates', 'prizeRecord', "professionId", 'popularity', 'randomRecruit', 'rolename', "showLevel", 'starlevel', 'taskFinished', 'taskCurrent', 'todayPrizeRecord', 'todayFubenRecord', 'vigor', "userid", 'wingPage', 'wingCompoundStar', 'friends', 'friendsApply', 'playerTalks','nobility', 'lastLogoffTime','scenesdiscuss','coachs','roleClubCondition','roleIntoGameData','arrayEquipment','refreshItemArray','playerGuideRecord'], 'role','insert_role_all')
    #获取快照
    str += parse_sql_base.build_select_sql_by_field_list(['userid', 'professionId', 'rolename', 'lastLogoffTime', "misc", "friends"], [], "role", "get_all_role_snapshot")
    #根据mac地址获取角色列表
    str += parse_sql_base.build_select_sql_by_field_list_limit(["userid", "rolename"], ["accountid"], "role", "get_rolelist_by_accountid", "userid", "10", True)
    #角色改名字
    str += parse_sql_base.build_update_sql_by_field_list([ 'rolename', ], ['userid',], 'role','update_role_change_rolename_by_userid')
    
    
    #-----------------------竞技场数据
    #获得排行信息,前8个
    str += parse_sql_base.build_limit_select_sql_all_by_field_list([], 'rank', "get_all_rank_limit", "rankid", "30", False)
    #获得竞技场所有数据
    str += parse_sql_base.build_select_sql_all_by_field_list(['rankid',], 'rank', 'get_rank')
    #将排名记录回数据库
    str += parse_sql_base.build_update_sql_by_field_list(['ranklist','lastupdateTime'], ['rankid',], 'rank','save_rank')
    #创建排名记录
    str += parse_sql_base.build_insert_sql_by_field_list(['ranklist', 'rankid'], 'rank','insert_rank')
    #检查数据库保活
    str += parse_sql_base.build_select_sql_all_by_field_list(['rankid'], 'rank','check_rank_count')
    #-----------------------iap transaction购买记录
    #将iap记录从数据库读取
    str += parse_sql_base.build_select_sql_by_field_list(["userid", "transactionId"], [], "iap_transaction_id", "get_this_week_iap_transaction")
    #创建iap购买记录
    str += parse_sql_base.build_insert_sql_by_field_list(['userid', 'transactionId', 'purchaseDate', 'obtained', 'productId'], 'iap_transaction_id','insert_iap_transaction')
    #从数据库读取还未发放的充值结果 
    str += parse_sql_base.build_select_sql_all_by_field_list(['obtained',], 'iap_transaction_id', 'get_not_obtained_iap')
    #将领取记录回数据库
    str += parse_sql_base.build_update_sql_by_field_list(['obtained'], ['id',], 'iap_transaction_id','save_obtain_iap')
    #-----------------------帮派
    #将前100个帮派从数据库读取
    str += parse_sql_base.build_limit_select_sql_all_by_field_list([], 'gang', "get_all_gang_limit", "id", "100", False)
    #创建新帮会
    str += parse_sql_base.build_insert_sql_by_field_list(['joinList', 'createTime', 'ownerUserId', 'state', 'level', 'popularity', 'coffers', 'power', "name", "annoucement", "declaration", 'affairs', 'roleList', 'taskOrItemOrGems'], 'gang','insert_new_gang')
    #更新帮会数据
    str += parse_sql_base.build_update_sql_by_field_list(['joinList', 'createTime', 'ownerUserId', 'state', 'level', 'popularity', 'coffers', 'power', "name", "annoucement", "declaration",'affairs', 'roleList', 'taskOrItemOrGems', "gangPublicDailyTask", "gangMisc"], ['id',], 'gang','update_gang_by_id')
    
    #-------------------爱贝支付
    #插入新的支付数据
    str += parse_sql_base.build_insert_sql_by_field_list(['userid', 'ordNO', 'purchaseDate', 'payState', 'productId'], 'iapppay', "insert_new_iapppay_record")
    #查询充值数据
    str += parse_sql_base.build_limit_select_sql_all_by_field_list(['payState'], 'iapppay', "select_undefined_state_iapppay" , 'id', "100")
    #更新充值数据
    str += parse_sql_base.build_update_sql_by_field_list(['purchaseDate', 'payState'], ['ordNO'], 'iapppay', 'update_iapppay')
    #查询指定订单
    #str += build_limit_select_sql_all_by_field_list(['ordNO'], 'iapppay', 'select_ordNO_Info_iapppay','id', "100")
       
    str += "\n\n"
    str += parse_sql_base.build_wrap_struct("")
    str += parse_sql_base.build_operation_enum("")
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

    
main('../../../server/common_interface/SqlOperationHlp.h')
