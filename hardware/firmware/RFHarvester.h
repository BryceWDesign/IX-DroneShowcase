// RFHarvester.h
// IX-DroneShowcase: Header for RF Energy Harvester Class
// Author: BryceWDesign
// License: MIT

#ifndef RFHARVESTER_H
#define RFHARVESTER_H

#define RF_INPUT_PIN A0  // Analog input from RF rectifier circuit
#define threshold 180     // Empirical threshold for MPPT-like adjustment

class RFHarvester {
public:
    void init();
    int readEnergy();
private:
    int lastReading;
    int mpptState;
    int applyMPPT(int rawInput);
};

#endif
