#include "Setup.h"
#include "Arduino.h"
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT22
#define PHOTO A0
#define LED 11
#define SERVO 10
#define BTN 7

DHT dht(DHTPIN, DHTTYPE);

void Setup(){
  pinMode(PHOTO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(SERVO, OUTPUT);
  pinMode(BTN, INPUT);

  Serial.begin(115200);

  Serial.println("Commencing reading...");
  dht.begin();
}