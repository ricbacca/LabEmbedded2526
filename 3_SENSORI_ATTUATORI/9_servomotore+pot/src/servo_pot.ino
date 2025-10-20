#include <Servo.h>

#define POT_PIN 0
#define SERVO_PIN 9

Servo servoMotor;
int pot;
int servoAngle;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);

  pot = 0;
  servoAngle = 0;
}

void loop() {
  pot = analogRead(POT_PIN);
  servoAngle = map(pot, 0, 1024, 0, 180);
  servoMotor.write(servoAngle);

  delay(30);
}
