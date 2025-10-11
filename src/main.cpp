#include "Chappie.h"
#include <QTRSensors.h>

Chappie chappie = Chappie();

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Hello, Chappie!");
    delay(1000);
}