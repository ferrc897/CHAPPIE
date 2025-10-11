#include "LineSensors.h"

LineSensors::LineSensors() {
    qtr.setTypeAnalog();
    qtr.setSensorPins(sensorPins, 8); // Assuming 8 sensors
}

void LineSensors::calibrate() {
    for (uint16_t i = 0; i < 400; i++) {
        qtr.calibrate();
    }
}

int LineSensors::readPosition() {
    qtr.readLineBlack(sensorValues);

    long numerator = 0;
    long denominator = 0;

    for (uint8_t i = 0; i < 8; i++) {
        int value = sensorValues[i];
        numerator += (-3500+(i*1000))*value; 
        denominator += value;
    }

    int pos = 0;
    if (denominator != 0) {
        pos = numerator / denominator;
    }
    return pos;
}