# -*- coding: GBK -*-
class EasyClient(object):
    def __init__(self, s):
        self._s = s
        sefl._recvbuf = ""
    def send(self, buf):
        self._s.send(buf)
    def recv(self):
        self._recvbuf += self._s.recv(0xffff)
    def set_recvbuf(self, buf):
        self._recvbuf = buf
    def get_recvbuf(self):
        return self._recvbuf
    recvbuf = property(get_recvbuf, set_recvbuf)
    
g_handle_map = {
                #ID_GATE_2_CLIENT_START_NTF: handle_ID_GATE_2_CLIENT_START_NTF,
                #LGID_ACT_ACK: handle_LGID_ACT_ACK,
                #SDF_CLI_SELECTED_ROLE_ACK: handle_SDF_CLI_SELECTED_ROLE_ACK,
                #ID_GAME_2_CLIENT_CHAT_TEST_ACK:handle_ID_GAME_2_CLIENT_CHAT_TEST_ACK,
                #ID_GAME_2_CLIENT_MONSTER_POSITION_APPEAR_NTF:handle_ID_GAME_2_CLIENT_MONSTER_POSITION_APPEAR_NTF,
                #ID_GAME_2_CLIENT_MONSTER_POSITION_MOVE_NTF:handle_ID_GAME_2_CLIENT_MONSTER_POSITION_MOVE_NTF,
                #ID_GAME_2_CLIENT_MONSTER_POSITION_DISAPPEAR_NTF:handle_ID_GAME_2_CLIENT_MONSTER_POSITION_DISAPPEAR_NTF,
                #ID_GAME_2_CLIENT_ROLE_ENTER_MAP_NTF:handle_ID_GAME_2_CLIENT_ROLE_ENTER_MAP_NTF,
                #ID_GAME_2_CLIENT_ROLE_LEAVE_MAP_NTF:handle_ID_GAME_2_CLIENT_ROLE_LEAVE_MAP_NTF,                
                }
def get_on_recv(handle_map, parse_message):
    def handle_default(recvedMsgid, st, client):
        print "unhandled msg ", recvedMsgid
    def handle(msgid, st, client):
        handle_map.get(msgid, handle_default)(st, msgid, client)
    def on_recv(client):
        while (1):
            #time.sleep(1)
            #print "on revvvv"
            st,pos,msgid = parse_message(client.recvbuf)
            #print pos, msgid
            if pos > 0:
                client.recvbuf = client.recvbuf[pos:]
                handle(msgid, st, client)
            else:
                return 
    