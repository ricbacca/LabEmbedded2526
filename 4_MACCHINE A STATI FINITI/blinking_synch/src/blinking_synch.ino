#include "Led.h"

#define LED_PIN 13

enum { ON, OFF} state;

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  state = OFF;
}

void loop(){
  switch (state){
    case OFF:
      switchOn(LED_PIN);
      Serial.println("ON");
      state = ON;
      break;
    case ON:
      switchOff(LED_PIN);
      Serial.println("OFF");
      state = OFF;
      break;
  }
  delay(500);
};
