#ifndef FLYINGFISH_H
#define FLYINGFISH_H

#include <Arduino.h>

class FlyingFish {
private:
    int pin;
public:
    FlyingFish(int pin);
    bool detectsBall();
};

#endif // FLYINGFISH_H