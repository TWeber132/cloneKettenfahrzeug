#ifndef _Kettenfahrzeug_GPS_h_INCLUDED_
#define _Kettenfahrzeug_GPS_h_INCLUDED_

#include "Arduino.h"
#include <Adafruit_GPS.h>
#define GPSSerial Serial1


class Kettenfahrzeug_GPS
{
  public:
    Kettenfahrzeug_GPS(int pin);
    String NMEA1; //Variable für eingehenden NMEA Daten
    String NMEA2; //Variable für eingehenden NMEA Daten
    char c; //Variable für eingehende GPS Daten                                   y/Long
    float degLong; //Variable für den Längengrad                                  ^             *
    float degWholeLong; //Variable für den ganzzaligen Teil des Längengrades      |
    float degDecLong; //Variable für den Dezimalteil des Längengrades             |
    float degLat; //Variable für den Breitengrad                                  |
    float degWholeLat; //Variable für den ganzzaligen Teil des Breitengrades      |
    float degDecLat; //Variable für den Dezimalteil des Breitengrades             --------------> x/Lat
    float x;
    float y;
    uint32_t timer = millis();

    void sensorIni(int baudrate);
    void readGPS();
    void clearGPS();
  private:
    int _pin;
    int _baudrate;
};

#endif
