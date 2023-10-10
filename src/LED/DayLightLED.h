//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_DAYLIGHTLED_H
#define UNTITLED_DAYLIGHTLED_H

#include "LED.h"

class DayLightLED : LED {
public:
    DayLightLED(byte arrLED[][3]) : LED(arrLED) {};
    virtual void turnOn() override;
    virtual void turnOff() override;
};

#endif //UNTITLED_DAYLIGHTLED_H
