# -*- coding: utf8 -*-

#ssdict = {
#          servername:[servername, ip, port, serverstatus, globalntf],
#          :[],
#          }

def build_server_status(ssdict):
    all_template="""
<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<ServerList_Tab>
<TResHeadAll version="7">
    <resHead type="TResHead">
        <Magic>1397052237 </Magic>
        <Version>7 </Version>
        <Unit>2312 </Unit>
        <Count>%(totalServerCount)d </Count>
        <MetalibHash>a839ebc5dd3557b743bb04f465b6d40e</MetalibHash>
        <ResVersion>0 </ResVersion>
        <CreateTime>2013-05-20 07:04:26</CreateTime>
        <ResEncording>UTF-8</ResEncording>
        <ContentHash>886f19b48ab33cd74c5c53b77da19dca</ContentHash>
    </resHead>
    <resHeadExt type="TResHeadExt">
        <DataOffset>140 </DataOffset>
        <Buff>0 </Buff>
    </resHeadExt>
</TResHeadAll>
%(ss)s
</ServerList_Tab>
"""
    ss_template = """
<ServerList version="1">
    <serverName>%(servername)s</serverName>
    <serverAdd>%(ip)s</serverAdd>
    <serverPort>%(port)s</serverPort>
    <ServerStatu>%(serverstatus)s</ServerStatu>
    <GlobalNtf>%(globalntf)s</GlobalNtf>
</ServerList>
"""
    totalServerCount = len(ssdict.keys())
    ss = ""
    for sn in ssdict.keys():
        servername   = ssdict[sn][0]
        ip           = ssdict[sn][1]
        port         = ssdict[sn][2]
        serverstatus = ssdict[sn][3]
        globalntf    = ssdict[sn][4]
        ss += ss_template%(locals())
    return all_template%(locals())

def build_xml_file(filename, ssdict):
    w = open(filename, 'w')
    #w = open('testSqlOperationHlp.h', 'w')
    w.write(build_server_status(ssdict))
    w.close()
    