//
// Created by dot_blue on 6/16/19.
//

#ifndef IMMORTALSDUEL_GAMESETTING_H
#define IMMORTALSDUEL_GAMESETTING_H

#include <iostream>

struct RemoteSetting{

    bool enabled = false;
    short robotID = -1;
    double maxSpeed = 100.0;
    double maxAngSpeed = 10.0;
    bool enableChip = false;
    bool enableDirect = false;
};

struct GameSetting{

    // Delay between commands (usec)
    unsigned commandSleep = 5000;

    //Looks like every USB station can handle up to 4 controllers
    RemoteSetting remote[4];


    std::string sender_UDP_Address;
    unsigned short senderPort;


    bool enable_GrSim = false;
    std::string GrSim_UDP_Address;
    unsigned short GrSimPort;

};


#endif //IMMORTALSDUEL_GAMESETTING_H
