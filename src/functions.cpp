#include "functions.h"

namespace p1 {
    void ball() {
        
    }
}

namespace p2 {
    void lineFollower() {
        // PID constants
        float Kp = 0.021, Ki = 0.0, Kd = 0.0;
        float error = 0, integralError = 0, derivativeError, lastError = 0;
        int baseSpeed = 150;

        while (true) {
            int position = lineSensors.readPosition();
            error = -position;
            integralError += error;
            derivativeError = error - lastError;

            float pid = Kp * error + Ki * integralError + Kd * derivativeError;

            int speedRight = constrain(baseSpeed + pid, 0, 255);
            int speedLeft = constrain(baseSpeed - pid, 0, 255);

            chappie.moveForward(speedRight, speedLeft);
        }
    }
}