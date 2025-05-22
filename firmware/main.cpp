#include <Arduino.h>

// IX Drone Showcase Main Firmware
// Version 1.0 - 2025-05-22

// Hardware pins
const int ledPin = 13;

// Setup function runs once at startup
void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    Serial.println("IX-DroneShowcase firmware started.");
}

// Loop function runs repeatedly
void loop() {
    digitalWrite(ledPin, HIGH);   // Turn the LED on
    delay(500);                   // Wait for 500ms
    digitalWrite(ledPin, LOW);    // Turn the LED off
    delay(500);                   // Wait for 500ms
}
