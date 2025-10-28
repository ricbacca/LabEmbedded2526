#include "Setup.h"

Timer modeTimer;

void pinSetup() {
    pinMode(TEMP_PIN, INPUT);
}

void initTimer() {
    modeTimer.setupPeriod(10000);
}