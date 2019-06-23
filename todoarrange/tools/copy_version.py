import os
import os.path
import shutil
def copytree(src, dst, symlinks=False):
    names = os.listdir(src)
    if not os.path.isdir(dst):
        os.makedirs(dst)
          
    errors = []
    for name in names:
        srcname = os.path.join(src, name)
        dstname = os.path.join(dst, name)
        try:
            if symlinks and os.path.islink(srcname):
                linkto = os.readlink(srcname)
                os.symlink(linkto, dstname)
            elif os.path.isdir(srcname):
                copytree(srcname, dstname, symlinks)
            else:
                if os.path.isdir(dstname):
                    os.rmdir(dstname)
                elif os.path.isfile(dstname):
                    os.remove(dstname)
                shutil.copy2(srcname, dstname)
            # XXX What about devices, sockets etc.?
        except (IOError, os.error) as why:
            errors.append((srcname, dstname, str(why)))
        # catch the Error from the recursive copytree so that we can
        # continue with other files
        except OSError as err:
            errors.extend(err.args[0])
    try:
        shutil.copystat(src, dst)
    except WindowsError:
        # can't copy file access times on Windows
        pass
    except OSError as why:
        errors.extend((src, dst, str(why)))
    if errors:
        raise Error(errors)

def build_temp_gameserver(src, temp):
    copytree(src+"/cfg", temp+"/cfg")
    copytree(src+"/gameserver", temp+"/gameserver")
    copytree(src+"/tools", temp+"/tools")
    shutil.copyfile(src+"/auto_commit.bat", temp+"/auto_commit.bat")
    shutil.copyfile(src+"/init_svn.bat", temp+"/init_svn.bat")
    
def build_temp_passportserver(src, temp):
    copytree(src+"/cfg", temp+"/cfg")
    copytree(src+"/passportserver", temp+"/passportserver")
    copytree(src+"/tools", temp+"/tools")

def do_copy(src, targetlist):
    for t in targetlist:
        copytree(src, t)
        
g_target_gameserver_list = [
                 "E:/test_cpy/server_1",
                 "E:/test_cpy/server_2",
                 ]
g_src = "E:/code/X_H_W-2013/Bin/Server"
g_temp_gameserver = "E:/test_cpy/standard_version"

copytree(g_src+"/../../Server/tools", g_src+"/tools")
build_temp_gameserver(g_src, g_temp_gameserver)
do_copy(g_temp_gameserver, g_target_gameserver_list)
print "OK"
g_target_passport_list = [
                          "E:/test_cpy/passport_2"
                          ]
g_temp_passportserver = "E:/test_cpy/passport_version"

build_temp_passportserver(g_src, g_temp_passportserver)
do_copy(g_temp_passportserver, g_target_passport_list)



