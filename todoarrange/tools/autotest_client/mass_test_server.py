# -*- coding: utf8 -*-
import mass_server_listener
import time

print "server start"
s = mass_server_listener.EasyServer('192.168.1.32', 9999) #最简单的模式
#s = mass_server_listener.SelectServer('192.168.1.33', 9999) #select模式 
#s = mass_server_listener.EPollServer('192.168.1.33', 9999) #epoll模式 


try:
	while s.run() == True:
	    time.sleep(0.001)
	    pass
except KeyboardInterrupt :
	pass
except :
	print "except any way"
s.close()
print "server all over"
