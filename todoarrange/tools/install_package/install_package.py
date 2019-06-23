# -*- coding: gbk -*-
import sys
sys.path.append('../')
import global_path
import os

def build_7z(path, targetList):
    os.system("cd %s"%(path))
    targetstr =  " ".join(targetList)
    print targetstr
    zipname = "helloworld"
    os.system("7z a %(zipname)s.7z %(targetstr)s"%(locals()))
    
build_7z("E:\\code\\X_H_W-2013\\Bin\\Server", ["cfg", "gameserver", "init_svn.bat"])    