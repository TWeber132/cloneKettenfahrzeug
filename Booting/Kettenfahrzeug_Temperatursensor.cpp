#include "Kettenfahrzeug_Temperatursensor.h"
#include "Arduino.h"

OmronD6T sensor;

Kettenfahrzeug_Temperatursensor::Kettenfahrzeug_Temperatursensor() {
  int trss = 53;
}

void Kettenfahrzeug_Temperatursensor::sensorIni() {
 Serial.print("Initialisierung Temperatursensor!");
}
