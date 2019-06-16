//
// Created by dot_blue on 4/2/19.
//

#ifndef IMMORTALITYSTONE_ROBOT_H
#define IMMORTALITYSTONE_ROBOT_H


#include "Protocol/data_lite.h"
#include "Protocol/writer.h"
#include "../Math/Vector.h"
#include <iostream>

struct Robot {
public:

    //Initialize
    void set_visionID(int _ID);

    //Robot Navigation
    void moveBySpeed(TVec2 vel);
    void orientateAng(double deg);
    void set_direct(int pow);
    void set_chip(int pow);
    void set_dribble(int pow);

    void halt(bool _halt = true);
    bool isHalted();


    //Resetting the params for a new process
    void makeReadyForNewComm();

    //Generate data command
    void makeDataReady(bool raw_motor = false);

public://private:

    unsigned char data[32];

    int _visionID;
    TVec2 target_velocity;
    float target_orientation;
    int _direct, _chip, _dribble;
    bool _halted;
    bool _newCommReady;

};


#endif //IMMORTALITYSTONE_ROBOT_H
