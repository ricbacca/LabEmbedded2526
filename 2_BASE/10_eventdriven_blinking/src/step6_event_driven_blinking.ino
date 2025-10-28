#include "TimerOne.h"

#define LED_PIN 3

boolean flagState = false;

void blinky(){
  Serial.println("BLINK");
  if (!flagState){
    digitalWrite(LED_PIN, HIGH);  
  } else {
    digitalWrite(LED_PIN, LOW);  
  }
  flagState = !flagState;
}


void setup()
{
  pinMode(LED_PIN,OUTPUT);
  // nanosecondi: 1 secondo = 1.000.000 uSec
  /* set period timer 1000000 usec = 1 sec */
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(blinky); 
  Serial.begin(9600);
}

void loop(){
  Serial.println(flagState);
}
