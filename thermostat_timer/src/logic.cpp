#include "logic.h"

TermostatStates currentState = COMFORT_STANDBY;

void resetThermostat() {
    currentState = COMFORT_STANDBY;
}

void changeEcoComfort() {
  if (timerFlag) {
      timerFlag = false;
      if (currentState == COMFORT_HEATING || currentState == COMFORT_STANDBY) {
          currentState = ECO_STANDBY;
          Serial.println("Cambio ad ECO");
      } else {
          currentState = COMFORT_STANDBY;
          Serial.println("Cambio a COMFORT");
      }
  }
}