#include "servo_motor_impl.h"

int pos;   
int delta;
ServoMotor* pMotor;

void setup() {
  Serial.begin(9600);
  pMotor = new ServoMotorImpl(9);
  pos = 90;
  delta = 1;
}

void loop() {
  pMotor->on();

    pMotor->setPosition(pos);         
    delay(15);            

  pMotor->off();

  delay(1000);
}
