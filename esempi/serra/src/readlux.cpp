#include "readlux.h"
#include "Arduino.h"

#define PHOTO A0

extern int readLux(){
// These constants should match the photoresistor's "gamma" and "rl10" attributes
const float GAMMA = 0.7;
const float RL10 = 50;

// Convert the analog value into lux value:
int analogValue = analogRead(PHOTO);
float voltage = analogValue / 1024. * 5;
float resistance = 2000 * voltage / (1 - voltage / 5);
float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
return lux;
}