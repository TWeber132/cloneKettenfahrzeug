#ifndef _Kettenfahrzeug_Neigungssensor_h_INCLUDED_
#define _Kettenfahrzeug_Neigungssensor_h_INCLUDED_

#include "Arduino.h"
#include <Adafruit_MMA8451.h>
#include <Wire.h>

class Kettenfahrzeug_Neigungssensor
{
  public:
    Kettenfahrzeug_Neigungssensor(int pin);
    void sensorIni();
    void sensorRead();
  private:
    int _pin;
    int _xAcc = 8192;
    int _yAcc = 8192;
    int _zAcc = 8192;
};
#endif
