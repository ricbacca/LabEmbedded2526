#ifndef __INTERRUPTLOGIC__
#define __INTERRUPTLOGIC__

#include <avr/sleep.h>

void interruptRoutine();

void enterPowerSaveMode(int wakeupPin, int mode);

#endif