//
// Created by 박우영 on 10/7/23.
//

#ifndef UNTITLED_LEDCONTROLLER_H
#define UNTITLED_LEDCONTROLLER_H

#include "DayLightLED.h"
#include "HeadLightLED.h"
#include "TurnLightLED.h"
#include "BreakLightLED.h"
#include "ReversingLightLED.h"

class LEDController {
private:
    DayLightLED dayLightLed;
    HeadLightLED headLightLed;
    TurnLightLED turnLightLed;
    BreakLightLED breakLightLed;
    ReversingLightLED reversingLightLed;

    void turnOffAllLED();
public:
    LEDController(byte arrLED[][3])
    : dayLightLed(arrLED), headLightLed(arrLED), turnLightLed(arrLED),
      breakLightLed(arrLED), reversingLightLed(arrLED) {};

    void turnOnDayLightLED();
    void turnOnHeadLightLED();
    void turnOnTurnLightLED(DIRECTION direction);
    void turnOffTurnLightLED();
    void turnOnBreakLightLED();
    void turnOnReversingLightLED();
    void turnOffAllLEDExceptTurnLight();
};

#endif //UNTITLED_LEDCONTROLLER_H
