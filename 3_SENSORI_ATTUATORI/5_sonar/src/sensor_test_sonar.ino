const int trigPin = 8;
const int echoPin = 7;

/* supponendo di eseguire il test 
   in un ambiente a 20 °C 
   https://it.wikipedia.org/wiki/Velocità_del_suono
   */
const float vs = 331.45 + 0.62*20;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

float getDistance()
{
    /* invio impulso di setup*/
    digitalWrite(trigPin,LOW);
    delayMicroseconds(10);

    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    
    /* ricevi l’eco */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 10000.0 / 2;
    float d = t*vs;
    return d;
}

void loop()
{
  float d = getDistance();
  Serial.println(d);
  delay(200); 
}
