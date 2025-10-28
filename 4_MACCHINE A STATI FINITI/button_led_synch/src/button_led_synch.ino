#include "Led.h"
#include "ButtonImpl.h"

#define LED_PIN 13
#define BUTTON_PIN 2 

enum { ON, OFF} state;

Led* led;
ButtonImpl* button;

void setup(){
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);        
  Serial.begin(9600);
  state = OFF;
}

void loop(){
    switch (state){
      case OFF:
        if (button->isPressed(BUTTON_PIN)){
          led->switchOn(LED_PIN);
          Serial.println("ON");
          state = ON;
        }
        break;
      case ON:
        if (!button->isPressed(BUTTON_PIN)){
          led->switchOff(LED_PIN);
          Serial.println("OFF");
          state = OFF;
        }
        break;
  }
};
