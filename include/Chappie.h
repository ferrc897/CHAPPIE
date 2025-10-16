#ifndef CHAPPIE_H
#define CHAPPIE_H

#include <Arduino.h>
#include "Motor.h"
#include "Ultrasonic.h"
#include "Claw.h"
#include "FlyingFish.h"

class Chappie {
private:
    Motor motorRight;
    Motor motorLeft;
    Ultrasonic ultrasonicFront;
    Ultrasonic ultrasonicRight;
    Ultrasonic ultrasonicLeft;
    Claw claw;
    FlyingFish ff;

public:
    Chappie();
    // Add other public methods and attributes here

    void moveForward(int speedRight, int speedLeft);
    void moveBackward(int speedRight, int speedLeft);
    void stop();
    int readFrontDistance();
    int readRightDistance();
    int readLeftDistance();
    bool isClawHolding();
    bool clawSensor();
    int getPosition();
    void pick();
    void release();
};

#endif // CHAPPIE_H