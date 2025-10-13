#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t triggerPin, uint8_t echoPin)
    : trig(triggerPin), echo(echoPin) {

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

int Ultrasonic::readDistance() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH);
    long distance = duration * 0.034 / 2; // Convert to cm

    return distance;
}