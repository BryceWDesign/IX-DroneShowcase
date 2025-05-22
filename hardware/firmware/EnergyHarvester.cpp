// EnergyHarvester.cpp
// IX-DroneShowcase: Ambient energy harvester implementation
// Author: BryceWDesign
// License: MIT

#include "EnergyHarvester.h"

// Initialize energy harvester hardware and state
void EnergyHarvester::init() {
    // Initialize RF harvester
    rfHarvester.init();
    // Initialize thermal TEG modules
    thermalHarvester.init();
    // Initialize piezoelectric harvesters
    piezoHarvester.init();

    supercapBank.init();
    battery.init();

    currentEnergy = 0;
}

// Update harvesting from all sources, manage power routing
void EnergyHarvester::update() {
    int rfPower = rfHarvester.readPower();
    int thermalPower = thermalHarvester.readPower();
    int piezoPower = piezoHarvester.readPower();

    // Aggregate power
    currentEnergy = rfPower + thermalPower + piezoPower;

    // Route energy: supercaps first, then battery
    if (supercapBank.canCharge()) {
        supercapBank.charge(currentEnergy);
    } else {
        battery.charge(currentEnergy);
    }

    // Monitor and log
    logEnergyStatus(currentEnergy);
}

void EnergyHarvester::logEnergyStatus(int energy) {
    Serial.print("Current harvested energy (mW): ");
    Serial.println(energy);
}

