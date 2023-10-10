#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "LED/LEDController.h"

#define LED_PIN_OUTPUT A1
#define SERVO_PIN_INPUT A2
#define MOTOR_PIN_INPUT A5
#define CH3_PIN_INPUT A4

#define LED_NUM 4

// signal status
#define STATUS_LOW 1
#define STATUS_MEDIUM 2
#define STATUS_HIGH 3

// input signal value
unsigned long motorSignal = 0;
unsigned long servoSignal = 0;
unsigned long ch3Signal = 0;

// input signal status
unsigned int motorStatus = 0;
unsigned int servoStatus = 0;
unsigned int ch3Status = 0;

// input signal mode;
enum SERVO_SIGNAL_MODE {
    SERVO_INITIAL_MODE,
    SERVO_RIGHT_MODE,
    SERVO_LEFT_MODE,
    SERVO_NEUTRAL_MODE
};

enum MOTOR_SIGNAL_MODE {
    MOTOR_INITIAL_MODE,
    MOTOR_FORWARD_MODE,
    MOTOR_BACKWARD_MODE,
    MOTOR_NEUTRAL_MODE
};

enum CH3_SIGNAL_MODE {
    CH3_INITIAL_MODE,
    CH3_ON_MODE,
    CH3_OFF_MODE
};

SERVO_SIGNAL_MODE servoMode = SERVO_INITIAL_MODE;
MOTOR_SIGNAL_MODE motorMode = MOTOR_INITIAL_MODE;
CH3_SIGNAL_MODE ch3Mode = CH3_INITIAL_MODE;

// mode value
bool welcomeMode = true;
bool turnSignalStatus = false;

// LED light value
byte arrLED[4][3]{
        { 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00 }
};

Adafruit_NeoPixel led = Adafruit_NeoPixel(LED_NUM, LED_PIN_OUTPUT, NEO_RGB + NEO_KHZ800);
LEDController ledController = LEDController(arrLED);

uint8_t getSignalStatus(unsigned long signal, unsigned long lowThreshold, unsigned long highThreshold) {
    if (signal < lowThreshold) {
        return STATUS_LOW;
    } else if (signal > highThreshold) {
        return STATUS_HIGH;
    } else {
        return STATUS_MEDIUM;
    }
}

void captureSignals() {
    servoSignal = pulseIn(SERVO_PIN_INPUT, HIGH, 100000L);
    motorSignal = pulseIn(MOTOR_PIN_INPUT, HIGH, 100000L);
    ch3Signal   = pulseIn(CH3_PIN_INPUT,   HIGH, 100000L);

    servoStatus = getSignalStatus(servoSignal, 1450, 1700);
    motorStatus = getSignalStatus(motorSignal, 1400, 1550);
    ch3Status = getSignalStatus(ch3Signal, 1300, 1600);

    switch (motorStatus) {
        case STATUS_LOW:
            ledController.turnOnReversingLightLED();
            break;
        case STATUS_HIGH:
            ledController.turnOffAllLEDExceptTurnLight();
            break;
        case STATUS_MEDIUM:
            ledController.turnOnBreakLightLED();
            break;
    }

    switch (servoStatus) {
        case STATUS_LOW:
            ledController.turnOnTurnLightLED(LEFT);
            break;
        case STATUS_HIGH:
            ledController.turnOnTurnLightLED(RIGHT);
            break;
        case STATUS_MEDIUM:
            ledController.turnOffTurnLightLED();
            break;
    }

    switch (ch3Status) {
        case STATUS_LOW:
            ledController.turnOnDayLightLED();
            break;
        case STATUS_HIGH:
            ledController.turnOnHeadLightLED();
            break;
    }
}

//void printLED() {
//    for (int i = 0; i < 4; i++) {    // 2차원 배열의 세로 크기만큼 반복
//        for (int j = 0; j < 3; j++) {    // 2차원 배열의 가로 크기만큼 반복
//            Serial.print((arrLED[i][j]), HEX); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
//            Serial.print(" "); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
//        }
//        Serial.print("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
//    }
//}

void setLED() {
    for (int i = 0; i < 4; i++) {
        led.setPixelColor(i, arrLED[i][0], arrLED[i][1], arrLED[i][2]);
    }
}

void setup() {
    // Setting PinMode
    pinMode(SERVO_PIN_INPUT, INPUT);
    pinMode(MOTOR_PIN_INPUT, INPUT);
    pinMode(CH3_PIN_INPUT, INPUT);
    pinMode(LED_PIN_OUTPUT, OUTPUT);

    led.begin();
    ledController.turnOnDayLightLED();
    Serial.begin(9600);
}

void loop() {
    captureSignals();
    setLED();
    led.show();
    delay(200);
    //printLED();
}