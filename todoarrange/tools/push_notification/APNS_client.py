# -*- coding: utf8 -*-

import ssl
import os
import socket
import time
import pprint
c = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
ssl_c = ssl.wrap_socket(c,
                        certfile = "../../../codesign/dragonswardofficial/aps_development.pem",
                        keyfile = "../../../codesign/dragonswardofficial/development_private_key.pem",
                       cert_reqs=ssl.CERT_REQUIRED,
                       ca_certs = "../../../Bin/Server/gameserver/Debug/entrust_2048_ca.pem",
                       ciphers = "AdAAdA987654321")
print "build the ssl socket"
ssl_c.connect(("gateway.sandbox.push.apple.com", 2195))
print "connect the apple push success"
print ssl_c.getpeername()
print ssl_c.cipher()
print pprint.pformat(ssl_c.getpeercert())
ssl_c.shutdown()
ssl_c.close()


"""
import time
import socket
from OpenSSL import SSL
ctx = SSL.Context(SSL.SSLv3_METHOD)
ctx.set_passwd_cb(lambda *unused: "AdAAdA987654321")
#F:/projectxxx/Bin/Server/gameserver/Debug, "F:/projectxxx/Bin/Server/gameserver/Debug"
ctx.load_verify_locations("F:/projectxxx/Bin/Server/gameserver/Debug/entrust_2048_ca.pem")
ctx.use_privatekey_file("../../../codesign/dragonswardofficial/development_private_key.pem")
ctx.use_certificate_file("../../../codesign/dragonswardofficial/aps_development.pem")
ctx.check_privatekey()
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setblocking(True)

someSocket = SSL.Connection(ctx, s)
someSocket.connect(("gateway.sandbox.push.apple.com", 2195))
print "all ok", someSocket.getpeername(), someSocket.get_servername(), someSocket.get_client_ca_list()
someSocket.send("Hello, world")
r = someSocket.recv(1024)
someSocket.shutdown()
someSocket.close()
"""
