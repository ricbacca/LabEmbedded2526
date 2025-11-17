#include "surveillanceLogic.h"
#include "Sonar.h"

void standby() {
    Serial.println("Sleeping STANDBY");

    enterPowerSaveMode(BUTTON, RISING);

    if(wakeUp && digitalRead(BUTTON) == HIGH){
        currentState = ARMED;
        Serial.println("Switching to ARMED");
    }
}

void armed() {
    Serial.println("Sleeping ARMED");
    enterPowerSaveMode(PIR, RISING);

    if(wakeUp && digitalRead(PIR) == HIGH){
        currentState = DETECTED;
        Serial.println("Switching to DETECTED");
    }
}

void detected() {
    if(getDistance(TRIGPIN, ECHOPIN) < 100){
        currentState = ALARM;
        Serial.println("Switching to ALARM");
    }
}

void alarm() {
    digitalWrite(LEDPIN, HIGH);

    // ATTENZIONE
    // void Timer::waitForNextTick()
    //    while (!timerFlag){}
    //    timerFlag = false;
    timer->setupPeriod(TIMER_PERIOD);
    timerFlag = false;
    timer->waitForNextTick();

    currentState = STANDBY;
    digitalWrite(LEDPIN, LOW);
    Serial.println("Switching to STANDBY");
}