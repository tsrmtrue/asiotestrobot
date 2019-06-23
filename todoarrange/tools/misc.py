# -*- coding: utf8 -*-
import sys
print sys.getdefaultencoding()
import json
print json.loads('{"errcode":0,"roleCount":1,"roles":[{"roleBasic":{"guid":17,"macAddress":"rrr","rolename":"hello","level":1,"hpTrainAdd":0,"strTrainAdd":0,"intTrainAdd":0,"agiTrainAdd":0,"professionId":4550,"exp":0,"popularity":0,"expTotal":0,"equipmentCount":0,"equipment":[0,0]},"itemCount":0,"itemsPacket":[0,0],"itemInventoryCount":0,"itemsInventory":[0,0],"gemForEquipmentCount":0,"gemForEquipment":[0,0],"gemTemoCount":0,"gemTemp":[0,0],"mercsCount":0,"mercsArray":[0,0],"hireHistoryCount":0,"hireHistory":[0,0]}]}')
s="属性更改"
print "%r" %("是".encode('utf8'))
print     """mp["%r"] = E_BUFF_EFFECT_ATTR_CHANGE;"""%(s.encode('utf8'))



CREATE TABLE rank (
  id INTEGER(11) NOT NULL unique COMMENT 'just convenient for sql',
  ranklist BLOB COMMENT 'rank list like int[]',
)ENGINE=MyISAM,
AUTO_INCREMENT=48 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';



s = "属性修改".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_ATTR_CHANGE;//%(s)s"""%(locals())

s = "控制状态".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_STATE_CONTROL;//%(s)s"""%(locals())

s = "施放技能".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_CAST_SKILL;//%(s)s"""%(locals())

s = "免疫状态".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_IMMUNE;//%(s)s"""%(locals())

s = "消失触发".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_TRIGGER_WHEN_DISAPPEAR;//%(s)s"""%(locals())

s = "怒气".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_ANGER;//%(s)s """%(locals())

s = "生命".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_HP;//%(s)s """%(locals())

s = "体力".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_CD;//%(s)s """%(locals())

s = "物理防御".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_PSYDEF; """%(locals())

s = "物理攻击".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_PSYATK;//%(s)s """%(locals())

s = "法术攻击".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_MAGIATK;//%(s)s """%(locals())

s = "法术防御".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_MAGIDEF;//%(s)s """%(locals())

s = "技能攻击".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_SKILLATK;//%(s)s """%(locals())

s = "技能防御".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_SKILLDEF;//%(s)s """%(locals())

s = "爆击值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_CRIT;//%(s)s """%(locals())

s = "闪避值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_DODGE;//%(s)s """%(locals())

s = "命中值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_ACCURATE;//%(s)s """%(locals())

s = "反击值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_COUNTERSTRIKE;//%(s)s """%(locals())

s = "格挡值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_BLOCK;//%(s)s """%(locals())

s = "破挡值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_BREAK_BLOCK;//%(s)s """%(locals())

s = "晕眩".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_STATE_DAZE;//%(s)s """%(locals())

s = "混乱".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_STATE_CHAOS;//%(s)s """%(locals())

s = "免伤".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_AVOID_HARM;//%(s)s """%(locals())

s = "数值".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NUMERIC;//%(s)s """%(locals())

s = "最大值千分比".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PERCENT_THOUSAND_MAX;//%(s)s """%(locals())

s = "当前值千分比".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PERCENT_THOUSAND_CURRENT;//%(s)s """%(locals())

s = "减少".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_DEC;//%(s)s """%(locals())

s = "增加".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ADD;//%(s)s"""%(locals())

s = "是".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_YES;//%(s)s """%(locals())

s = "否".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NO;//%(s)s """%(locals())

s = "骑士".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_KNIGHT;//%(s)s """%(locals())

s = "剑士".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_SWARDMAN;//%(s)s """%(locals())

s = "弓手".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ARCHER;//%(s)s """%(locals())

