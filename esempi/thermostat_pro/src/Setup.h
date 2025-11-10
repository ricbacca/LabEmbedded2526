#ifndef __SETUP__
#define __SETUP__

#include "Arduino.h"

#define TEMP_PIN A0

void pinSetup();

const float comfortSetPoint = 20;
const float ecoSetPoint = 18;
const float tempThreshold = 2;
const unsigned long MODE_SWITCH_TIME = 10000;


enum TermostatStates { COMFORT_STANDBY, COMFORT_HEATING, ECO_STANDBY, ECO_HEATING };
extern TermostatStates currentState;
extern unsigned long lastSwitch;

#endif