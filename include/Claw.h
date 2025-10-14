#ifndef CLAW_H
#define CLAW_H

#include <Arduino.h>
#include "Servo.h"

class Claw {
   public:
    Claw(int pin);
    void open();
    void close();
    bool holding = false;
    Servo clawServo;
   private:
    int pin;
};  

#endif // CLAW_H