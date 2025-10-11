#include "Chappie.h"
#include "LineSensors.h"

void lineFollower();
int constraint(int val);

Chappie chappie = Chappie();
LineSensors lineSensors = LineSensors();

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Hello, Chappie!");
    delay(1000);
}

void lineFollower() {
    float Kp = 0.021, Ki = 0.0, Kd = 0.0;
    float error = 0, integralError = 0, derivativeError, lastError = 0;
    int baseSpeed = 150;

    while (true) {
        int position = lineSensors.readPosition();
        error = -position;
        integralError += error;
        derivativeError = error - lastError;

        float pid = Kp * error + Ki * integralError + Kd * derivativeError;

        int speedRight = constraint(baseSpeed + pid);
        int speedLeft = constraint(baseSpeed - pid);

        chappie.moveForward(speedRight, speedLeft);
    }
}

int constraint(int val) {
    if (val > 255) return 255;
    if (val < 0) return 0;
    return val;
}