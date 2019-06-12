#include <iostream>
#include <cstdio>

#include "libgamepad/gamepad.h"

int main() {
    std::cout << "Waiting to connect to the remotes..." << std::endl;

    int ch;



    GamepadInit();

    while ((ch = getchar()) != 'q') {

    }

    return 0;
}