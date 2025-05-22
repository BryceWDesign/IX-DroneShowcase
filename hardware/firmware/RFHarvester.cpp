// RFHarvester.cpp
// IX-DroneShowcase: Implementation of RF Energy Harvester Class
// Author: BryceWDesign
// License: MIT

#include "RFHarvester.h"
#include <Arduino.h>

void RFHarvester::init() {
    pinMode(RF_INPUT_PIN, INPUT);
    lastReading = 0;
    mpptState = 0;
}

int RFHarvester::readEnergy() {
    int raw = analogRead(RF_INPUT_PIN);
    return applyMPPT(raw);
}

int RFHarvester::applyMPPT(int rawInput) {
    int delta = rawInput - lastReading;
    if (abs(delta) > threshold) {
        mpptState = (delta > 0) ? 1 : -1;
    }
    lastReading = rawInput;
    return rawInput + mpptState * 5;
}
