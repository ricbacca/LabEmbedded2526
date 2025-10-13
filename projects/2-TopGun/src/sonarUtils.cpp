#include "sonarUtils.h"

const float vs = 331.45 + 0.62*20;

float getDistance()
{
    /* invio impulso di setup*/
    digitalWrite(TRIG_PIN,LOW);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN,LOW);
    
    /* ricevi l’eco */
    float tUS = pulseIn(ECHO_PIN, HIGH);
    float t = tUS / 10000.0 / 2;
    float d = t*vs;
    return d;
}