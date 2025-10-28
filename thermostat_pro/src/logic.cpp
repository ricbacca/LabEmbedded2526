#include "logic.h"

TermostatStates currentState = COMFORT_STANDBY;
unsigned long lastSwitch = 0;

void resetThermostat() {
    currentState = COMFORT_STANDBY;
    lastSwitch = millis();
}

void changeEcoComfort() {
  unsigned long now = millis();

  if (now - lastSwitch >= MODE_SWITCH_TIME) {
    lastSwitch = now;
    if (currentState == COMFORT_HEATING || currentState == COMFORT_STANDBY) {
      currentState = ECO_STANDBY;
      Serial.println("Cambio ad ECO");
    } else {
      currentState = COMFORT_STANDBY;
      Serial.println("Cambio a COMFORT");
    }
  }
}