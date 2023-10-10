//
// Created by 박우영 on 10/7/23.
//

#include "DayLightLED.h"

void DayLightLED::turnOn() {
    _arrLED[0][1] = 0x28;
    _arrLED[1][1] = 0x28;
}

void DayLightLED::turnOff() {
    _arrLED[0][1] = 0x00;
    _arrLED[1][1] = 0x00;
}

