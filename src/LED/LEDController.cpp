//
// Created by 박우영 on 10/7/23.
//

#include "LEDController.h"

void LEDController::turnOnDayLightLED() {
    dayLightLed.turnOn();
    headLightLed.turnOff();
}

void LEDController::turnOnHeadLightLED() {
    dayLightLed.turnOn();
    headLightLed.turnOn();
}

void LEDController::turnOnTurnLightLED(DIRECTION direction) {
    turnLightLed.blink(direction, 500);
}

void LEDController::turnOffTurnLightLED() {
    turnLightLed.turnOff();
}

void LEDController::turnOnBreakLightLED() {
    turnOffAllLEDExceptTurnLight();
    breakLightLed.turnOn();
}

void LEDController::turnOnReversingLightLED() {
    breakLightLed.turnOff();
    reversingLightLed.turnOn();
}

void LEDController::turnOffAllLED() {
    breakLightLed.turnOff();
    reversingLightLed.turnOff();
    turnLightLed.turnOff();
}

void LEDController::turnOffAllLEDExceptTurnLight() {
    breakLightLed.turnOff();
    reversingLightLed.turnOff();
}