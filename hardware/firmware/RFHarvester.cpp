// RFHarvester.cpp
// IX-DroneShowcase: 2.4GHz RF Energy Harvester Implementation
// Author: BryceWDesign
// License: MIT

#include "RFHarvester.h"
#include <Arduino.h>

void RFHarvester::init() {
    pinMode(RF_INPUT_PIN, INPUT);
    mpptState = 0;
    lastReading = 0;
}

int RFHarvester::readEnergy() {
    int reading = analogRead(RF_INPUT_PIN);
    int harvested = applyMPPT(reading);
    lastReading = harvested;
    return harvested;
}

int RFHarvester::applyMPPT(int rawInput) {
    // Simulated MPPT logic for RF input optimization
    int mpptOutput = (rawInput > threshold) ? rawInput - threshold : 0;
    return constrain(mpptOutput, 0, 255);
}
