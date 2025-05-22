// PiezoHarvester.h
// IX-DroneShowcase: Header for Piezoelectric Energy Harvester
// Author: BryceWDesign
// License: MIT

#ifndef PIEZO_HARVESTER_H
#define PIEZO_HARVESTER_H

#define PIEZO_INPUT_PIN A0  // Analog pin for piezo input

class PiezoHarvester {
public:
  void init();
  int readEnergy();  // Returns estimated power in mW

private:
  float smoothedValue;
  const float internalResistance = 1000.0; // ohms
  int estimateEnergy(int smoothed);
};

#endif // PIEZO_HARVESTER_H
