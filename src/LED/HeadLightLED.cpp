//
// Created by 박우영 on 10/7/23.
//

#include "HeadLightLED.h"

void HeadLightLED::turnOn() {
    _arrLED[0][2] = 0x28;
    _arrLED[1][2] = 0x28;
}

void HeadLightLED::turnOff() {
    _arrLED[0][2] = 0x00;
    _arrLED[1][2] = 0x00;
}
