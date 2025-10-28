#include "Led.h"
#include "Arduino.h"

void switchOn(int pin){
  digitalWrite(pin,HIGH);
}

void switchOff(int pin){
  digitalWrite(pin,LOW);
};
