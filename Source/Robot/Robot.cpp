//
// Created by dot_blue on 4/2/19.
//

#include "Robot.h"
#include "../Math/helpers.h"

void Robot::halt(bool _halt) {
    this-> _halted = _halt;
}

void Robot::makeDataReady(bool raw_motor) {

    data[0] = _visionID;
    if(_halted){
        data[1] = 0x0A;//length=10
        data[2] = 0x06;//Command to HALT
        data[3] = 0x00;
        data[4] = 0x00;
        data[5] = 0x00;
        data[6] = 0x00;
        data[7] = 0x00;
        data[8] = 0x00;
        data[9] = 0x00;
    } else {
        if(!raw_motor) {
            data[1] = 15;//length=15
            data[2] = 12;//Command to move with new protocol

            convert_float_to_2x_buff(data + 3, target_velocity.X);
            convert_float_to_2x_buff(data + 5, target_velocity.Y);
            convert_float_to_2x_buff(data + 7, target_orientation);
            convert_float_to_2x_buff(data + 9, 0.0);
            if (_direct > 0) {
                data[11] = _direct;
                data[12] = 0x00;
            } else if (_chip > 0) {
                data[11] = 0x00;
                data[12] = _chip;
            } else {
                data[11] = 0x00;
                data[12] = 0x00;
            }
        } else {
            data[1] = 10;//length=15
            data[2] = 0x0A;//Command to move by giving the direct motor values

            int tmp1 = target_velocity.Y*0.8387 - target_velocity.X*0.5446;
            int tmp2 = -target_velocity.Y*0.8387 - target_velocity.X*0.5446;
            int tmp3 = -target_velocity.Y*0.707 + target_velocity.X*0.707;
            int tmp4 = target_velocity.Y*0.707 + target_velocity.X*0.707;

            data[3] = abs(tmp1);
            data[4] = abs(tmp2);
            data[5] = abs(tmp3);
            data[6] = abs(tmp4);

            data[7] = 0x00;
            data[7] |= (tmp1<0)? 0x01 : 0x00;
            data[7] |= (tmp2<0)? 0x02 : 0x00;
            data[7] |= (tmp3<0)? 0x04 : 0x00;
            data[7] |= (tmp4<0)? 0x08 : 0x00;

        }
    }
    _newCommReady = true;
}

void Robot::makeReadyForNewComm() {
    this->_newCommReady = false;
}


void Robot::set_direct(int pow){
    //TODO add a calibrated converter here...
    //_direct = getCalibratedShootPow(vision_id, pow);
    _direct = pow;
}
void Robot::set_chip(int pow){
    //TODO add a calibrated converter here...
    //_chip = getCalibratedChipPow(vision_id, pow);
    _chip = pow;
}

void Robot::set_dribble(int pow){
    _dribble = 16*pow;
}

void Robot::orientateAng(double deg) {
    target_orientation = NormalizeAngle(deg);
}

void Robot::moveBySpeed(TVec2 vel) {
    target_velocity = vel;
}

bool Robot::isHalted() {
    return _halted;
}

void Robot::set_visionID(int _ID) {
    _visionID = _ID;
}





