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
  smoothedValue = 0.9 * smoothedValue + 0.1 * rawValue;

  return estimateEnergy((int)smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
  float voltage = (smoothed / 1023.0) * 5.0; // assuming 5V ADC reference
  float power_mW = (voltage * voltage) / internalResistance * 1000.0;
  return (int)power_mW;
}
