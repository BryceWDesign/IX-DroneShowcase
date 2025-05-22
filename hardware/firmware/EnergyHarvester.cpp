// EnergyHarvester.cpp
// IX-DroneShowcase: Ambient energy harvester implementation
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
    int rfEnergy = rfHarvester.harvest();
    int thermalEnergy = thermalHarvester.harvest();
    int piezoEnergy = piezoHarvester.harvest();

    int totalHarvested = rfEnergy + thermalEnergy + piezoEnergy;

    // Store harvested energy first in supercapacitors
    supercapBank.storeEnergy(totalHarvested);

    // If supercapacitors are full, trickle charge battery
    if(supercapBank.isFull()) {
        battery.storeEnergy(supercapBank.releaseExcess());
    }

    currentEnergy = supercapBank.getStoredEnergy() + battery.getStoredEnergy();

    logEnergyStatus(currentEnergy);
}

void EnergyHarvester::logEnergyStatus(int energy) {
    Serial.print("Current harvested energy (mJ): ");
    Serial.println(energy);
}
