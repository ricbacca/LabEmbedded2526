#include "gameUtils.h"

void generatePattern(int length) {
    for (int i = 0; i < length; i++) {
        pattern[i] = random(0, 4);
    }
}

void resetGame() {
    state = WAIT_START;
    digitalWrite(RED_LED, LOW);
    patternLength = 0;
    score = 0;
    Serial.println("Defuse the Bomb - Press T1 to Start");
}

void boom() {
    Serial.print("BOOM! You failed! Score: ");
    Serial.println(score);

    digitalWrite(RED_LED, HIGH);
    delay(3000);

    resetGame();
}