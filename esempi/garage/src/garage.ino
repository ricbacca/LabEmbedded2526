#include <Servo.h>
#include "Arduino.h"
 
#define POT_PIN A0
#define SERVO_PIN 11
#define BUT_PIN 4
#define TRIGGER_PIN 8
#define ECHO_PIN 7
 
const float vs = 331.45 + 0.62*20;
 
enum States {STANDBY, DETECTED, MOVING_SONAR, MOVING_BUTTON};
States currentState;
 
Servo servoMotor;
int pot;
int servoAngle;
float distance;
 
void setup() {
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  pinMode(BUT_PIN, INPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
 
  servoMotor.attach(SERVO_PIN);
  pot = 0;
  servoAngle = 0;
  currentState = STANDBY;
}
 
float getDistance()
{
    /* invio impulso di setup*/
    digitalWrite(TRIGGER_PIN,LOW);
    delayMicroseconds(10);
 
    digitalWrite(TRIGGER_PIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN,LOW);
   
    /* ricevi l’eco */
    float tUS = pulseIn(ECHO_PIN, HIGH);
    float t = tUS / 10000.0 / 2;
    float d = t*vs;
    return d;
}
 
void loop() {
  switch(currentState) {
    case STANDBY:
      delay(100);
      if(digitalRead(BUT_PIN)) {
        Serial.print("Moving to MOVING_BUTTON");
        currentState = MOVING_BUTTON;
      }
      distance = getDistance();
      if(distance <= 180) {
        Serial.print("Moving to DETECTED");
        currentState = DETECTED;
      }
      break;
    case DETECTED:
      distance = getDistance();
      if(distance <= 180) {
        Serial.println("Changing to MOVING SONAR");
        currentState = MOVING_SONAR;
      }
      break;
    case MOVING_SONAR:
      distance = getDistance();
      if(distance > 180){
        Serial.println("Moving to STANDBY")
        currentState = STANDBY;
      } else {
        servoAngle = map(distance, 0, 180, 180, 0);
        servoMotor.write(servoAngle);
      }
      
      break;
    case MOVING_BUTTON:
      pot = analogRead(POT_PIN);
      servoAngle = map(pot, 0, 1023, 0, 180);
      servoMotor.write(servoAngle);
      delay(30);
      if(digitalRead(BUT_PIN)) {
        Serial.print("Moving to STANDBY");
        currentState = STANDBY;
      }
      break;
  }
}
 
 