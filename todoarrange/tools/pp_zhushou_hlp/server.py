# -*- coding: utf8 -*-
import pp_zhushou_hlp
import time

print "server start"
inner_s = pp_zhushou_hlp.PPInnerServer('192.168.1.32', 7995) #最简单的模式
ppsdk_s = pp_zhushou_hlp.PPPayServer('192.168.1.32', 7994) #最简单的模式
#s = mass_server_listener.SelectServer('192.168.1.33', 9999) #select模式 
#s = mass_server_listener.EPollServer('192.168.1.33', 9999) #epoll模式 


try:
	while 1:
		inner_s.run()
		ppsdk_s.run()
		time.sleep(0.01)
except KeyboardInterrupt :
	pass
except :
	print "except any way"
inner_s.close()
ppsdk_s.run()
print "server all over"
