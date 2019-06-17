#ifndef ROBOT_IO_COMPONENT_H
#define ROBOT_IO_COMPONENT_H

#include "robot_client.h"

using asio::ip::tcp;
using WriteMessageQueue = std::deque<SWriteMessage*>;
using ReadMessageQueue = std::deque<SReadMessageDynamic>;

class CIO
    : public RobotModule<CIO>
{
public:
    explicit CIO(CRobotClient &guild, asio::io_service &io_service);
    ~CIO();

    void TryWrite(SWriteMessage* msg);
    void DoWrite();
    void Close();
    void OnNetworkClose();
    
    void TryConnect(std::string ip, std::string port, int targetState);
    void CloseConnection();
    //主动断开链接检查
    bool IsCloseNetworkFinished();

    // 读取特定协议的信息
    bool WaitReadMsgs(uint32_t protocal_id);

    void ClearLastNetMessage();

    //被动链接断开检查
    bool IsSocketBroken()
    {
        return !socket_.is_open();
    }

    ReadMessageQueue& GetMsgQ() { return read_msgs; }
    uint32_t GetReadMsgSize() { return read_msgs.size(); }
    bool ReadMsgEmpty() { return read_msgs.empty(); }
    SReadMessageDynamic& GetReadMsgFront() { return read_msgs.front(); }
    void ReadMsgPopFront() { read_msgs.pop_front(); }
private:

    void TryConnect(tcp::resolver::iterator endpoint_iterator, int targetState);
    //void TryReadHead();
    //void TryReadBody();
    void TryRead();

    CRobotClient &robot_client_;

    //asio封装
    asio::io_service &io_service_;
    tcp::socket socket_;

    WriteMessageQueue write_msgs_;
    SReadMessage read_msg_;
    ReadMessageQueue read_msgs;
    SReadMessageBig read_msg_big_;//读大包,自己做解析

    uint32_t current_write_msg_id_{ 0 };//当前发送报文的id
    uint32_t current_write_msg_index_{ 0 };//当前报文的index
};



#endif // ROBOT_IO_COMPONENT_H
