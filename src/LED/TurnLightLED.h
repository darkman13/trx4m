//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_TURNLIGHTLED_H
#define UNTITLED_TURNLIGHTLED_H

#include "LED.h"

class TurnLightLED : LED {
private:
    unsigned long currentMillis;
public:
    TurnLightLED(byte arrLED[][3]) : LED(arrLED) {
        currentMillis = 0;
    };
    virtual void turnOn() override;
    virtual void turnOff() override;
    void blink(DIRECTION direction, unsigned long blinkInterval);
};

#endif //UNTITLED_TURNLIGHTLED_H
