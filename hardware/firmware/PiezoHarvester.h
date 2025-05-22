// PiezoHarvester.h
// IX-DroneShowcase: Header for Piezoelectric Harvester module
// Author: BryceWDesign
// License: MIT

#ifndef PIEZO_HARVESTER_H
#define PIEZO_HARVESTER_H

#define PIEZO_INPUT_PIN A0  // Define analog input pin for piezo

class PiezoHarvester {
public:
  void init();
  int readEnergy();  // Returns energy estimate in mW

private:
  float smoothedValue;
  const float internalResistance = 1000000.0; // Ohms, estimate for modeling

  int estimateEnergy(int smoothed);
};

#endif // PIEZO_HARVESTER_H
