void setup()
{
  Serial.begin(115200);
  Serial.println("ciao");
}

// Serial Monitor VS Code extension

void loop()
{
  while (!Serial.available()); // Wait for input
  String name = Serial.readStringUntil('\n');
  Serial.println(name);
}