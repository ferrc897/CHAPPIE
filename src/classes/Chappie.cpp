#include "Chappie.h"
#include "Motor.h"

Chappie::Chappie() : motorRight(4, 5, 6), motorLeft(7, 8, 9),
  ultrasonicFront(10, 11), ultrasonicRight(12, 13), ultrasonicLeft(14, 15), claw(9) {
  // Constructor implementation
  
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

void Chappie::openClaw() {
    claw.open();
}

void Chappie::closeClaw() {
    claw.close();
}

bool Chappie::isClawHolding() {
    return claw.holding;
}

