#include "Kettenfahrzeug_Ultraschallsensor.h"
#include "Arduino.h"

#define ultraschallSensor1 7
#define ultraschallSensor2 6


Kettenfahrzeug_Ultraschallsensor::Kettenfahrzeug_Ultraschallsensor(int pinSensor1, int pinSensor2) {
  _pinSensor1 = pinSensor1;
  _pinSensor2 = pinSensor2;

}

void Kettenfahrzeug_Ultraschallsensor::sensorIni() {

  Serial.print("Initialisierung Ultraschallsensor!");
}

void Kettenfahrzeug_Ultraschallsensor::sensorRead() {
  Ultrasonic sensor1(_pinSensor1);
  Ultrasonic sensor2(_pinSensor2);
  Serial.println("The distance to obstacles in front is: ");
  RangeInCentimeters = sensor1.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);
}
