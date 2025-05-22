// EnergyHarvester.h
// IX-DroneShowcase: Header for Adaptive Ambient Energy Harvester
// Author: BryceWDesign
// License: MIT

#ifndef ENERGY_HARVESTER_H
#define ENERGY_HARVESTER_H

#include "RFHarvester.h"
#include "ThermalHarvester.h"
#include "PiezoHarvester.h"
#include "SupercapBank.h"
#include "BatteryUnit.h"

class EnergyHarvester {
public:
    void init();
    void update();

private:
    RFHarvester rfHarvester;
    ThermalHarvester thermalHarvester;
    PiezoHarvester piezoHarvester;
    SupercapBank supercapBank;
    BatteryUnit battery;

    int currentEnergy;

    void logEnergyStatus(int energy);
};

#endif
