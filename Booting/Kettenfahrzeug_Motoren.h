#ifndef _Kettenfahrzeug_Motoren_h_INCLUDED_
#define _Kettenfahrzeug_Motoren_h_INCLUDED_

#include "Arduino.h"
#include "Kettenfahrzeug_Ultraschallsensor.h"
#include "Kettenfahrzeug_Temperatursensor.h"

//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8
#define PWM_MOTOR_1 5
//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9
#define PWM_MOTOR_2 6
//Motor Shield
#define BRAKE 0
#define CW 1
#define CCW 2
#define CS_THRESHOLD 15 // Definition des Sicherheitsstroms

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1


class Kettenfahrzeug_Motoren
{
  public:
    Kettenfahrzeug_Motoren(int pin);

    short currentSpeed = 0; //Startgeschwindigkeit und aktuelle Geschwindigkeit (PWM)
    short wantedSpeed = 0; //Geschwindigkeit in der das Kettenfahrzeug losfahren kann
    unsigned short motorState = BRAKE; //Startzustand
    void aktorIni();
    void stop();
    void setSpeedLimit(int limit);
    void forwards();
    void backwards();
    void turn(int winkel);
  private:
    void driveMotor(uint8_t motor, uint8_t direct, uint8_t pwm);
};
#endif
