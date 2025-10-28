#define BUTTON_PIN 7 
#define LED_PIN 13  

bool ledState = false;
bool lastButtonState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT);     
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  delay(10);

  if (buttonState == HIGH) {     
    digitalWrite(LED_PIN, HIGH);  
    ledState = true;
  } else {
    digitalWrite(LED_PIN, LOW); 
    ledState = false;
  }
}

/*
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
}*/
