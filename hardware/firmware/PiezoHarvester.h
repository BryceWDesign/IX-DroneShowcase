// PiezoHarvester.h
// IX-DroneShowcase: Header for Piezoelectric Energy Harvester
// Author: BryceWDesign
// License: MIT

#ifndef PIEZOHARVESTER_H
#define PIEZOHARVESTER_H

#define PIEZO_INPUT_PIN A0  // ADC input for piezo signal

class PiezoHarvester {
public:
  void init();         // Initialize the pin and variables
  int readEnergy();    // Read and return estimated power in mW

private:
  float smoothedValue;             // For signal smoothing
  const float internalResistance = 100000.0; // Assumed resistance in ohms

  int estimateEnergy(int smoothed); // Convert signal to estimated mW
};

#endif
