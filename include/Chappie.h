#ifndef CHAPPIE_H
#define CHAPPIE_H

#include <Arduino.h>

class Chappie {
public:
    Chappie();
    // Add other public methods and attributes here

    void moveForward(int speedRight, int speedLeft);
    void moveBackward(int speedRight, int speedLeft);
    void turnRight(int speedRight, int speedLeft);
    void turnLeft(int speedRight, int speedLeft);
    void stopMotors();

    bool detectObstacleFront();
    bool detectObstacleLeft();
    bool detectObstacleRight();
};

#endif // CHAPPIE_H