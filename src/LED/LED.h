//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_LED_H
#define UNTITLED_LED_H

#ifdef ARDUINO

#if (ARDUINO >= 100)
#include <Arduino.h>
#endif

#endif

typedef bool boolean;
typedef uint8_t byte;

enum LED_STATUS {
    LED_ON,
    LED_OFF
};

enum DIRECTION {
    RIGHT,
    LEFT,
    BOTH
};

class LED {
protected:
    byte (*_arrLED)[3];
    LED_STATUS ledStatus = LED_OFF;
    // for blink action
    unsigned long previousMillis = 0;
public:
    LED(byte arrLED[][3]) {
        _arrLED = arrLED;
    }
    virtual void turnOn();
    virtual void turnOff();
};

#endif //UNTITLED_LED_H
