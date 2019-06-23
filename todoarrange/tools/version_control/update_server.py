# -*- coding: gbk -*-
import os
import os.path
import sys
sys.path.append('../')
import init_tool
import version_control_global_setting as vcgs
import server_config_parse as scp

def get_server_instance_name(isPassport=False):
    if isPassport:
        return "passport_server_"
    else :
        return "lj_server_"
    
def get_server_id_filename(isPassport=False):
    if isPassport:
        return "passport_server_id.txt"
    else :
        return "server_id.txt"
    
def get_init_db_file(isPassport=False):
    if isPassport:
        return "init_db_passport.py"
    else :
        return "init_db.py"
    
def update_server_instance(server_version, server_id, isPassport):
    #创建目标新目录
    instance_path = vcgs.g_server_instance_path
    server_instance_name = get_server_instance_name(isPassport)
    new_server_path = "%(instance_path)s/%(server_instance_name)s%(server_id)d"%(locals())
    if not os.path.isdir(new_server_path):
        print "the server path not exists ",new_server_path
        return False
    #拷贝server目录
    unzip_path = vcgs.g_unzip_path
    src_path = "%(unzip_path)s/%(server_version)s"%(locals())
    try:
        vcgs.copytree(src_path, new_server_path)
    except Error as e:
        print e
        return False
    #id的配置
    server_id_filename = get_server_id_filename(isPassport)
    w = open('%(new_server_path)s/%(server_id_filename)s'%(locals()), 'w')
    w.write("%(server_id)d"%(locals()))
    w.close()
    
    #配置脚本生成
    server_conf_dict_file = new_server_path + "/cfg/fuwuqipeizhi_utf8.csv"
    server_conf_dict = scp.get_server_cfg(server_conf_dict_file, server_id)
    os.chdir("%(new_server_path)s/tools"%(locals()))
    w = open("server_cfg.py", 'w')
    w.write(init_tool.get_server_cfg(server_conf_dict))
    w.close()
    w = open("global_path.py", 'w')
    w.write(init_tool.get_global_cfg())
    w.close()


    
update_server_instance("Server_2013_09_25_23_25_29.83", 7, False)
#update_server_instance("Passport_Server_2013_09_12_16_59_26.84", 10003, True)

print "OK"

