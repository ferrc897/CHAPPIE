#ifndef LINESENSORS_H
#define LINESENSORS_H

#include <Arduino.h>
#include "QTRSensors.h"

class LineSensors {
public:
    LineSensors();
    QTRSensors qtr;
    uint16_t sensorValues[8];
    const uint8_t sensorPins[8] = {A0, A1, A2, A3, A4, A5, A6, A7}; // Example analog pins
    void calibrate();
    int readPosition();
};

#endif // LINESENSORS_H