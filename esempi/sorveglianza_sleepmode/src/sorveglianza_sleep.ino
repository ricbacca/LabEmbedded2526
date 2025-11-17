#include "Arduino.h"
#include "Setup.h"
#include "surveillanceLogic.h"
 
void setup()
{
  pinSetup();
}
 
void loop()
{
  switch(currentState){
    case STANDBY:
      standby();
      break;
    case ARMED:
      armed();
      break;
    case DETECTED:
      detected();
      break;
    case ALARM:
      alarm();
      break;
  }
}