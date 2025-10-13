#include "Setup.h"

void pinSetup(){
    pinMode(RED_LED, OUTPUT);

    for (int i = 0; i < 4; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(buttons[i], INPUT_PULLUP);
    }

    pinMode(POT, INPUT);
}