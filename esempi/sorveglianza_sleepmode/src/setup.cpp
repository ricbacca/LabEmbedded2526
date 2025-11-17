#include "Setup.h"
#include "Arduino.h"

Timer* timer = new Timer();
bool wakeUp = false;
SurveillanceStates currentState = STANDBY;

void pinSetup() {
    Serial.begin(9600);

    pinMode(TRIGPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);  
    pinMode(PIR, INPUT);
    pinMode(LEDPIN, OUTPUT);
    pinMode(BUTTON, INPUT);
    
    Serial.println("INITIALIZING PIR...10 seconds");
    delay(10000);
    Serial.println("DONE!");
}