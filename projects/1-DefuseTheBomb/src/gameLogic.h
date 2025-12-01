#ifndef __GAME_LOGIC__
#define __GAME_LOGIC__

#include "Arduino.h"
#include "setup.h"
#include "gameUtils.h"

extern int score;
extern int patternLength;    
extern int pattern[32];

void showPattern();

void waitStart();

void userInput();

#endif