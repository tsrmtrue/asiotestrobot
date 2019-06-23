# -*- coding: gbk -*-

import sys
sys.path.append('autotest_client')
sys.path.append('autotest_lib')

import test_namedlist
import test_namedlist_coding

spf = test_namedlist.SPackedFiles()

spf.count = 2
spf.files[0].name = "大田市.h"
spf.files[0].startIndex = 0
spf.files[0].endIndex = 124

spf.files[1].name = "无奈一.h"
spf.files[1].startIndex = 125
spf.files[1].endIndex = 322

buf = test_namedlist_coding.encode_SPackedFiles(spf)

spf2,pos = test_namedlist_coding.decode_SPackedFiles(buf)

print spf2.files[0].name

print spf2.files[1].name

print spf2.files[1].endIndex
