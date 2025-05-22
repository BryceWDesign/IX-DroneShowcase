// PiezoHarvester.cpp
// IX-DroneShowcase: Implementation of Piezoelectric Energy Harvester Class
// Author: BryceWDesign
// License: MIT

#include "PiezoHarvester.h"
#include <Arduino.h>

void PiezoHarvester::init() {
    pinMode(PIEZO_INPUT_PIN, INPUT);
    smoothedValue = 0;
}

int PiezoHarvester::readEnergy() {
    int raw = analogRead(PIEZO_INPUT_PIN);
    smoothedValue = (smoothedValue * 0.9) + (raw * 0.1);
    return estimateEnergy(smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
    float voltage = (smoothed / 1023.0) * 3.3;
    float energy = voltage * voltage / internalResistance;
    return (int)(energy * 1000); // mW equivalent
}
