/*
 * Button functioning as a switch
 * pressed => switch the light
 */
#define BUTTON_PIN 7
#define LED_PIN 13   

boolean ledState;
boolean lastButtonState;


void setup() {
  pinMode(LED_PIN, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT);     
  ledState = false;
  lastButtonState = false;
  digitalWrite(LED_PIN,LOW);
  Serial.begin(9600);
}

void loop() {
  int buttonPressed = digitalRead(BUTTON_PIN);
  // debouncing
  delay(5);
  
  if (lastButtonState == false) {
    if (buttonPressed == true){
      lastButtonState = true;
      if (ledState){
        digitalWrite(LED_PIN, LOW);  
        ledState = false;
        Serial.println("Switched off.");
      } else {
        digitalWrite(LED_PIN, HIGH);  
        ledState = true;
        Serial.println("Switched on.");
      }
    }
  } else {
    // lastButtonState = true
    // se il pulsante non è premuto "libero" il main loop per una
    // successiva pressione del pulsante che cambi lo stato
    if (buttonPressed == false){
      lastButtonState = false;         
    }
  }
}
