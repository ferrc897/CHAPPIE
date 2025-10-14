#include "functions.h"
#include "globals.h"

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (chappie.readFrontDistance() < 30) {
        chappie.stop();
    }
    else {
        chappie.moveForward(150, 150);
    }

    if (chappie.clawSensor() && chappie.readFrontDistance() > 30 && !chappie.clawSensor()) {
        chappie.holdBall();
        delay(1000);
        chappie.kickBall();
        delay(1000);
    }
    
}