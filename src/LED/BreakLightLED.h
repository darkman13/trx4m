//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_BREAKLIGHTLED_H
#define UNTITLED_BREAKLIGHTLED_H

#include "LED.h"

class BreakLightLED : LED {
public:
    BreakLightLED(byte arrLED[][3]) : LED(arrLED)  {};
    virtual void turnOn() override;
    virtual void turnOff() override;
};

#endif //UNTITLED_BREAKLIGHTLED_H
