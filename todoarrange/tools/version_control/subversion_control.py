# -*- coding: gbk -*-
import os
import os.path

import version_control_global_setting as vcgs

#更新svn
def update_svn():
    subversion_path = vcgs.g_subversion_path 
    os.system("%(subversion_path)s/update.bat"%(locals()))

#解压缩指定的server版本
def unzip_server(server_version):
    server_zip_file = vcgs.g_subversion_path + "/"+server_version+".7z"
    unzip_path = vcgs.g_unzip_path + "/" + server_version
    print "7z x \"%(server_zip_file)s\" -o\"%(unzip_path)s\" -y"%(locals())
    os.system("7z x \"%(server_zip_file)s\" -o\"%(unzip_path)s\" -y"%(locals()))

#解压缩mysql版本
def unzip_mysql():
    mysql_zip_file = vcgs.g_subversion_path + "/" + vcgs.g_mysql_zip_file
    unzip_path = vcgs.g_unzip_path
    print "7z x \"%(mysql_zip_file)s\" -o%(unzip_path)s -y"%(locals())
    os.system("7z x \"%(mysql_zip_file)s\" -o\"%(unzip_path)s\" -y"%(locals()))
    
#unzip_mysql()
#unzip_server("Passport_Server_2013_09_11_21_33_04.48")
unzip_server("Server_2013_09_26_14_20_35.72")
#update_svn()
