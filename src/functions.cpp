#include "functions.h"

namespace p1 {
    float Kp = 0.5, Ki = 0.0, Kd = 0.0;
    float error = 0, integralError = 0, derivativeError, lastError = 0;
    int baseSpeed = 150;

    float red, green, blue;


    void ball() {

        Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
        tcs.begin(0x29);

        if (!tcs.begin()) {
            while (1); // Halt if sensor not found
        }

        while (true) {
            goStraight();

            if (!chappie.isClawHolding() && chappie.clawSensor()) {
                chappie.stop();
                chappie.pick();
                delay(1000);
            }

            if (chappie.isClawHolding()) {
                tcs.setInterrupt(false);  // turn on LED

                delay(60);  // takes 50ms to read

                tcs.getRGB(&red, &green, &blue);

                tcs.setInterrupt(true);

                //FFDC55
                if (red > 235 and blue > 200 and blue < 240 and green > 35 and green < 75) {
                    dropBall();
                }
                //5FAFE1
                else if (red > 75 and red < 115 and blue > 155 and blue < 195 and green > 205 and green < 245) {
                    kickBall();
                }

                while (chappie.readFrontDistance() < 10) {
                    chappie.stop();
                }
            }
        }
    }

    void goStraight() {
        float position = chappie.getPosition();
            int correction = pid(position);

            int speedRight = constrain(baseSpeed + correction, 0, 255);
            int speedLeft = constrain(baseSpeed - correction, 0, 255);

            chappie.moveForward(speedRight, speedLeft);
    }

    void goStraightBack() {
        float position = chappie.getPosition();
            int correction = pid(position);

            int speedRight = constrain(baseSpeed + correction, 0, 255);
            int speedLeft = constrain(baseSpeed - correction, 0, 255);

            chappie.moveBackward(speedRight, speedLeft);
    }

    void dropBall() {
        while (chappie.readFrontDistance() > 5) {
            goStraight();
        }
        chappie.stop();

        chappie.release();
    }

    void kickBall() {
        while (chappie.readFrontDistance() > 15) {
            goStraight();
        }
        chappie.stop();
        delay(500);
        chappie.release();
        while (chappie.readFrontDistance() < 20) {
            goStraightBack();
        }
        chappie.stop();
        delay(500);
        chappie.pick();
        delay(500);
        while (chappie.readFrontDistance() > 5) {
            goStraight();

        }
    }

    int pid(float position) {
        error = -position;
        integralError += error;
        derivativeError = error - lastError;

        int correction = Kp * error + Ki * integralError + Kd * derivativeError;

        lastError = error;
        return correction;
    }
}

namespace p2 {
    float Kp = 0.5, Ki = 0.0, Kd = 0.0;
    float error = 0, integralError = 0, derivativeError, lastError = 0;
    int baseSpeed = 150;

    void lineFollower() {

        while (true) {
            float position = lineSensors.readPosition();
            int correction = pid(position);

            int speedRight = constrain(baseSpeed + correction, 0, 255);
            int speedLeft = constrain(baseSpeed - correction, 0, 255);

            chappie.moveForward(speedRight, speedLeft);
        }
    }

    int pid(float position) {
        error = -position;
        integralError += error;
        derivativeError = error - lastError;

        int correction = Kp * error + Ki * integralError + Kd * derivativeError;

        lastError = error;
        return correction;
    }
}