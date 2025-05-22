// PiezoHarvester.cpp
// IX-DroneShowcase: Source for Piezoelectric Energy Harvester logic
// Author: BryceWDesign
// License: MIT

#include "PiezoHarvester.h"
#include <Arduino.h>

void PiezoHarvester::init() {
  pinMode(PIEZO_INPUT_PIN, INPUT);
  smoothedValue = 0.0;
}

int PiezoHarvester::readEnergy() {
  int raw = analogRead(PIEZO_INPUT_PIN);

  // Simple exponential moving average
  smoothedValue = 0.9 * smoothedValue + 0.1 * raw;

  return estimateEnergy((int)smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
  // Convert analogRead value to voltage (assuming 3.3V ADC)
  float voltage = (smoothed / 1023.0) * 3.3;

  // Estimate power = V^2 / R (R is assumed internal resistance)
  float power_mW = (voltage * voltage / internalResistance) * 1000.0;

  return (int)power_mW;
}
