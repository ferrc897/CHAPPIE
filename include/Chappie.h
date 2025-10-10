#ifndef CHAPPIE_H
#define CHAPPIE_H

#include <Arduino.h>
#include "Motor.h"

class Chappie {
private:
    Motor motorRight;
    Motor motorLeft;

public:
    Chappie();
    // Add other public methods and attributes here

    void moveForward(int speedRight, int speedLeft);
    void moveBackward(int speedRight, int speedLeft);
    void stop();
};

#endif // CHAPPIE_H