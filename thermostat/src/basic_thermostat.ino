#include "Arduino.h"

#define TEMP_PIN A0

float setPoint;
float current;
const float BETA = 3950;

enum States{STANDBY, HEATING};
States currentState;

void setup(){
    Serial.begin(115200);
    pinMode(TEMP_PIN, INPUT);
    current = 0;
    setPoint = 18;
    currentState = STANDBY;
}


void loop(){
    int analogValue = analogRead(TEMP_PIN);
    current = 1 / (log(1 / (1023. / analogValue - 1)) 
                / BETA + 1.0 / 298.15) - 273.15;
                
    switch(currentState) {
        case STANDBY:
            if (current < setPoint) {
                currentState = HEATING;
                Serial.println("STATE CHANGING TO HEATING");
            }
            break;
        case HEATING:
            if (current >= setPoint) {
                currentState = STANDBY;
                Serial.println("STATE CHANGING TO STANDBY");
            }
            break;
    }

    delay(500);
}