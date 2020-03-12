/*
  LM35.h - Temperature Sensor Library for use LM35 - description
  2012 - Levi Mota.
*/

// ensure this library description is only included once
#ifndef LM35_h
#define LM35_h

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
class LM35Sensor
{
  // user-accessible "public" interface
  public:
    // constructors
    LM35Sensor(void);
    LM35Sensor(int samples);
    LM35Sensor(int samples, bool highRes);
	// setters
    void setSamples(int samples);
    void setHighRes(bool highRes); 
	// readers
    void read(int port);
	// getters
    double getCelsius(void);
	double getFahrenheit(void);
	double getKelvin(void);

  // library-accessible "private" interface
  private:
    bool highRes;
	double divider;
    int samples;
    
	double celsius;
    double fahrenheit;
    double kelvin;
};

#endif
