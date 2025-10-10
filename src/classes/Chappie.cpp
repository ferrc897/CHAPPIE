#include "Chappie.h"
#include "Motor.h"

Chappie::Chappie() : motorRight(3, 4, 5), motorLeft(6, 7, 8) {
  
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