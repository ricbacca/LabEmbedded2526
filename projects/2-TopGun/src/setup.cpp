#include "Setup.h"

ServoMotor* turret;

void pinSetup(){
    // Red Led
    pinMode(RED_LED, OUTPUT);

    // Pir sensor activation and calibration
    pinMode(PIR, INPUT);
    Serial.print("Calibrating sensor...");
    for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.print("Done");

    // Sonar
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);  

    //Servo motor
    turret = new ServoMotorImpl(9);
}