#include "Arduino.h"
#include "Timer.h"
 
#define PIR 11
#define BUTTON 4
#define LED 13
 
#define TIMER_PERIOD 5000
 
const int trigPin = 8;
const int echoPin = 7;
 
/* supponendo di eseguire il test
   in un ambiente a 20 °C
   https://it.wikipedia.org/wiki/Velocità_del_suono
   */
const double vs = 331.45 + 0.62*20;
 
Timer* timer;
 
enum States {
  STANDBY, ARMED, DETECTED, ALARMED
};
 
bool buttonPressed = false;
bool presenceDetected = false;
float distance;
States currentState;
 
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
 
  timer = new Timer();
  timer->setupPeriod(TIMER_PERIOD);
 
  currentState = STANDBY;
}
 
float getDistance() // ritorna la distanza in cm
{
    /* invio impulso */
    digitalWrite(trigPin,LOW);
    delayMicroseconds(10);
 
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
   
    /* ricevi l’eco */
    long tUS = pulseInLong(echoPin, HIGH);
    Serial.println(tUS);
 
    double t = tUS / 1000.0 / 10.0 / 2;
    double d = t*vs;
    return d;
}
 
 
void loop()
{
 
  switch(currentState){
    case STANDBY:
      Serial.println("Standby");
      buttonPressed = digitalRead(BUTTON);
      if(buttonPressed){
        currentState = ARMED;
      }
      break;
    case ARMED:
      Serial.println("Armed");
      presenceDetected = digitalRead(PIR);
      if(presenceDetected){
        currentState = DETECTED;
      }
      break;
    case DETECTED:
      Serial.println("Detected");
      distance = getDistance();
      if(distance < 100){
        currentState = ALARMED;
      }
      break;
    case ALARMED:
      Serial.println("Alarmed");
      digitalWrite(LED, HIGH);
      timer->waitForNextTick();

    currentState = STANDBY;
    timerFlag = false;
    digitalWrite(LED, LOW);
      break;
  }
}
 
Velocità del suono
La velocità del suono è la velocità con cui il suono si propaga in un certo mezzo. La velocità del suono varia a seconda del tipo di mezzo (ad esempio, il suono si propaga più velocemente nell'acqua che...
 