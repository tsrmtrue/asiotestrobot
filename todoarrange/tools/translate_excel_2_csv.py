#-*- coding:utf8 -*-

import xlrd
import string
import codecs
import types

def translateValue2String(value):
    #print type(value.value)
    if type(value.value) is types.UnicodeType:
        s = "%s"%(value.value.encode("utf8"))
        if s.find(",") <> -1:
            #print s
            s = s.replace(",", "\xef\xbc\x8c")
            #print s
        if s.find("\n") <> -1:
            print "unicode found \\n"
            print s
            s = s.replace("\n", "")
            print s
        return s
    if types.FloatType == type(value.value):
        return "%d"%(value.value)
    if types.StringType == type(value.value):
        s = "%s"%(value.value)
        if s.find(",") <> -1:
            #print s
            s = s.replace(",", "\xef\xbc\x8c")
            #print s
        if s.find("\n") <> -1:
            print "string found \\n"
            print s
            s = s.replace("\r\n", "")
            print s
        return s
    

def translateSheet2String(sheet):
    l = list()
    for r in range(0, sheet.nrows):
        row = sheet.row(r)
        #print row
        l.append(string.join(map(translateValue2String, row), ",").replace("''", ""))
    return string.join(l, "\n")

def translateExcel2Csv(excelPath, csvPath, sheet="Sheet1"):
    try :
        #print codecs.getdecoder(excelPath)
        p1 = excelPath.decode("utf8").encode("gbk")
        #print p1
        workbook = xlrd.open_workbook(p1)
        sheet = workbook.sheet_by_name(sheet)
        w = open(csvPath, 'w')
        s=translateSheet2String(sheet)
        print s
        
        w.write("\xEF\xBB\xBF"+s+"\x0a")
        w.close()
    except:
        print "error"
        pass

from build_cpp_config import *
'../../Document/配置表'
'../../Bin'
def translateExcelAndParse_4_cocos(excelFilePath, targetPath):
    
#    translateExcel2Csv(excelFilePath+'/.xlsx', targetPath+"/_utf8.csv")
#    parseFile(targetPath+'/_utf8.csv', '')

    translateExcel2Csv(excelFilePath+'/题目库.xlsx', targetPath+"/timuku_utf8.csv")
    parseFile(targetPath+'/timuku_utf8.csv', 'QuizConfig')
    
    
    translateExcel2Csv(excelFilePath+'/女主角表.xlsx', targetPath+"/girls_utf8.csv")
    parseFile(targetPath+'/girls_utf8.csv', 'GirlsConfig')

    translateExcel2Csv(excelFilePath+'/玩家台词表.xlsx', targetPath+"/player_words_utf8.csv")
    parseFile(targetPath+'/player_words_utf8.csv', 'PlayerWordsConfig')

    translateExcel2Csv(excelFilePath+'/npc对话池_公共.xlsx', targetPath+"/npcWordsPool_public_utf8.csv")
    parseFile(targetPath+'/npcWordsPool_public_utf8.csv', 'NpcWordsPoolPublicConfig')

    translateExcel2Csv(excelFilePath+'/npc对话池_私人定制.xlsx', targetPath+"/npcWordsPool_private_utf8.csv")
    parseFile(targetPath+'/npcWordsPool_private_utf8.csv', 'NpcWordsPoolPrivateConfig')

    translateExcel2Csv(excelFilePath+'/npc好感度回答_私人定制.xlsx', targetPath+"/npc_answer_private_utf8.csv")
    parseFile(targetPath+'/npc_answer_private_utf8.csv', 'NpcAnswerPrivateConfig')

    translateExcel2Csv(excelFilePath+'/称号开放台词表.xlsx', targetPath+"/title2playerWords_utf8.csv")
    parseFile(targetPath+'/title2playerWords_utf8.csv', 'Title2PlayerWordsConfig')

    translateExcel2Csv(excelFilePath+'/场景选择对话池.xlsx', targetPath+"/scene2wordsPools_utf8.csv")
    parseFile(targetPath+'/scene2wordsPools_utf8.csv', 'scene2wordsPoolsConfig')
    
    translateExcel2Csv(excelFilePath+'/动作表.xlsx', targetPath+"/motion_utf8.csv")
    parseFile(targetPath+'/motion_utf8.csv', 'MotionConfig')
    
    translateExcel2Csv(excelFilePath+'/场景表.xlsx', targetPath+"/scene_utf8.csv")
    parseFile(targetPath+'/scene_utf8.csv', 'SceneConfig')

    translateExcel2Csv(excelFilePath+'/道具表.xlsx', targetPath+"/goods_utf8.csv")
    parseFile(targetPath+'/goods_utf8.csv', 'GoodsConfig')

    translateExcel2Csv(excelFilePath+'/语音表.xlsx', targetPath+"/music_utf8.csv")
    parseFile(targetPath+'/music_utf8.csv', 'MusicConfig')
    
    
    
    writeStructHFile('../Common/Configure/ConfigureStruct.h')
    writeHFile('../Common/Configure/ConfigureParser.h')
    writeCppFile('../Common/Configure/ConfigureParser.cpp', True)

