// EnergyHarvester.h
// IX-DroneShowcase: Ambient energy harvester interface
// Author: BryceWDesign
// License: MIT

#ifndef ENERGY_HARVESTER_H
#define ENERGY_HARVESTER_H

#include <Arduino.h>
#include "RFHarvester.h"
#include "ThermalHarvester.h"
#include "PiezoHarvester.h"
#include "SuperCapBank.h"
#include "Battery.h"

class EnergyHarvester {
public:
    void init();
    void update();
private:
    RFHarvester rfHarvester;
    ThermalHarvester thermalHarvester;
    PiezoHarvester piezoHarvester;

    SuperCapBank supercapBank;
    Battery battery;

    int currentEnergy;

    void logEnergyStatus(int energy);
};

#endif // ENERGY_HARVESTER_H
