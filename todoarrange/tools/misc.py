# -*- coding: utf8 -*-
import sys
print sys.getdefaultencoding()
import json
print json.loads('{"errcode":0,"roleCount":1,"roles":[{"roleBasic":{"guid":17,"macAddress":"rrr","rolename":"hello","level":1,"hpTrainAdd":0,"strTrainAdd":0,"intTrainAdd":0,"agiTrainAdd":0,"professionId":4550,"exp":0,"popularity":0,"expTotal":0,"equipmentCount":0,"equipment":[0,0]},"itemCount":0,"itemsPacket":[0,0],"itemInventoryCount":0,"itemsInventory":[0,0],"gemForEquipmentCount":0,"gemForEquipment":[0,0],"gemTemoCount":0,"gemTemp":[0,0],"mercsCount":0,"mercsArray":[0,0],"hireHistoryCount":0,"hireHistory":[0,0]}]}')
s="���Ը���"
print "%r" %("��".encode('utf8'))
print     """mp["%r"] = E_BUFF_EFFECT_ATTR_CHANGE;"""%(s.encode('utf8'))



CREATE TABLE rank (
  id INTEGER(11) NOT NULL unique COMMENT 'just convenient for sql',
  ranklist BLOB COMMENT 'rank list like int[]',
)ENGINE=MyISAM,
AUTO_INCREMENT=48 CHARACTER SET 'utf8' COLLATE 'utf8_general_ci';



s = "�����޸�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_ATTR_CHANGE;//%(s)s"""%(locals())

s = "����״̬".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_STATE_CONTROL;//%(s)s"""%(locals())

s = "ʩ�ż���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_CAST_SKILL;//%(s)s"""%(locals())

s = "����״̬".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_IMMUNE;//%(s)s"""%(locals())

s = "��ʧ����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BUFF_EFFECT_TRIGGER_WHEN_DISAPPEAR;//%(s)s"""%(locals())

s = "ŭ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_ANGER;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_HP;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_CD;//%(s)s """%(locals())

s = "�������".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_PSYDEF; """%(locals())

s = "������".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_PSYATK;//%(s)s """%(locals())

s = "��������".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_MAGIATK;//%(s)s """%(locals())

s = "��������".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_MAGIDEF;//%(s)s """%(locals())

s = "���ܹ���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_SKILLATK;//%(s)s """%(locals())

s = "���ܷ���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_SKILLDEF;//%(s)s """%(locals())

s = "����ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_CRIT;//%(s)s """%(locals())

s = "����ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_DODGE;//%(s)s """%(locals())

s = "����ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_ACCURATE;//%(s)s """%(locals())

s = "����ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_COUNTERSTRIKE;//%(s)s """%(locals())

s = "��ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_BLOCK;//%(s)s """%(locals())

s = "�Ƶ�ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_BASIC_ATTR_BREAK_BLOCK;//%(s)s """%(locals())

s = "��ѣ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_STATE_DAZE;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_STATE_CHAOS;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_AVOID_HARM;//%(s)s """%(locals())

s = "��ֵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NUMERIC;//%(s)s """%(locals())

s = "���ֵǧ�ֱ�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PERCENT_THOUSAND_MAX;//%(s)s """%(locals())

s = "��ǰֵǧ�ֱ�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PERCENT_THOUSAND_CURRENT;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_DEC;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ADD;//%(s)s"""%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_YES;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NO;//%(s)s """%(locals())

s = "��ʿ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_KNIGHT;//%(s)s """%(locals())

s = "��ʿ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_SWARDMAN;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ARCHER;//%(s)s """%(locals())

s = "��ʦ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ENCHANTER;//%(s)s """%(locals())

s = "��ɮ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_MONK_WARRIOR;//%(s)s """%(locals())

s = "�̿�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ASSASSIN;//%(s)s """%(locals())

s = "��ս".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_BERSERKER;//%(s)s """%(locals())

s = "��˾".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_FLAMEN;//%(s)s """%(locals())

s = "��֪".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ORACLE;//%(s)s """%(locals())

s = "ȫְҵ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PROFESSION_ALL;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_WHITE;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_GREEN;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_BLUE;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_PURPLE;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_GOLDEN;//%(s)s """%(locals())

s = "��ɫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_ITEM_COLOR_ALL;//%(s)s """%(locals())

s = "Ŀ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TARGET_TARGET;//%(s)s """%(locals())

s = "�Լ�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TARGET_SELF;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_SINGLE;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_BACK;//%(s)s """%(locals())

s = "����ֱ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_ROW;//%(s)s """%(locals())

s = "����ֱ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_COLUM;//%(s)s """%(locals())

s = "ȫ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_ALL;//%(s)s """%(locals())

s = "ʮ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_CROSS;//%(s)s """%(locals())

s = "������ֱ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_SCALE_BACK_LINE;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_NEAR;//%(s)s"""%(locals())

s = "Զ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_FAR;//%(s)s """%(locals())

s = "�����˺�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PSY_HURT;//%(s)s """%(locals())

s = "�����˺�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MAGI_HURT;//%(s)s """%(locals())

s = "�����˺�".encode('utf8')
print """    mp["%(s2)s"] = E_SKILL_HURT;//%(s)s """%(locals())

s = "�ظ�����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_RECOVER_HP;//%(s)s """%(locals())

s = "�ظ�ŭ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_RECOVER_ANGER;//%(s)s """%(locals())

s = "���ش���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TRIGGER_UP;//%(s)s """%(locals())

s = "�������".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_TRIGGER_TIMER;//%(s)s """%(locals())

s = "(�ɽ�)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "(δ���)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "(�Ѿ����)".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = ;//%(s)s """%(locals())

s = "ͷ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_HELMET;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_WEAPON;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_GLOVES;//%(s)s """%(locals())


s = "�ؼ�".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_CLOTH;//%(s)s """%(locals())

s = "ѥ��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_SHOE;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_BELT;//%(s)s """%(locals())

s = "��ָ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_RING;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_NECKLACES;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_PART_AMULATES;//%(s)s """%(locals())

s = "���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_GIFT_PACKET;//%(s)s """%(locals())

s = "��ѫ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_EXPLOIT;//%(s)s """%(locals())

s = "���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_GOLD;//%(s)s """%(locals())

s = "��Ʒ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_ITEM;//%(s)s """%(locals())

s = "����".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_POPULARITY;//%(s)s """%(locals())

s = "���".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_MATE;//%(s)s """%(locals())

s = "��ʯ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_OBJ_DIAMOND;//%(s)s """%(locals())

s = "��ͨ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_NORMAL;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GENERAL;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_KING;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_EMPEROR;//%(s)s """%(locals())

s = "ʥ".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_INVIOLABILITY;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_IMMORTAL;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GOD;//%(s)s """%(locals())

s = "��".encode('utf8')
s2 = """%r"""%(s)
s2 = s2[1:-1]
print """    mp["%(s2)s"] = E_MATE_QUALITY_GHOST;//%(s)s """%(locals())
