#include "Sonar.h"
#include "Arduino.h"

float getDistance(int trigPin, int echoPin)
{
    /* invio impulso */
    digitalWrite(trigPin,LOW);
    delayMicroseconds(10);
 
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
   
    /* ricevi l’eco */
    long tUS = pulseInLong(echoPin, HIGH);
 
    double t = tUS / 1000.0 / 10.0 / 2;
    double d = t*vs;
    return d;
}