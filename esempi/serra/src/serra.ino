#include "Arduino.h"
#include "DHT.h"
 
#define DHTPIN 8
#define DHTTYPE DHT22
#define PHOTO A0
#define LED 11
#define SERVO 10
#define BTN 7
 
DHT dht(DHTPIN, DHTTYPE);
 
int readLux(){
  // These constants should match the photoresistor's "gamma" and "rl10" attributes
  const float GAMMA = 0.7;
  const float RL10 = 50;
  
  // Convert the analog value into lux value:
  int analogValue = analogRead(PHOTO);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  return lux;
}
 
void setup(){
  pinMode(DHTPIN, INPUT);
  pinMode(PHOTO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(SERVO, OUTPUT);
  pinMode(BTN, INPUT);
 
  Serial.begin(115200);
 
  Serial.println(F("DHTxx test!"));
 
  dht.begin();
}
 
void loop(){
  delay(2000);
  Serial.println("Luminosity: ");
  Serial.print(readLux());
  Serial.println(" lux");
  Serial.println("Humidity: ");
  Serial.print(dht.readHumidity());
  Serial.println("%");
  Serial.println("Temperature: ");
  Serial.print(dht.readTemperature());
  Serial.println("°C");
}
 