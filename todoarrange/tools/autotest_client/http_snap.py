# -*- coding: utf8 -*-

http_get_rsp = """HTTP/1.1 403 Forbidden
Date: Tue, 24 Sep 2013 22:10:33 GMT
Server: Apache/2.2.15 (CentOS)
connection:keep-alive
Accept-Ranges: bytes
Content-Length: 5039
Connection: close
Content-Type: text/html; charset=UTF-8

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
        <head>
                <title>Apache HTTP Server Test Page powered by CentOS</title>
                <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
                <style type="text/css">
                        body {
                                background-color: #fff;
                                color: #000;
                                font-size: 0.9em;
                                font-family: sans-serif,helvetica;
                                margin: 0;
                                padding: 0;
                        }
                        :link {
                                color: #0000FF;
                        }
                        :visited {
                                color: #0000FF;
                        }
                        a:hover {
                                color: #3399FF;
                        }
                        h1 {
                                text-align: center;
                                margin: 0;
                                padding: 0.6em 2em 0.4em;
                                background-color: #3399FF;
                                color: #ffffff;
                                font-weight: normal;
                                font-size: 1.75em;
                                border-bottom: 2px solid #000;
                        }
                        h1 strong {
                                font-weight: bold;
                        }
                        h2 {
                                font-size: 1.1em;
                                font-weight: bold;
                        }
                        .content {
                                padding: 1em 5em;
                        }
                        .content-columns {
                                /* Setting relative positioning allows for 
                                absolute positioning for sub-classes */
                                position: relative;
                                padding-top: 1em;
                        }
                        .content-column-left {
                                /* Value for IE/Win; will be overwritten for other browsers */
                                width: 47%;
                                padding-right: 3%;
                                float: left;
                                padding-bottom: 2em;
                        }
                        .content-column-right {
                                /* Values for IE/Win; will be overwritten for other browsers */
                                width: 47%;
                                padding-left: 3%;
                                float: left;
                                padding-bottom: 2em;
                        }
                        .content-columns>.content-column-left, .content-columns>.content-column-right {
                                /* Non-IE/Win */
                        }
                        img {
                                border: 2px solid #fff;
                                padding: 2px;
                                margin: 2px;
                        }
                        a:hover img {
                                border: 2px solid #3399FF;
                        }
                </style>
        </head>

        <body>
        <h1>Apache 2 Test Page<br><font size="-1"><strong>powered by</font> CentOS</strong></h1>

                <div class="content">
                        <div class="content-middle">
                                <p>This page is used to test the proper operation of the Apache HTTP server after it has been installed. If you can read this page it means that the Apache HTTP server installed at this site is working properly.</p>
                        </div>
<hr />
                        <div class="content-columns">
                                <div class="content-column-left">
                                        <h2>If you are a member of the general public:</h2>

                                        <p>The fact that you are seeing this page indicates that the website you just visited is either experiencing problems or is undergoing routine maintenance.</p>

                                        <p>If you would like to let the administrators of this website know that you've seen this page instead of the page you expected, you should send them e-mail. In general, mail sent to the name "webmaster" and directed to the website's domain should reach the appropriate person.</p>

                                        <p>For example, if you experienced problems while visiting www.example.com, you should send e-mail to "webmaster@example.com".</p>
                                </div>

                                <div class="content-column-right">
                                        <h2>If you are the website administrator:</h2>

                                        <p>You may now add content to the directory <tt>/var/www/html/</tt>. Note that until you do so, people visiting your website will see this page and not your content. To prevent this page from ever being used, follow the instructions in the file <tt>/etc/httpd/conf.d/welcome.conf</tt>.</p>

                                                <p>You are free to use the images below on Apache and CentOS Linux powered HTTP servers.  Thanks for using Apache and CentOS!</p>

                                                <p><a href="http://httpd.apache.org/"><img src="/icons/apache_pb.gif" alt="[ Powered by Apache ]"/></a> <a href="http://www.centos.org/"><img src="/icons/poweredby.png" alt="[ Powered by CentOS Linux ]" width="88" height="31" /></a></p>
                                </div>
                        </div>
                </div>
                <div class="content">
                        <div class="content-middle"><h2>About CentOS:</h2><b>The Community ENTerprise Operating System</b> (CentOS) is an Enterprise-class Linux Distribution derived from sources freely provided to the public by a prominent North American Enterprise Linux vendor.  CentOS conforms fully with the upstream vendors redistribution policy and aims to be 100% binary compatible. (CentOS mainly changes packages to remove upstream vendor branding and artwork.)  The CentOS Project is the organization that builds CentOS.</p>
<p>For information on CentOS please visit the <a href="http://www.centos.org/">CentOS website</a>.</p>
<p><h2>Note:</h2><p>CentOS is an Operating System and it is used to power this website; however, the webserver is owned by the domain owner and not the CentOS Project.  <b>If you have issues with the content of this site, contact the owner of the domain, not the CentOS project.</b>
<p>Unless this server is on the CentOS.org domain, the CentOS Project doesn't have anything to do with the content on this webserver or any e-mails that directed you to this site.</p>
<p>For example, if this website is www.example.com, you would find the owner of the example.com domain at the following WHOIS server:</p>
<p><a href="http://www.internic.net/whois.html">http://www.internic.net/whois.html</a></p>

                        </div>
                </div>
</body>
</html>
"""

http_get_rsp_template = """HTTP/1.1 200 OK
Date: Tue, 24 Sep 2013 22:10:33 GMT
Server: Apache/2.2.15 (CentOS)
connection:keep-alive
Accept-Ranges: bytes
Content-Length: %(html_file_length)d
Connection: close
Content-Type: text/html; charset=UTF-8

%(html_file)s
"""

html_test = """<html>
        <body background="DSC01076.gif">
                <h1>龙剑服务器列表</h1>
                <div class="server_status" id="2">
                        <div class="herf">
                                <a href="/getlog/2/normal">观看当前日志</a>
                        </div>
                        <div class="herf">
                                <a href="/control/2/terminate">关闭服务器</a>
                        </div>
                        <div class="herf">
                                <a href="/control/2/start">开启服务器</a>
                        </div>
                </div>
        </body>
</html>
"""

http_get_gif="""GET /DSC01076.gif HTTP/1.1
Host: 192.168.1.134:9999
Connection: keep-alive
Cache-Control: max-age=0
Accept: image/webp,*/*;q=0.8
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.76 Safari/537.36
Referer: http://192.168.1.134:9999/
Accept-Encoding: gzip,deflate,sdch
Accept-Language: en-US,en;q=0.8


"""

import re
class CEasyHttpReq:
    action=None
    path=None

    def __repr__(self):
        #print " CEasyHttpReq  here the repr"
        return "action is [%r], path is [%r]"%(self.action, self.path)

    def __init__(self, req):
        print " CEasyHttpReq  here the init"
        print "#####################"
        print req
        print "#####################"
        pat = re.compile('^([\w]+) ([/\w]+) ')
        result = pat.findall(req)
        print result
        if len(result) > 0:
            self.action = result[0][0]
            self.path = result[0][1]

