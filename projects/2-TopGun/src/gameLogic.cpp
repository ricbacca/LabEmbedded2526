#include "gameLogic.h"

GameState state = STANDBY;
int detected = LOW;
float prevDistance = 0;
float distance = 0;
int pos = 90;
int angoloCasuale = 0;

void standBy(){
    int detected = digitalRead(PIR);
    if (detected == HIGH){
        state = FREE_ZONE;
        detected = LOW;
    }
    delay(10);
}

void freeZone() {
    delay(100);
    distance = getDistance();

    if (distance != 0) {
        // Non ho ancora avuto rilevazioni
        if (prevDistance == 0) {
            Serial.print("Distanza dalla base: ");
            Serial.print(distance, 2);
            Serial.println();
            prevDistance = distance;
        } else if (distance < prevDistance) {
            float speed = (prevDistance-distance)/100;
            Serial.print("Distanza dalla base: ");
            Serial.print(distance, 2);
            Serial.println();
            Serial.print("Velocity: ");
            Serial.print(speed, 2);
            Serial.println();
            if (distance < 25) {
                state = ATTACKED;
                prevDistance = 0;
            }
        }
    }
}

void attacked() {
    digitalWrite(RED_LED, HIGH);
    turret->on();
    turret->setPosition(pos);
    delay(15);
    turret->off();

    state = TARGET_DETECTED;
}

void targetDetected() {
    distance = getDistance();

    if (distance > 25) {
        turret->on();
        turret->setPosition(0);
        delay(15);
        turret->off();

        digitalWrite(RED_LED, LOW);
        
        state = STANDBY;
        distance = 0;
        Serial.println("Zona libera");
    } else {
        digitalWrite(RED_LED, HIGH);
        angoloCasuale = (int)random(1, 180);

        turret->on();
        turret->setPosition(angoloCasuale);
        delay(15);
        turret->off();

        Serial.print("Target detected! Distance: ");
        Serial.print(distance, 2);
        Serial.println();
        delay(500);
    }
}