// EnergyHarvester.h
// IX-DroneShowcase: Header for adaptive ambient energy harvesting
// Author: BryceWDesign
// License: MIT

#ifndef ENERGY_HARVESTER_H
#define ENERGY_HARVESTER_H

#include "RFHarvester.h"
#include "ThermalHarvester.h"
#include "PiezoHarvester.h"
#include "SupercapBank.h"
#include "SolidStateBattery.h"
#include <Arduino.h>

class EnergyHarvester {
public:
    void init();
    void update();
    int getEnergy() const { return currentEnergy; }

private:
    RFHarvester rfHarvester;
    ThermalHarvester thermalHarvester;
    PiezoHarvester piezoHarvester;

    SupercapBank supercapBank;
    SolidStateBattery battery;

    int currentEnergy;
    void logEnergyStatus(int energy);
};

#endif // ENERGY_HARVESTER_H
