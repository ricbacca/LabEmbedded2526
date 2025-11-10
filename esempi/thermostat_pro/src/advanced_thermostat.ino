#include "Arduino.h"
#include "setup.h"
#include "Temp.h"
#include "logic.h"

void setup() {
    Serial.begin(115200);

    pinSetup();
    resetThermostat();
}


void loop() {
    float currentTemp = readCurrentTemperature();
    changeEcoComfort();

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
            break;

        case ECO_STANDBY:
            if (currentTemp < ecoSetPoint) {
                currentState = ECO_HEATING;
                Serial.println("→ ECO_HEATING");
            }
            break;

        case ECO_HEATING:
            if (currentTemp >= ecoSetPoint) {
                currentState = ECO_STANDBY;
                Serial.println("→ ECO_STANDBY");
            }
            break;
    }

}
