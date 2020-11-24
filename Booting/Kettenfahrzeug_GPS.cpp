#include "Kettenfahrzeug_GPS.h"
#include "Arduino.h"

Adafruit_GPS GPS(&GPSSerial);

Kettenfahrzeug_GPS::Kettenfahrzeug_GPS(int pin) {
  _pin = pin;
}

void Kettenfahrzeug_GPS::sensorIni(int baudrate) {
  int _baudrate = baudrate;
  Serial.println("Adafruit GPS library basic test!");
  GPS.begin(_baudrate);
  GPS.sendCommand("$PGCMD,33,0*6D"); // <-----------------------------------
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);
  delay(1000);
  GPSSerial.println(PMTK_Q_RELEASE);
}

void Kettenfahrzeug_GPS::readGPS() { // Funktion, welche zwei NMEA Datensätze liest und speichert
  clearGPS(); // Reinigen des Serial Ports
  while (!GPS.newNMEAreceived()) { // Liest solange die GPS Daten bis ein ganzer NMEA Satz vorhanden ist
    c = GPS.read(); // liest die Daten vom GPS
  }
  GPS.parse(GPS.lastNMEA()); // Wenn ein ganzer Satz da ist verbinde alle Daten
  NMEA1 = GPS.lastNMEA(); // Sobald Satz vollständig speichere ihn in Variable NMEA1
  while (!GPS.newNMEAreceived()) { // Liest zweiten unterschiedlichen NMEA Satz vom GPS
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  NMEA2 = GPS.lastNMEA();

  degWholeLong = float(int(GPS.longitude / 100)); //Berechnung des ganzzaligen Teils des Längengrades
  degDecLong = (GPS.longitude - degWholeLong * 100) / 60; //Berechnung des Deziamlteils des Längengrades
  degLong = degWholeLong + degDecLong;
  if (GPS.lon == 'W') (degLong = (-1) * degLong);

  degWholeLat = float(int(GPS.latitude / 100)); //Berechnung des ganzzaligen Teils des Breitengrades
  degDecLat = (GPS.latitude - degWholeLat * 100) / 60; //Berechnung des Dezimalteils des Längengrades
  degLat = degWholeLat + degDecLat;
  if (GPS.lat == 'S') (degLat = (-1) * degLat);
}

void Kettenfahrzeug_GPS::clearGPS() { //Zwischen dem Lesen der GPS Datensätze kommen immernoch Daten rein, welche gelöscht werden müssen um nicht zu stören
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
