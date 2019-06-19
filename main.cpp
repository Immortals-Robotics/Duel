#include <iostream>
#include <unistd.h>
#include <deque>

#include "libgamepad/gamepad.h"
#include "Source/GameSetting.h"
#include "Source/WorldState.h"
#include "Source/Output/Sender/Sender.h"

#define BUFF_SIZE 10

using namespace std;


GameSetting* gameSetting;
WorldState* worldState;
Sender* sender;

deque <double> buff[4];

double avg_vec(deque<double> _vec){
    double sum = 0;
    for(double elem:_vec){
        sum += elem;
    }
    return sum/_vec.size();
}

static void update(GAMEPAD_DEVICE dev) {
    float lx, ly, lenL, rx, ry, lenR;


    if (!GamepadIsConnected(dev)) {
        cout << dev << ") n/a\n";
        return;
    }

    if (!gameSetting->remote[dev].enabled){
        cout << dev << ") DISABLED\n";
        return;
    }

    double maxSpeed = gameSetting->remote[dev].maxSpeed;
    double maxAngSpeed = gameSetting->remote[dev].maxAngSpeed;

    GamepadStickNormXY(dev, STICK_LEFT, &lx, &ly);
    lenL = GamepadStickLength(dev, STICK_LEFT);
    buff[dev].push_back(lenL);
    if(buff[dev].size() > BUFF_SIZE){
        buff[dev].pop_front();
    }
    lenL = avg_vec(buff[dev]);
    lx *= lenL;
    ly *= lenL;
    GamepadStickNormXY(dev, STICK_RIGHT, &rx, &ry);
    lenR = GamepadStickLength(dev, STICK_RIGHT);
    rx *= lenR;
    ry *= lenR;



    worldState->ownRobot[dev].halt(false);
    worldState->ownRobot[dev].moveBySpeed(Vec2(ly,-lx) * maxSpeed);
    worldState->ownRobot[dev].orientateAng(-rx * maxAngSpeed);
    worldState->ownRobot[dev].set_direct(GamepadTriggerLength(dev, TRIGGER_RIGHT) * 50);
    worldState->ownRobot[dev].set_chip(GamepadTriggerLength(dev, TRIGGER_LEFT) * 50);

    worldState->ownRobot[dev].makeDataReady(false);
    sender->getCommand(&(worldState->ownRobot[dev]));


    printf("%d) L:(%+.3f,%+.3f :: %+.3f,%+.3f) R:(%+.3f, %+.3f :: %+.3f,%+.3f) LT:%+.3f RT:%+.3f \n",
           dev,
           lx, ly,
           GamepadStickAngle(dev, STICK_LEFT),
           GamepadStickLength(dev, STICK_LEFT),
           rx, ry,
           GamepadStickAngle(dev, STICK_RIGHT),
           GamepadStickLength(dev, STICK_RIGHT),
           GamepadTriggerLength(dev, TRIGGER_LEFT),
           GamepadTriggerLength(dev, TRIGGER_RIGHT));
//    printw("U:%d D:%d L:%d R:%d ",
//           GamepadButtonDown(dev, BUTTON_DPAD_UP),
//           GamepadButtonDown(dev, BUTTON_DPAD_DOWN),
//           GamepadButtonDown(dev, BUTTON_DPAD_LEFT),
//           GamepadButtonDown(dev, BUTTON_DPAD_RIGHT));
//    printw("A:%d B:%d X:%d Y:%d Bk:%d St:%d ",
//           GamepadButtonDown(dev, BUTTON_A),
//           GamepadButtonDown(dev, BUTTON_B),
//           GamepadButtonDown(dev, BUTTON_X),
//           GamepadButtonDown(dev, BUTTON_Y),
//           GamepadButtonDown(dev, BUTTON_BACK),
//           GamepadButtonDown(dev, BUTTON_START));
//    printw("LB:%d RB:%d LS:%d RS:%d\n",
//           GamepadButtonDown(dev, BUTTON_LEFT_SHOULDER),
//           GamepadButtonDown(dev, BUTTON_RIGHT_SHOULDER),
//           GamepadButtonDown(dev, BUTTON_LEFT_THUMB),
//           GamepadButtonDown(dev, BUTTON_RIGHT_THUMB));
}

int main() {

    gameSetting = new GameSetting();

    gameSetting->commandSleep = 20*1000;

    gameSetting->remote[0].enabled = true;
    gameSetting->remote[0].robotID = 5;
    gameSetting->remote[0].maxSpeed = 30;
    gameSetting->remote[0].maxAngSpeed = 20;
    gameSetting->remote[0].enableDirect = true;
    gameSetting->remote[0].enableChip = true;

    gameSetting->remote[1].enabled = true;
    gameSetting->remote[1].robotID = 4;
    gameSetting->remote[1].maxSpeed = 30;
    gameSetting->remote[1].maxAngSpeed = 20;
    gameSetting->remote[1].enableDirect = true;
    gameSetting->remote[1].enableChip = true;

    gameSetting->remote[2].enabled = false;
    gameSetting->remote[2].robotID = 4;
    gameSetting->remote[2].maxSpeed = 30;
    gameSetting->remote[2].maxAngSpeed = 20;
    gameSetting->remote[2].enableDirect = true;
    gameSetting->remote[2].enableChip = true;

    gameSetting->remote[3].enabled = false;

    gameSetting->sender_UDP_Address = "224.5.92.5";
    gameSetting->senderPort = 60005;

    //Not implemented
//    gameSetting->enable_GrSim = false;
//    gameSetting->GrSim_UDP_Address = "127.0.0.1";
//    gameSetting->GrSimPort = 20011;


    worldState = new WorldState();
    sender = new Sender(gameSetting);

    //Initializing
    for(int i=0;i<3;i++) {
        if(gameSetting->remote->enabled) {
            worldState->ownRobot[i].set_visionID(
                    gameSetting->remote[i].robotID
            );
        }
    }


    GamepadInit();

    while(1){
        GamepadUpdate();

        update(GAMEPAD_0);
        update(GAMEPAD_1);
        update(GAMEPAD_2);
        update(GAMEPAD_3);

        sender->append_demo_data();

        sender->sendAll();

        usleep(gameSetting->commandSleep);

    }

    delete gameSetting;
    delete worldState;
    delete sender;

    return 0;
}