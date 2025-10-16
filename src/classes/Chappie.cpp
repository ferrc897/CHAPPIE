#include "Chappie.h"
#include "Motor.h"

Chappie::Chappie() : motorRight(24, 25, 6), motorLeft(22, 23, 7),
  ultrasonicFront(50, 51), ultrasonicRight(52, 53), ultrasonicLeft(48, 49), claw(9), ff(2) {
  // Constructor implementation
  release();
  
};

void Chappie::moveForward(int speedRight, int speedLeft) {
  // Code to move the robot forward at the specified speed
  motorRight.forward(speedRight);
  motorLeft.forward(speedLeft);
}

void Chappie::moveBackward(int speedRight, int speedLeft) {
  // Code to move the robot backward at the specified speed
  motorRight.backward(speedRight);
  motorLeft.backward(speedLeft);
}

void Chappie::stop() {
  // Code to stop the robot
  motorRight.stop();
  motorLeft.stop();
  delay(500);
}

int Chappie::readFrontDistance() {
  return ultrasonicFront.readDistance();
}

int Chappie::readRightDistance() {
  return ultrasonicRight.readDistance();
}

int Chappie::readLeftDistance() {
  return ultrasonicLeft.readDistance();
}

bool Chappie::isClawHolding() {
  return claw.holding;
}

void Chappie::pick() {
  claw.close();
  delay(500);
}

void Chappie:: release() {
  claw.open();
  delay(500);
}

bool Chappie::clawSensor() {
  return ff.detectsBall();
}

int Chappie::getPosition() {
  return ultrasonicLeft.readDistance() - ultrasonicRight.readDistance();
}
