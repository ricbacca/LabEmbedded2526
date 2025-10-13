#ifndef __GAME_LOGIC__
#define __GAME_LOGIC__

#include "Arduino.h"
#include "setup.h"
#include "sonarUtils.h"

enum GameState { STANDBY, FREE_ZONE, ATTACKED, TARGET_DETECTED };
extern GameState state;

void standBy();

void freeZone();

void attacked();

void targetDetected();

#endif