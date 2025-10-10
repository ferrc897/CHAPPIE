#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  public:
    int pinIn1;
    int pinIn2;
    int pinEn;

    Motor(int in1, int in2, int en);
    void forward(int speed);
    void backward(int speed);
    void stop();

};

#endif // MOTOR_H