/* #define BUTTON_PIN 7 
#define LED_PIN 13  

//bool buttonState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT);     
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {     
    digitalWrite(LED_PIN, HIGH);  
    //Serial.println("Pressed");
  } else {
    digitalWrite(LED_PIN, LOW); 
  }
}
 */

#define BUTTON_PIN 7 
#define LED_PIN 13  


int oldValue = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT);     
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != oldValue) {
    if (buttonState == HIGH) {     
      digitalWrite(LED_PIN, HIGH);  
    } else {
      digitalWrite(LED_PIN, LOW); 
    }
    oldValue = buttonState;
  }
  
  delay(15);
}
