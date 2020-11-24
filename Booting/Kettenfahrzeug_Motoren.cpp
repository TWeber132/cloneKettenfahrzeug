#include "Kettenfahrzeug_Motoren.h"
#include "Arduino.h"

Kettenfahrzeug_Motoren::Kettenfahrzeug_Motoren(int pin) {
  Serial.print("Constructer -> Kettenfahrzeug Motoren");
}

void Kettenfahrzeug_Motoren::aktorIni()
{
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  Serial.print("Motoren initialisiert");
}

void Kettenfahrzeug_Motoren::driveMotor(uint8_t motor, uint8_t direct, uint8_t pwm)
{
  if (motor == MOTOR_1) {
    if (direct == CW) {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if (direct == CCW) {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);
    }
    else if (direct == BRAKE) {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);
      Serial.println(" - motor 1 stopped");
    }
    analogWrite(PWM_MOTOR_1, pwm);

  } else if (motor == MOTOR_2) {
    if (direct == CW) {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if (direct == CCW) {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);
    }
    else if (direct == BRAKE) {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);
      Serial.println(" - motor 2 stopped");
    }
    analogWrite(PWM_MOTOR_2, pwm);
  }
}

void Kettenfahrzeug_Motoren::stop()
{
  Serial.println("Attempting to decrease speed...");
  setSpeedLimit(0);
  
  while (currentSpeed > wantedSpeed) {
    currentSpeed = currentSpeed - 10;
    driveMotor(MOTOR_1, motorState, currentSpeed);
    driveMotor(MOTOR_2, motorState, currentSpeed);
    Serial.println(" - current speed: " + currentSpeed);
    delay(100);
  }
  
  Serial.println("Attempting to stop Motors...");
  motorState = BRAKE;
  driveMotor(MOTOR_1, motorState, 0);
  driveMotor(MOTOR_2, motorState, 0);
}

void Kettenfahrzeug_Motoren::setSpeedLimit(int limit)
{
  if (limit > wantedSpeed) {
    Serial.print("Attempting to increase speed limit to " + limit);
    if (limit > 250) {
      limit = 250;
      Serial.println("Speed limit maxed out at 250");
    } else if (limit < wantedSpeed) {
      limit = wantedSpeed;
      Serial.println("Speed limit did not increase");
    }
    wantedSpeed = limit;

  } else if (limit < wantedSpeed) {
    Serial.print("Attempting to decrease speed limit to " + limit);
    if (limit < 0) {
      limit = 0;
      Serial.println("Speed limit mined out at 0");
    } else if (limit > wantedSpeed) {
      limit = wantedSpeed;
      Serial.println("Speed limit did not decrease");
    }
    wantedSpeed = limit;

  } else {
    Serial.print("Speed stays at" + limit);
  }
}

void Kettenfahrzeug_Motoren::forwards()
{
  Serial.println("Forward");
  if (motorState != CW) stop();
  motorState = CW;
  
  while (currentSpeed < wantedSpeed) {
    currentSpeed = currentSpeed + 10;
    driveMotor(MOTOR_1, motorState, currentSpeed);
    driveMotor(MOTOR_2, motorState, currentSpeed);
    delay(250);
  }
}

void Kettenfahrzeug_Motoren::backwards()
{
  Serial.println("Reverse");
  if (motorState != CCW) stop();
  motorState = CCW;
  setSpeedLimit(30); // Geschwindigkeitsbegrenzung für das Rückwärtsfahren

  while (currentSpeed < wantedSpeed) {
    currentSpeed = currentSpeed + 10;
    driveMotor(MOTOR_1, motorState, currentSpeed);
    driveMotor(MOTOR_2, motorState, currentSpeed);
    delay(250);
  }
}

void Kettenfahrzeug_Motoren::turn(int winkel)
{
  Serial.print("Turning by " + (winkel + 360 - winkel));
  Serial.println("degrees...");
  delay(1000);
  Serial.println("Done!");
  stop();
}
