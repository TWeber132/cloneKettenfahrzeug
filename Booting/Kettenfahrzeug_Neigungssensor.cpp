#include "Kettenfahrzeug_Neigungssensor.h"
#include "Arduino.h"

Adafruit_MMA8451 mma = Adafruit_MMA8451();

Kettenfahrzeug_Neigungssensor::Kettenfahrzeug_Neigungssensor(int pin) {
  int fff = 23 + pin;
  Serial.print("Constructer -> Kettenfahrzeug Neigungssensor");
  Serial.print("Quelle: https://github.com/adafruit/Adafruit_MMA8451_Library");
}

void Kettenfahrzeug_Neigungssensor::sensorIni() {
  Serial.print ("Initialisierung Neigungssensor");
  if (!mma.begin()) {
    Serial.println("Couldn't start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_2_G);
  Serial.print("Range = "); Serial.print(2 << mma.getRange());
  Serial.println("G");
}

void Kettenfahrzeug_Neigungssensor::sensorRead() {
  mma.read();
  Serial.print("X:\t"); Serial.print(mma.x);
  Serial.print("\tY:\t"); Serial.print(mma.y);
  Serial.print("\tZ:\t"); Serial.print(mma.z);
  Serial.println();
  /* Get a new sensor event */
  sensors_event_t event;
  mma.getEvent(&event);
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.println("m/s^2 ");
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();

  switch (o) {
    case MMA8451_PL_PUF:
      Serial.println("Portrait Up Front");
      break;
    case MMA8451_PL_PUB:
      Serial.println("Portrait Up Back");
      break;
    case MMA8451_PL_PDF:
      Serial.println("Portrait Down Front");
      break;
    case MMA8451_PL_PDB:
      Serial.println("Portrait Down Back");
      break;
    case MMA8451_PL_LRF:
      Serial.println("Landscape Right Front");
      break;
    case MMA8451_PL_LRB:
      Serial.println("Landscape Right Back");
      break;
    case MMA8451_PL_LLF:
      Serial.println("Landscape Left Front");
      break;
    case MMA8451_PL_LLB:
      Serial.println("Landscape Left Back");
      break;
  }
  _xAcc = event.acceleration.x;
  _yAcc = event.acceleration.y;
  _zAcc = event.acceleration.z;
}
