//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_REVERSINGLIGHTLED_H
#define UNTITLED_REVERSINGLIGHTLED_H

#include "LED.h"

class ReversingLightLED : LED {
public:
    ReversingLightLED(byte arrLED[][3]) : LED(arrLED) {};
    virtual void turnOn() override;
    virtual void turnOff() override;
};

#endif //UNTITLED_REVERSINGLIGHTLED_H