def translateExcelAndParse(excelFilePath, targetPath):
    
#    translateExcel2Csv(excelFilePath+'/.xlsx', targetPath+"/_utf8.csv")
#    parseFile(targetPath+'/_utf8.csv', '')

    translateExcel2Csv(excelFilePath+'/服务器配置.xls', targetPath+"/Server/cfg/fuwuqipeizhi_utf8.csv")
    parseFile(targetPath+'/Server/cfg/fuwuqipeizhi_utf8.csv', 'ServerConfig')
    translateExcel2Csv(excelFilePath+'/服务器模块定义表.xls', targetPath+"/Server/cfg/fuwuqimokuaidingyi_utf8.csv")
    parseFile(targetPath+'/Server/cfg/fuwuqimokuaidingyi_utf8.csv', 'ServerBusinessConfig')
    
    translateExcel2Csv(excelFilePath+'/服务器模块分布表.xls', targetPath+"/Server/cfg/fuwuqimokuaifenbu_utf8.csv")
    parseFile(targetPath+'/Server/cfg/fuwuqimokuaifenbu_utf8.csv', 'ServerBusinessDeploymentConfig')
    translateExcel2Csv(excelFilePath+'/题目库.xlsx', targetPath+"/Server/cfg/timuku_utf8.csv")
    parseFile(targetPath+'/Server/cfg/timuku_utf8.csv', 'QuizConfig')
    
    
    translateExcel2Csv(excelFilePath+'/女主角表.xlsx', targetPath+"/Server/cfg/girls_utf8.csv")
    parseFile(targetPath+'/Server/cfg/girls_utf8.csv', 'GirlsConfig')

    translateExcel2Csv(excelFilePath+'/玩家台词表.xlsx', targetPath+"/Server/cfg/player_words_utf8.csv")
    parseFile(targetPath+'/Server/cfg/player_words_utf8.csv', 'PlayerWordsConfig')

    translateExcel2Csv(excelFilePath+'/npc对话池_公共.xlsx', targetPath+"/Server/cfg/npcWordsPool_public_utf8.csv")
    parseFile(targetPath+'/Server/cfg/npcWordsPool_public_utf8.csv', 'NpcWordsPoolPublicConfig')

    translateExcel2Csv(excelFilePath+'/npc对话池_私人定制.xlsx', targetPath+"/Server/cfg/npcWordsPool_private_utf8.csv")
    parseFile(targetPath+'/Server/cfg/npcWordsPool_private_utf8.csv', 'NpcWordsPoolPrivateConfig')

    translateExcel2Csv(excelFilePath+'/npc好感度回答_私人定制.xlsx', targetPath+"/Server/cfg/npc_answer_private_utf8.csv")
    parseFile(targetPath+'/Server/cfg/npc_answer_private_utf8.csv', 'NpcAnswerPrivateConfig')

    translateExcel2Csv(excelFilePath+'/称号开放台词表.xlsx', targetPath+"/Server/cfg/title2playerWords_utf8.csv")
    parseFile(targetPath+'/Server/cfg/title2playerWords_utf8.csv', 'Title2PlayerWordsConfig')

    translateExcel2Csv(excelFilePath+'/场景选择对话池.xlsx', targetPath+"/Server/cfg/scene2wordsPools_utf8.csv")
    parseFile(targetPath+'/Server/cfg/scene2wordsPools_utf8.csv', 'scene2wordsPoolsConfig')
    
    translateExcel2Csv(excelFilePath+'/动作表.xlsx', targetPath+"/Server/cfg/motion_utf8.csv")
    parseFile(targetPath+'/Server/cfg/motion_utf8.csv', 'MotionConfig')
    
    translateExcel2Csv(excelFilePath+'/场景表.xlsx', targetPath+"/Server/cfg/scene_utf8.csv")
    parseFile(targetPath+'/Server/cfg/scene_utf8.csv', 'SceneConfig')

    translateExcel2Csv(excelFilePath+'/道具表.xlsx', targetPath+"/Server/cfg/goods_utf8.csv")
    parseFile(targetPath+'/Server/cfg/goods_utf8.csv', 'GoodsConfig')

    translateExcel2Csv(excelFilePath+'/语音表.xlsx', targetPath+"/Server/cfg/music_utf8.csv")
    parseFile(targetPath+'/Server/cfg/music_utf8.csv', 'MusicConfig')

    translateExcel2Csv(excelFilePath+'/剧本表.xlsx', targetPath+"/Server/cfg/stage_utf8.csv")
    parseFile(targetPath+'/Server/cfg/stage_utf8.csv', 'StageConfig')


    writeStructHFile('../Common/Configure_server/ConfigureStruct.h')
    writeHFile('../Common/Configure_server/ConfigureParser.h')
    writeCppFile('../Common/Configure_server/ConfigureParser.cpp')



translateExcelAndParse('../configure/配置表', '../server/Bin')


# translateExcelAndParse_4_cocos('../configure/配置表', '../clientResource/config')

print "OK!"

