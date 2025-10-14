#include "Claw.h"

#include <Arduino.h>
#include <Servo.h>



Claw::Claw(int pin) 
    : pin(pin), clawServo() {
    pinMode(pin, OUTPUT);

    clawServo.attach(pin);
}

void Claw::open() {
    clawServo.write(0); // Open position
    holding = false;
}

void Claw::close() {
    clawServo.write(90); // Closed position
    holding = true;
}