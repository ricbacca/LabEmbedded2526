#include "Arduino.h"
#include "Timer.h"
 
#define PIR 2
#define BUTTON 12
#define LEDPIN 4
#define ECHOPIN 7
#define TRIGPIN 8
 
#define TIMER_PERIOD 5000

const double vs = 331.45 + 0.62*20;
 
Timer* timer;
 
enum SurveillanceStates { STANDBY, ARMED, DETECTED, ALARM };
SurveillanceStates currentState;
 
void setup()
{
  Serial.begin(9600);

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);  
  pinMode(PIR, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTON, INPUT);
 
  timer = new Timer();
 
  currentState = STANDBY;
}
 
float getDistance()
{
    /* invio impulso */
    digitalWrite(TRIGPIN,LOW);
    delayMicroseconds(10);
 
    digitalWrite(TRIGPIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN,LOW);
   
    /* ricevi l’eco */
    long tUS = pulseInLong(ECHOPIN, HIGH);
 
    double t = tUS / 1000.0 / 10.0 / 2;
    double d = t*vs;
    return d;
}
 
 digitalPinToInterrupt(2)
 
void loop()
{
  switch(currentState){
    case STANDBY:
      if(digitalRead(BUTTON) == HIGH){
        currentState = ARMED;
        Serial.println("Switching to ARMED");
      }
      break;
    case ARMED:
      if(digitalRead(PIR) == HIGH){
        currentState = DETECTED;
        Serial.println("Switching to DETECTED");
      }
      break;
    case DETECTED:
      if(getDistance() < 100){
        currentState = ALARM;
        Serial.println("Switching to ALARM");
      }
      break;
    case ALARM:
      digitalWrite(LEDPIN, HIGH);

      // ATTENZIONE
      // void Timer::waitForNextTick()
      //    while (!timerFlag){}
      //    timerFlag = false;
      timer->setupPeriod(TIMER_PERIOD);
      timerFlag = false;
      timer->waitForNextTick();

      // finchè son passati 5 secondi
      currentState = STANDBY;
      digitalWrite(LEDPIN, LOW);
      Serial.println("Switching to STANDBY");
      break;
  }
}