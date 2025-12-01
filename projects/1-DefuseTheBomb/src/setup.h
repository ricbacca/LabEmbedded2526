#ifndef __SETUP__
#define __SETUP__

#include "Arduino.h"
#include "gameLogic.h"
#include "gameUtils.h"

#define RED_LED 13               // LED rosso (stato bomba)
#define L1 2                // LED blu
#define L2 3                // LED verde
#define L3 4                // LED giallo
#define L4 5                // LED bianco

#define T1 6                // Pulsante blu
#define T2 7                // Pulsante verde
#define T3 8                // Pulsante giallo
#define T4 9                // Pulsante bianco

#define POT A0              // Potenziometro

const int leds[4] = {L1, L2, L3, L4};
const int buttons[4] = {T1, T2, T3, T4};

enum GameState { WAIT_START, SHOW_PATTERN, USER_INPUT };
extern GameState state;

void pinSetup();

#endif