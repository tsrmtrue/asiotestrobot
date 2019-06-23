# -*- coding: utf-8 -*-

import sys
sys.path.append('..')
sys.path.append('../autotest_lib')


# import build_lua_json_struct_str
# build_lua_json_struct_str.main()
# print "1"
# import build_coding_4_cpp
# build_coding_4_cpp.main()
# print "2"
# import build_coding_4_lua
# build_coding_4_lua.main()
# print "3"
#import build_coding_4_cpp_export
#build_coding_4_cpp_export.main()
# print "4"


import build_coding_4_cpp
build_coding_4_cpp.parseHFileWithTarget("../../Common/ProtocolsPNL/pnl_protocol.h", "../../Common/ProtocolsPNL/pnl_protocol_encode.h","../../Common/ProtocolsPNL/pnl_protocol_encode.cpp","../../Common/ProtocolsPNL/pnl_protocol_decode.h","../../Common/ProtocolsPNL/pnl_protocol_decode.cpp")
print "2"
# import build_coding_4_java
# build_coding_4_java.parseHFileWithTarget("..\..\Common\ProtocolsPNL\pnl_protocol.h", "..\..\Common\ProtocolsPNL\CPnlProtocol.java")

import build_coding_4_py
build_coding_4_py.parseAndBuild("../../Common/ProtocolsPNL/pnl_protocol.h", moduleName="PNL", protocolEnum="EProtocolId", relativePath="../")

import build_coding_4_lua
build_coding_4_lua.parseHFileWithTarget("../../Common/ProtocolsPNL/pnl_protocol.h", "../../Common/ProtocolsPNL/pnl_protocol_encode.lua", "../../Common/ProtocolsPNL/pnl_protocol_decode.lua")

import build_lua_json_struct_str
build_lua_json_struct_str.parseHFile2LuaProtocol("../../Common/ProtocolsPNL/pnl_protocol.h", "../../Common/ProtocolsPNL/pnl_protocol_enum.lua", "../../Common/ProtocolsPNL/pnl_protocol_table_struct.lua")


print "all ok"


