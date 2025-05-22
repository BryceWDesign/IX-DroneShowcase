// PiezoHarvester.h
// IX-DroneShowcase: Header for Piezoelectric Energy Harvester Class
// Author: BryceWDesign
// License: MIT

#ifndef PIEZOHARVESTER_H
#define PIEZOHARVESTER_H

#define PIEZO_INPUT_PIN A0

class PiezoHarvester {
  public:
    void init();
    int readEnergy();

  private:
    int estimateEnergy(int smoothed);
    float smoothedValue;
    const float internalResistance = 100000.0; // ohms
};

#endif
