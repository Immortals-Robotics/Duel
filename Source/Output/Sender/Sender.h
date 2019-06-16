//
// Created by dot_blue on 4/10/19.
//

#ifndef IMMORTALITYSTONE_SENDER_H
#define IMMORTALITYSTONE_SENDER_H

#define MAX_SENDER_BUFF_LEN    500


#include "../../GameSetting.h"
#include "../../WorldState.h"
#include "../../Network/PracticalSocket.h"

class Sender {
public:
    Sender() = delete;
    Sender(GameSetting* _gameSetting);

    bool getCommand(Robot* bot);
    bool sendAll();
    void append_demo_data();

private:
    // GameSettings & UDP_connection
    std::string sender_UDP_Address;
    unsigned short senderPort;
    UDPSocket commUDP;

    unsigned char buffer[MAX_SENDER_BUFF_LEN];
    int buff_idx;
    int startup;

};


#endif //IMMORTALITYSTONE_SENDER_H
