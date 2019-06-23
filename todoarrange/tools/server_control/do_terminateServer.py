# -*- coding: utf8 -*-
import sys

from masterControlClient import *
import protocol_enums_passport
sys.path.append('../')
import server_cfg
l = list()
l.append(protocol_enums_passport.E_M_C_C_Stop_Server)
doMasterControl(server_cfg.ip, server_cfg.port + 10000, l)



