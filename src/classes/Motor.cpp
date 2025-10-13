#include "Motor.h"

Motor::Motor(int in1, int in2, int en) 
  : pinIn1(in1), pinIn2(in2), pinEn(en) {

  pinMode(pinIn1, OUTPUT);
  pinMode(pinIn2, OUTPUT);
  pinMode(pinEn, OUTPUT);
}

void Motor::forward(int speed) {
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  analogWrite(pinEn, speed);
}

void Motor::backward(int speed) {
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  analogWrite(pinEn, speed);
}

void Motor::stop() { 
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, LOW);
  analogWrite(pinEn, 0);
}