#include "Arduino.h"
#include <avr/sleep.h>

#define BUTTON 3

bool wakeUp = false;
 
void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), wakeUpButton, HIGH);
}

void wakeUpButton() {
  wakeUp = true;
}

void enterSleep() { 
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  while (!wakeUp) {
    sleep_mode();
    sleep_cpu();
  }
  
  // IL PROGRAMMA RIPRENDE DA QUI DOPO CHE ARRIVA L'INTERRUPT
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(BUTTON));
}
  
void loop()
{  
  Serial.println("Entering sleep mode");
  wakeUp = false;

  enterSleep();

  if(wakeUp){
    Serial.println("SVEGLIATO DAL PULSANTE");
  }
}