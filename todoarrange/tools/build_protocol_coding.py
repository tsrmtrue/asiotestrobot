# -*- coding: gbk -*-
import build_lua_json_struct_str
build_lua_json_struct_str.main()
print "1"
import build_coding_4_cpp
build_coding_4_cpp.main()
print "2"
import build_coding_4_lua
build_coding_4_lua.main()
print "3"
#import build_coding_4_cpp_export
#build_coding_4_cpp_export.main()
print "4"
# import build_coding_4_py
# build_coding_4_py.main()

#特殊处理,将脚本拷贝到客户端包中
# import os
# lobby_path="""C:\\work\\code\\cocos\\cocos2d-x-2.2.2\\projects\\bioGameLua\\packed_scene\\1"""
# os.system("""xcopy "..\Common\Protocols\protocols_table_function.lua" %(lobby_path)s /Y"""%(locals()))
# os.system("""xcopy "..\Common\Protocols\protocolEncode4lua.lua" %(lobby_path)s /Y"""%(locals()))
# os.system("""xcopy "..\Common\Protocols\protocolDecode4lua.lua" %(lobby_path)s /Y"""%(locals()))
# os.system("""xcopy "..\Common\Protocols\protocol_enums.lua" %(lobby_path)s /Y"""%(locals()))

print "all ok"
