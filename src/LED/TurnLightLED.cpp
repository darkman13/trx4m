//
// Created by 박우영 on 10/7/23.
//

#include "TurnLightLED.h"

void TurnLightLED::turnOn() {
    _arrLED[0][0] = 0xC8;
    _arrLED[1][0] = 0xC8;
    _arrLED[2][0] = 0xC8;
    _arrLED[3][0] = 0xC8;
}

void TurnLightLED::turnOff() {
    _arrLED[0][0] = 0x00;
    _arrLED[1][0] = 0x00;
    _arrLED[2][0] = 0x00;
    _arrLED[3][0] = 0x00;
}

void TurnLightLED::blink(DIRECTION direction, unsigned long blinkInterval = 800) {
    previousMillis = 0;
    currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        if (ledStatus == LED_OFF) {
            switch (direction) {
                case RIGHT:
                    _arrLED[0][0] = 0x00;
                    _arrLED[1][0] = 0xC8;
                    _arrLED[2][0] = 0xC8;
                    _arrLED[3][0] = 0x00;
                    break;
                case LEFT:
                    _arrLED[0][0] = 0xC8;
                    _arrLED[1][0] = 0x00;
                    _arrLED[2][0] = 0x00;
                    _arrLED[3][0] = 0xC8;
                    break;
                case BOTH:
                    _arrLED[0][0] = 0xC8;
                    _arrLED[1][0] = 0xC8;
                    _arrLED[2][0] = 0xC8;
                    _arrLED[3][0] = 0xC8;
                    break;
            }
            ledStatus = LED_ON;
        } else {
            turnOff();
            ledStatus = LED_OFF;
        }
    }
}