#include "setup.h"
#include "gameLogic.h"

void setup() {
  Serial.begin(9600);
  pinSetup();
}

void loop() {
  switch (state) {
    case STANDBY:
      standBy();
      break;
      
    case FREE_ZONE:
      freeZone();
      break;

    case ATTACKED:
      attacked();
      break;

    case TARGET_DETECTED:
      targetDetected();
      break;
  }
}
