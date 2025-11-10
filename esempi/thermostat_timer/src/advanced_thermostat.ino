#include "Arduino.h"
#include "setup.h"
#include "Temp.h"
#include "logic.h"
 
#define PIR_PORT 2
 
bool isMoving = false;
 
void setup() {
    Serial.begin(115200);
 
    pinMode(PIR_PORT, INPUT);
    pinSetup();
    initTimer();
    resetThermostat();
}
 
void waiting() {
    if (timerFlag) {
        // CAMBIO DI STATO
        if (currentState == COMFORT_STANDBY) {
            currentState = ECO_STANDBY;
        } else if (currentState == COMFORT_HEATING) {
            currentState = ECO_HEATING;
        }
        timerFlag = false;
    }
}
 
void loop() {
    float currentTemp = readCurrentTemperature();
 
    isMoving = digitalRead(PIR_PORT);
    waiting();
 
    switch (currentState) {
        case COMFORT_STANDBY:
            if (currentTemp < comfortSetPoint) {
                currentState = COMFORT_HEATING;
                Serial.println("COMFORT_HEATING");
            }
            break;
 
        case COMFORT_HEATING:
            if (currentTemp >= comfortSetPoint) {
                currentState = COMFORT_STANDBY;
                Serial.println("→ COMFORT_STANDBY");
            }
 
            if(!isMoving) {
                currentState = ECO_HEATING;
                waiting();
            }
            break;
 
        case ECO_STANDBY:
            if (currentTemp < ecoSetPoint) {
                currentState = ECO_HEATING;
                Serial.println("→ ECO_HEATING");
            }
 
            if(isMoving) {
                currentState = COMFORT_STANDBY;
                waiting();
            }
            break;
 
        case ECO_HEATING:
            if (currentTemp >= ecoSetPoint) {
                currentState = ECO_STANDBY;
                Serial.println("→ ECO_STANDBY");
            }
 
            if(isMoving) {
                currentState = COMFORT_HEATING;
                waiting();
            }
            break;
    }
 
}
 
 