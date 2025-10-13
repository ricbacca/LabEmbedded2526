
#include "gameLogic.h"

GameState state = WAIT_START;
int score = 0;
int patternLength = 0;      
int userIndex = 0;

unsigned long TMAX = 10000;  // Tempo massimo iniziale
unsigned long startTime = 0;

int pattern[32];

void waitStart() {
    // LED rosso acceso
    digitalWrite(RED_LED, HIGH);

    // Lettura livello difficoltà
    int level = map(analogRead(POT), 0, 1023, 1, 8);
    Serial.println("Livello scelto: " + level);

    // Pressione pulsante blu
    if (digitalRead(T1) == LOW) {
        Serial.println("Bomb Activated! Follow the defuse code!");

        digitalWrite(RED_LED, LOW);

        // mappare liello di difficoltà scelto sulla lunghezza del pattern
        patternLength = map(level, 1, 8, 2, 8);
        generatePattern(patternLength);
        TMAX = 10000 - (level * 500);  // più difficile, meno tempo

        delay(500);

        state = SHOW_PATTERN;
    }
}

void showPattern() {
    Serial.print("Pattern: ");

    for (int i = 0; i < patternLength; i++) {
        int led = leds[pattern[i]];
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(250);
        Serial.print(pattern[i]);
        Serial.print(" ");
    }

    Serial.println();

    userIndex = 0;
    startTime = millis();
    state = USER_INPUT;
}

void userInput() {
    // 4 buttons
    for (int i = 0; i < 4; i++) {
        // INPUT_PULLUP = LOW se premuto
        if (digitalRead(buttons[i]) == LOW) {
          delay(200); // debounce
            
            // il pulsante premuto è quello corretto nella sequenza
            if (pattern[userIndex] == i) {
                userIndex++;

                //Led relativo al pulsante premuto si accende e si spegne
                digitalWrite(leds[i], HIGH);
                delay(200);
                digitalWrite(leds[i], LOW);

                // finiamo i fili da tagliare, ed è giusto
                if (userIndex >= patternLength) {
                    Serial.println("Correct! Moving to next code");
                    score++;
                    patternLength++;
                    if (patternLength > 32)
                        patternLength = 32;

                    TMAX = max(1000UL, TMAX - 300);
                    delay(1000);

                    generatePattern(patternLength);

                    state = SHOW_PATTERN;
                } 
            } else {
                boom();
            } 
        }
    }

    if (millis() - startTime > TMAX) {
        boom();
    }
}