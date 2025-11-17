#ifndef __SETUP__
#define __SETUP__

#include "Timer.h"

// INTERRUPT 0...COSA FA LA FUNZIONE DIGITAL PIN TO INTERRUPT ?
#define PIR 2

// SPOSTARLO AL 3 !! IL 12 SUPPORTA INTERRUPT ?
// INTERRUPT 1...
#define BUTTON 3

#define LEDPIN 4
#define ECHOPIN 7
#define TRIGPIN 8
#define TIMER_PERIOD 5000

extern Timer* timer;
extern bool wakeUp;

enum SurveillanceStates { STANDBY, ARMED, DETECTED, ALARM };
extern SurveillanceStates currentState;

void pinSetup();

#endif