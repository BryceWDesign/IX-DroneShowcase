// PiezoHarvester.cpp
// IX-DroneShowcase: Source for Piezoelectric Energy Harvester logic
// Author: BryceWDesign
// License: MIT

#include "PiezoHarvester.h"
#include <Arduino.h>

void PiezoHarvester::init() {
  pinMode(PIEZO_INPUT_PIN, INPUT);
  smoothedValue = 0;
}

int PiezoHarvester::readEnergy() {
  int raw = analogRead(PIEZO_INPUT_PIN);
  smoothedValue = (smoothedValue * 0.9) + (raw * 0.1);

  return estimateEnergy((int)smoothedValue);
}

int PiezoHarvester::estimateEnergy(int smoothed) {
  float voltage = (smoothed / 1023.0) * 5.0; // assuming 5V ADC
  float power = (voltage * voltage) / internalResistance; // P = V^2 / R
  return (int)(power * 1000); // convert W to mW
}
