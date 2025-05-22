// PiezoHarvester.h
// IX-DroneShowcase: Header for Piezoelectric Energy Harvester
// Author: BryceWDesign
// License: MIT

#ifndef PIEZO_HARVESTER_H
#define PIEZO_HARVESTER_H

#define PIEZO_INPUT_PIN A0

class PiezoHarvester {
public:
  void init();
  int readEnergy();

private:
  float smoothedValue;
  const float internalResistance = 1000.0; // Ohms, approximate
  int estimateEnergy(int smoothed);
};

#endif // PIEZO_HARVESTER_H
