# -*- coding: utf-8 -*-
# 这里的脚本其实在另外一个abandon目录下，没有同步过来。

# import build_lua_json_struct_str
# build_lua_json_struct_str.mainPassport()
# import build_coding_4_cpp
# build_coding_4_cpp.mainPassport()
# import build_coding_4_lua
# build_coding_4_lua.mainPassport()
# import build_coding_4_py
# build_coding_4_py.mainPassport()


# import build_coding_4_cpp
# build_coding_4_cpp.parseHFileWithTarget("..\..\Common\ProtocolsPNL\pnl_protocol.h", "..\..\Common\ProtocolsPNL\pnl_protocol_encode.h","..\..\Common\ProtocolsPNL\pnl_protocol_encode.cpp","..\..\Common\ProtocolsPNL\pnl_protocol_decode.h","..\..\Common\ProtocolsPNL\pnl_protocol_decode.cpp")
# print "2"
# import build_coding_4_java
# build_coding_4_java.parseHFileWithTarget("..\..\Common\ProtocolsPNL\pnl_protocol.h", "..\..\Common\ProtocolsPNL\CPnlProtocol.java")

# import build_coding_4_py
# build_coding_4_py.parseAndBuild("..\..\Common\ProtocolsPNL\pnl_protocol.h", moduleName="PNL", protocolEnum="EProtocolId", relativePath="..\\")

import build_coding_4_cpp
build_coding_4_cpp.g_modulePrefix = "_PASSPORT"
build_coding_4_cpp.parseHFileWithTarget("../Common/ProtocolsS2S/protocolPassport.h", "../Common/ProtocolsS2S/protocolPassportEncode4cpp.h","../Common/ProtocolsS2S/protocolPassportEncode4cpp.cpp","../Common/ProtocolsS2S/protocolPassportDecode4cpp.h","../Common/ProtocolsS2S/protocolPassportDecode4cpp.cpp")

