#include "interruptLogic.h"
#include "Arduino.h"
#include "Setup.h"

void interruptRoutine() {
  wakeUp = true;
}

void enterPowerSaveMode(int wakeupPin, int mode) {
  wakeUp = false;

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  attachInterrupt(digitalPinToInterrupt(wakeupPin), interruptRoutine, mode);

  while(!wakeUp) {
    sleep_mode();
    sleep_cpu();
  }

  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(wakeupPin));
}