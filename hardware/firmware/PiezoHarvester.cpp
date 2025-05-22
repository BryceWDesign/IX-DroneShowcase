// PiezoHarvester.cpp
// IX-DroneShowcase: Implementation for Piezoelectric Harvester module
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
  smoothedValue = 0.8 * smoothedValue + 0.2 * rawValue;

  return estimateEnergy((int)smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
  // Approximate voltage from 10-bit ADC (assuming 5V reference)
  float voltage = (smoothed / 1023.0) * 5.0;
  float power_mW = (voltage * voltage) / internalResistance * 1000.0;

  return (int)power_mW;
}
