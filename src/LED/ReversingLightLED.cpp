//
// Created by 박우영 on 10/7/23.
//

#include "ReversingLightLED.h"

void ReversingLightLED::turnOn()  {
    Serial.println("ReversingLightLED:turnOn");
    _arrLED[2][1] = 0x32;
    _arrLED[3][1] = 0x32;
}

void ReversingLightLED::turnOff() {
    Serial.println("ReversingLightLED:turnOff");
    _arrLED[2][1] = 0x00;
    _arrLED[3][1] = 0x00;
}
