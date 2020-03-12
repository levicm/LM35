/*
  LM35.cpp - Temperature Sensor Library for use LM35 - implementation
  2012 - Levi Mota
*/

// include core Wiring API
#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

// include this library's description file
#include "LM35.h"

const double DIVIDER_HIGH_RES = 9.309;
const double DIVIDER_LOW_RES = 2.048;

// Constructors /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances
LM35Sensor::LM35Sensor(void) {
  // initialize this instance's variables
  setSamples(500);	
  setHighRes(false);
}

LM35Sensor::LM35Sensor(int pSamples) {
  // initialize this instance's variables
  setSamples(pSamples);
  setHighRes(false);
}

LM35Sensor::LM35Sensor(int pSamples, bool pHighRes) {
  // initialize this instance's variables
  setSamples(pSamples);
  setHighRes(pHighRes);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void LM35Sensor::setSamples(int pSamples) {
  samples = pSamples;
}

void LM35Sensor::setHighRes(bool pHighRes) {
  highRes = pHighRes;
  if (highRes) {
    divider = DIVIDER_HIGH_RES;
    analogReference(HIGH_RES);
  } else {
    divider = DIVIDER_LOW_RES;
    analogReference(LOW_RES);
  }
}

void LM35Sensor::read(int port) {
  double tempSum = 0.0;
  for (int i = 0; i < samples; i++) {
    tempSum = tempSum + (analogRead(port) / divider);
  } 
  celsius = tempSum / samples; 
  fahrenheit = 1.8 * celsius + 32;
  kelvin = celsius + 273.15;
}

double LM35Sensor::getCelsius(void) {
  return celsius;
}

double LM35Sensor::getFahrenheit(void) {
  return fahrenheit;
}

double LM35Sensor::getKelvin(void) {
  return kelvin;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library
