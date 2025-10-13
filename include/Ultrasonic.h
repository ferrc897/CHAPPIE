#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
public:
    Ultrasonic(uint8_t triggerPin, uint8_t echoPin);
    uint8_t trig;
    uint8_t echo;

    int readDistance();
};

#endif // ULTRASONIC_H