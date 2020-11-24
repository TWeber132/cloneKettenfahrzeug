#include "Kettenfahrzeug_GPS.h"
#include "Kettenfahrzeug_Neigungssensor.h"
#include "Kettenfahrzeug_Temperatursensor.h"
#include "Kettenfahrzeug_Ultraschallsensor.h"
#include "Kettenfahrzeug_Motoren.h"

Kettenfahrzeug_GPS kettenfahrzeug_GPS(12);
Kettenfahrzeug_Neigungssensor kettenfahrzeug_Neigungssensor(11);
Kettenfahrzeug_Temperatursensor kettenfahrzeug_Temperatursensor;
Kettenfahrzeug_Ultraschallsensor kettenfahrzeug_Ultraschallsensor(6, 7);
Kettenfahrzeug_Motoren kettenfahrzeug_Motoren(22);

boolean once = true;

void setup() {
  Serial.begin(112500);
  kettenfahrzeug_GPS.sensorIni(9600);
  kettenfahrzeug_Neigungssensor.sensorIni();
  kettenfahrzeug_Temperatursensor.sensorIni();
  kettenfahrzeug_Ultraschallsensor.sensorIni();
  kettenfahrzeug_Motoren.aktorIni();
}

void loop() {
  if (once) {
    kettenfahrzeug_Motoren.setSpeedLimit(50);
    kettenfahrzeug_Motoren.forwards();
    delay(1000);
    kettenfahrzeug_Motoren.backwards();
    delay(1000);
    kettenfahrzeug_Motoren.stop();
    Serial.println(" - - - Test completed - - - ");
    once = false;
  }
}
