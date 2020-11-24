#ifndef _Kettenfahrzeug_Temperatursensor_h_INCLUDED_
#define _Kettenfahrzeug_Temperatursensor_h_INCLUDED_

#include "Arduino.h"
#include <OmronD6T.h>

class Kettenfahrzeug_Temperatursensor
{
  public:
    Kettenfahrzeug_Temperatursensor();
    bool temp = true;
    void sensorIni();
  private:
    int _pin;
};
#endif
