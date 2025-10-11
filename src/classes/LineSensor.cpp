#include "LineSensors.h"

LineSensor::LineSensor() {
    qtr.setTypeAnalog();
    qtr.setSensorPins(sensorPins, 8); // Assuming 8 sensors
}

void LineSensor::calibrate() {
    for (uint16_t i = 0; i < 400; i++) {
        qtr.calibrate();
    }
}

int LineSensor::readPosition() {
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