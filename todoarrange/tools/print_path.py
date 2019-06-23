# -*- coding: utf-8 -*-
import sys
import os
import string

l_all_path= []
def print_all(rootPath):
    l_all_path.append(rootPath)
    l = os.listdir(rootPath)
    for f in sorted(l):
        if os.path.isdir(rootPath+'/'+f):
            if f.find(".svn") == -1:
                l_all_path.append(rootPath+'/'+f)
                print_all(rootPath+'/'+f)
            
            
def build_Path(l_path):
    template = """################ PATH 文件夹目录#####################
    set(PATH_CUR "./")
    %(path_template)s

"""
    list_path_template = []
    for p in l_path:
        s = p.replace("/", "_").replace(":", "")
        
        list_path_template.append("""set(PATH_%(s)s "%(p)s")"""%(locals()))
    path_template = "\n".join(list_path_template) 
    return template%(locals())
        
def build_include(l_path):
    template = """################ INCLUDE 头文件路径#####################
%(path_template)s
    """        
    list_path_template = []
    for p in l_path:
        s = p.replace("/", "_").replace(":", "")
        list_path_template.append("""include_directories("${PATH_%(s)s}")"""%(locals()))
    path_template = "\n".join(list_path_template) 
    return template%(locals())

def build_source_files(l_path):
    template = """################ SOURCE_FILES 源文件#####################
%(path_template)s
    """        
    list_path_template = []
    for p in l_path:
        s = p.replace("/", "_").replace(":", "")
        list_path_template.append("""AUX_SOURCE_DIRECTORY(${PATH_%(s)s} SOURCE_FILES)"""%(locals()))
    path_template = "\n".join(list_path_template) 
    return template%(locals())

def build_head_files(l_path):
    template = """################ HEAD_FILES 头文件#####################
%(path_template)s
    """        
    list_path_template = []
    for p in l_path:
        s = p.replace("/", "_").replace(":", "")
        list_path_template.append("""FILE(GLOB_RECURSE  HEAD_FILES_%(s)s "${PATH_%(s)s}/*.lua")"""%(locals()))
    path_template = "\n".join(list_path_template) 
    return template%(locals())

def build_set_head_files(l_path):
    template = """################ HEAD_FILES 设置头文件#####################
set(HEAD_FILES 
%(path_template)s        
        )
    """        
    list_path_template = []
    for p in l_path:
        s = p.replace("/", "_").replace(":", "")
        list_path_template.append("""${HEAD_FILES_%(s)s}"""%(locals()))
    path_template = "\n".join(list_path_template) 
    return template%(locals())


#print_all("C:/work/code/ClientBase/EEE/Source")

print_all("C:/work/code/cocos2d-x-2.2.2/projects/bioGameLua/Resources/script")
print build_Path(l_all_path)
print build_include(l_all_path)
print build_source_files(l_all_path)
print build_head_files(l_all_path)
print build_set_head_files(l_all_path)

