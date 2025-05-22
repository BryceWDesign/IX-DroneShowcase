// PiezoHarvester.cpp
// IX-DroneShowcase: Implementation for Piezoelectric Energy Harvester
// Author: BryceWDesign
// License: MIT

#include "PiezoHarvester.h"
#include <Arduino.h>

void PiezoHarvester::init() {
  pinMode(PIEZO_INPUT_PIN, INPUT);
  smoothedValue = 0.0;
}

int PiezoHarvester::readEnergy() {
  int rawValue = analogRead(PIEZO_INPUT_PIN);
  // Simple smoothing filter
  smoothedValue = (smoothedValue * 0.9) + (rawValue * 0.1);
  return estimateEnergy((int)smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
  // Estimate power output in milliwatts based on smoothed input
  // This is a placeholder linear approximation for demonstration
  float voltage = (smoothed / 1023.0) * 5.0; // ADC to voltage
  float power = (voltage * voltage) / internalResistance; // P=V^2/R
  return (int)(power * 1000); // Convert to milliwatts
}
