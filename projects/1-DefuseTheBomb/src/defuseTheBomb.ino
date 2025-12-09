#include "setup.h"
#include "gameLogic.h"

void setup() {
  Serial.begin(9600);
  pinSetup();
  resetGame();
}

void loop() {
  switch (state) {
    case WAIT_START:
      waitStart();
      break;

    case SHOW_PATTERN:
      showPattern();
      break;

    case USER_INPUT:
      userInput();
      break;
  }
}
