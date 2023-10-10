//
// Created by 박우영 on 10/7/23.
//

#include "BreakLightLED.h"

void BreakLightLED::turnOn() {
    Serial.println("BreakLightLED:turnOn");
    _arrLED[2][2] = 0xC8;
    _arrLED[3][2] = 0xC8;
}

void BreakLightLED::turnOff() {
    Serial.println("BreakLightLED:turnOff");
    _arrLED[2][2] = 0x00;
    _arrLED[3][2] = 0x00;
}

