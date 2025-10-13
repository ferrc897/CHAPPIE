#include "functions.h"
#include "globals.h"

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Hello, Chappie!");
    delay(1000);
}