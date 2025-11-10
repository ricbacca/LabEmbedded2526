#ifndef __SETUP__
#define __SETUP__

#include "Arduino.h"
#include "Timer.h"

#define TEMP_PIN A0

void pinSetup();

void initTimer();

const float comfortSetPoint = 20;
const float ecoSetPoint = 18;
const float tempThreshold = 2;


enum TermostatStates { COMFORT_STANDBY, COMFORT_HEATING, ECO_STANDBY, ECO_HEATING };
extern TermostatStates currentState;

extern Timer modeTimer;


#endif