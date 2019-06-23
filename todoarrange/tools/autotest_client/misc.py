from test_namedlist import *
from test_namedlist_coding import *
st = SRole()
st.roleBasic.diamond = 222;
st.roleBasic.exp = 333;
print type(st.roleBasic.rolename)
st.roleBasic.rolename = " sucker"
print st.roleBasic.rolename
print type(st.roleBasic.rolename)
st.roleBasic.macAddress = " loser"

st.taskCount = 1
st.tasks[0].aguid = 444
st.tasks[0].fid = 555
st.tasks[0].desc = "task1"
st.tasks[0].name = "task1"


st.packetTotal.totalCount = 666
st.packetTotal.count = 2
st.packetTotal.grids[0].g.c = 777
st.packetTotal.grids[0].x = 888
st.packetTotal.grids[1].g.g = 999
st.packetTotal.grids[1].x = 123
st.wingTotal.count=0
st.dailyWelfare.salary = 323

st.diamondConsume.exVigour = 98

st.equipmentStrength.count = 1
st.equipmentStrength.es[0].g = 324

sendRoleStr = encode_SRole(st)
print sendRoleStr
print len(sendRoleStr)

st2, recvlen = decode_SRole(sendRoleStr)
print st2
print recvlen
spvn = SProtocolVersionNtf()
spvn.v = 9
str = encode_SProtocolVersionNtf(spvn)
spvn2,l = decode_SProtocolVersionNtf(str)
print spvn.v