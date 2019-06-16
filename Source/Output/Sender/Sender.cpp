//
// Created by dot_blue on 4/10/19.
//

#include "Sender.h"
#include "../../Robot/Robot.h"


Sender::Sender(GameSetting *_gameSetting) {
    buff_idx = 0;
    for(int i=0;i<MAX_SENDER_BUFF_LEN;i++){
        buffer[i]=0x00;
    }
    startup = 5;

    sender_UDP_Address = _gameSetting->sender_UDP_Address;
    senderPort = _gameSetting->senderPort;
}

bool Sender::getCommand(Robot* bot) {

    if(bot->_newCommReady) {
        for (int i = 0; i < bot->data[1]; i++) {
            buffer[i + buff_idx] = bot->data[i];
        }
        buff_idx += bot->data[1];
        bot->_newCommReady = false;
        return true;
    }

    return false;
}

bool Sender::sendAll() {
    if(startup > 0){
        startup--;
        return false;
    }
//    int i=0;
//    for(unsigned char data:buffer)
//        cout<<i++<<": "<<(int)data<<endl;

    try {
        commUDP.sendTo ( buffer , buff_idx , sender_UDP_Address , senderPort );
    } catch (...) {
        cout << "ERROR: failed to send robot packets." << endl;
        buff_idx = 0;
        return false;
    }

    buff_idx = 0;
    return true;
}


void Sender::append_demo_data() {
    buffer[0 + buff_idx] = 25;
    buffer[1 + buff_idx] = 0x0A;//2
//    buffer[2 + buff_idx] = 0x00;
//    buffer[3 + buff_idx] = 0x00;
//    buffer[4 + buff_idx] = 0x00;
//    buffer[5 + buff_idx] = 0x00;
//    buffer[6 + buff_idx] = 0x00;
//    buffer[7 + buff_idx] = 0x00;
//    buffer[8 + buff_idx] = 0x00;
//    buffer[9 + buff_idx] = 0x00;
    buff_idx += 2;
}

