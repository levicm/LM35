/*
  LM35Thermometer.h - Thermometer library for use LM35 - implementation
  Copyright (c) 2012 Levi Mota.  All right reserved.
*/

// include core Wiring API
#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

// include this library's description file
#include "LM35Thermometer.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances
Thermometer::Thermometer(void) {
  // initialize this instance's variables
  setSamples(500);
  setHighRes(false);
}

Thermometer::Thermometer(int pSamples) {
  // initialize this instance's variables
  setSamples(pSamples);
  setHighRes(false);
}

Thermometer::Thermometer(int pSamples, bool pHighRes) {
  // initialize this instance's variables
  setSamples(pSamples);
  setHighRes(pHighRes);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void Thermometer::setSamples(int pSamples) {
  samples = pSamples;
}

void Thermometer::setHighRes(bool pHighRes) {
  highRes = pHighRes;
  if (highRes) {
    analogReference(HIGH_RES);
  } else {
    analogReference(LOW_RES);
  }
}

double Thermometer::read(int port) {
  Serial.println(port);
  Serial.println(samples);
  Serial.println(highRes);
  Serial.println(analogRead(port));
  double tempSensor = 0.0;
  for (int i = 0; i < samples; i++) {
    if (highRes) {
      tempSensor = tempSensor + (analogRead(port) / 9.309);
	} else {
      tempSensor = tempSensor + (analogRead(port) / 2.048);
	}
  } 
  tempSensor = tempSensor / samples; 
  lastRead = tempSensor;
  return tempSensor;
}

double Thermometer::getLastRead() {
  return lastRead;
}

double Thermometer::toFahrenheit(double celsius) {
  return 1.8 * celsius + 32;
}

double Thermometer::toKelvin(double celsius) {
  return celsius + 273.15;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library
