#define POT_PIN A0
#define LED_PIN 5
#define BUTTON_PIN 2

bool lastButtonState;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButtonState = false;
  Serial.begin(115200);
}

void loop() {
  int buttonPressed = digitalRead(BUTTON_PIN);
  // debouncing
  delay(5);

  if(lastButtonState == false) {
    if (buttonPressed) {
      lastButtonState = true;
    }
  }

  Serial.println(lastButtonState);
  
  //int value = analogRead(POT_PIN);
  //int ledValue = map(value, 0, 1023, 0, 255);
  //analogWrite(LED_PIN, ledValue);
}
