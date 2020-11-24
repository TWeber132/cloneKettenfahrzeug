#ifndef _Kettenfahrzeug_Ultraschallsensor_h_INCLUDED_
#define _Kettenfahrzeug_Ultraschallsensor_h_INCLUDED_

#include "Arduino.h"
#include <Ultrasonic.h>


class Kettenfahrzeug_Ultraschallsensor
{
  public:
    Kettenfahrzeug_Ultraschallsensor(int pinSensor1, int pinSensor2);
    long RangeInCentimeters;
    void sensorIni();
    void sensorRead();
  private:
    int _pinSensor1;
    int _pinSensor2;
    bool ja = false;
};
#endif
