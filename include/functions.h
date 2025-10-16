#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"
#include <Arduino.h>
#include <Adafruit_TCS34725.h>

namespace p1 {
    void ball();
    void dropBall();
    void kickBall();
    void goStraight();
    void goStraightBack();
    int pid(float position);
}

namespace p2 {
    void lineFollower();
    int pid(float position);
}

#endif

