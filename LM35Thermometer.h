/*
  LM35Thermometer.h - Thermometer library for use LM35 - description
  Copyright (c) 2012 Levi Mota.  All right reserved.
*/

// ensure this library description is only included once
#ifndef LM35Thermometer_h
#define LM35Thermometer_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define HIGH_RES INTERNAL1V1
#define LOW_RES DEFAULT
#else
#define HIGH_RES INTERNAL
#define LOW_RES DEFAULT
#endif

// library interface description
class Thermometer
{
  // user-accessible "public" interface
  public:
    // constructors
    Thermometer(void);
    Thermometer(int samples);
    Thermometer(int samples, bool highRes);
	// setters
    void setSamples(int samples);
    void setHighRes(bool highRes); 
	// readers
    double read(int port);
    double getLastRead(void);
	// conversors
	double toFahrenheit(double celsius);
	double toKelvin(double celsius);

  // library-accessible "private" interface
  private:
    bool highRes;
    int samples;
    double lastRead;
};

#endif