s = "法师".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ENCHANTER;//%(s)s """%(locals())

s = "武僧".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_MONK_WARRIOR;//%(s)s """%(locals())

s = "刺客".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ASSASSIN;//%(s)s """%(locals())

s = "狂战".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_BERSERKER;//%(s)s """%(locals())

s = "祭司".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_FLAMEN;//%(s)s """%(locals())

s = "先知".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ORACLE;//%(s)s """%(locals())

s = "全职业".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ALL;//%(s)s """%(locals())

s = "白色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_WHITE;//%(s)s """%(locals())

s = "绿色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_GREEN;//%(s)s """%(locals())

s = "蓝色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_BLUE;//%(s)s """%(locals())

s = "紫色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_PURPLE;//%(s)s """%(locals())

s = "金色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_GOLDEN;//%(s)s """%(locals())

s = "彩色".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_ALL;//%(s)s """%(locals())

s = "目标".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TARGET_TARGET;//%(s)s """%(locals())

s = "自己".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TARGET_SELF;//%(s)s """%(locals())

s = "单人".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_SINGLE;//%(s)s """%(locals())

s = "后方".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_BACK;//%(s)s """%(locals())

s = "横向直线".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_ROW;//%(s)s """%(locals())

s = "纵向直线".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_COLUM;//%(s)s """%(locals())

s = "全体".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_ALL;//%(s)s """%(locals())

s = "十字".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_CROSS;//%(s)s """%(locals())

s = "后方纵向直线".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_BACK_LINE;//%(s)s """%(locals())

s = "近程".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NEAR;//%(s)s"""%(locals())

s = "远程".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_FAR;//%(s)s """%(locals())

s = "物理伤害".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PSY_HURT;//%(s)s """%(locals())

s = "法术伤害".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MAGI_HURT;//%(s)s """%(locals())

s = "技能伤害".encode('utf8')
print """    mp["%(s2)s"] = E_SKILL_HURT;//%(s)s """%(locals())

s = "回复生命".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_RECOVER_HP;//%(s)s """%(locals())

s = "回复怒气".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_RECOVER_ANGER;//%(s)s """%(locals())

s = "上沿触发".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TRIGGER_UP;//%(s)s """%(locals())

s = "间隔触发".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TRIGGER_TIMER;//%(s)s """%(locals())

s = "(可接)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "(未完成)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "(已经完成)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "头盔".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_HELMET;//%(s)s """%(locals())

s = "武器".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_WEAPON;//%(s)s """%(locals())

s = "手套".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_GLOVES;//%(s)s """%(locals())


s = "胸甲".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_CLOTH;//%(s)s """%(locals())

s = "靴子".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_SHOE;//%(s)s """%(locals())

s = "腰带".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_BELT;//%(s)s """%(locals())

s = "戒指".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_RING;//%(s)s """%(locals())

s = "项链".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_NECKLACES;//%(s)s """%(locals())

s = "护符".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_AMULATES;//%(s)s """%(locals())

s = "礼包".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_GIFT_PACKET;//%(s)s """%(locals())

s = "功勋".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_EXPLOIT;//%(s)s """%(locals())

s = "金币".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_GOLD;//%(s)s """%(locals())

s = "物品".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_ITEM;//%(s)s """%(locals())

s = "声望".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_POPULARITY;//%(s)s """%(locals())

s = "伙伴".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_MATE;//%(s)s """%(locals())

s = "钻石".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_DIAMOND;//%(s)s """%(locals())

s = "普通".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_NORMAL;//%(s)s """%(locals())

s = "将".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GENERAL;//%(s)s """%(locals())

s = "王".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_KING;//%(s)s """%(locals())

s = "皇".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_EMPEROR;//%(s)s """%(locals())

s = "圣".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_INVIOLABILITY;//%(s)s """%(locals())

s = "神".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_IMMORTAL;//%(s)s """%(locals())

s = "天".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GOD;//%(s)s """%(locals())

s = "鬼".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GHOST;//%(s)s """%(locals())
