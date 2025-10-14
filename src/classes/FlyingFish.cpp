#include "FlyingFish.h"

FlyingFish::FlyingFish(int pin) : pin(pin) {
    pinMode(pin, INPUT);
}

bool FlyingFish::detectsBall() {
    return digitalRead(pin) == HIGH;
}