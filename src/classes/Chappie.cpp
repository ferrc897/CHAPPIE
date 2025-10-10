#include "Chappie.h"

Chappie::Chappie() {
  // Constructor
}

void Chappie::moveForward(int speedRight, int speedLeft) {
  // Code to move the robot forward at the specified speed
  digitalWrite(motorRightPosPin, HIGH);
  digitalWrite(motorRightNegPin, LOW);

  digitalWrite(motorLeftPosPin, HIGH);
  digitalWrite(motorLeftNegPin, LOW);

  analogWrite(motorRightPin, speedRight);
  analogWrite(motorLeftPin, speedLeft);
}

void Chappie::moveBackward(int speedRight, int speedLeft) {
  // Code to move the robot backward at the specified speed
  digitalWrite(motorRightDirPin, LOW);
  digitalWrite(motorLeftDirPin, HIGH);

  analogWrite(motorRightPin, speedRight);
  analogWrite(motorLeftPin, speedLeft);
}