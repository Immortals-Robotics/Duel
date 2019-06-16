cmake_minimum_required(VERSION 3.6)
project (gamepad)

SET(mylibSRCS gamepad.c gamepad.h)

ADD_LIBRARY(gamepad ${mylibSRCS})

target_link_libraries(gamepad c m udev)



