#include "Readings.h"
#include "Arduino.h"
#include "readlux.h"
#include "DHT.h"
#include "Setup.h"

void Readings(){
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
  Serial.println("-----------------------------");
}