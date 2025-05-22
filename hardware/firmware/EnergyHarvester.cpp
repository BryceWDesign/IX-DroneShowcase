// EnergyHarvester.cpp
// IX-DroneShowcase: Adaptive Ambient Energy Harvester Implementation
// Author: BryceWDesign
// License: MIT

#include "EnergyHarvester.h"

void EnergyHarvester::init() {
    rfHarvester.init();
    thermalHarvester.init();
    piezoHarvester.init();
    supercapBank.init();
    battery.init();
    currentEnergy = 0;
}

void EnergyHarvester::update() {
    int rfPower     = rfHarvester.readPower();     // mW
    int thermalPower= thermalHarvester.readPower(); // mW
    int piezoPower  = piezoHarvester.readPower();  // mW

    int totalInput  = rfPower + thermalPower + piezoPower;

    supercapBank.charge(totalInput);
    battery.trickleCharge(totalInput / 4); // send portion to battery

    currentEnergy = totalInput;

    logEnergyStatus(currentEnergy);
}

void EnergyHarvester::logEnergyStatus(int energy) {
    Serial.print("[EnergyHarvester] Input Power (mW): ");
    Serial.println(energy);
}
