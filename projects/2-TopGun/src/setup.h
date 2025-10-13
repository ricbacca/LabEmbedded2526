#ifndef __SETUP__
#define __SETUP__

#include "Arduino.h"
#include "gameLogic.h"
#include "servo_motor_impl.h"

#define RED_LED 4             // LED rosso

#define TRIG_PIN 8           // Sonar HC-SR04 Trig Pin
#define ECHO_PIN 7           // Sonar HC-SR04 Echo Pin
#define PIR 2                // Pir sensor

#define SERVO 9             // ServoMotore
#define CALIBRATION_TIME_SEC 3

extern ServoMotor* turret;

void pinSetup();

#endif