const int LED_PIN = 0;   // GPIO0

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(2000);

  digitalWrite(LED_PIN, LOW);
  delay(2000);
}