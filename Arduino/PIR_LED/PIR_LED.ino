const int LED = 13;
const int PIR = 3;

bool isOn = LED == HIGH;

uint32_t timeCheck = 0;
long timeDelay = 50000;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
  digitalWrite(LED, LOW);

  attachInterrupt(digitalPinToInterrupt(PIR), ISR_hallLight, HIGH);
}

void loop() {
  if (IsOn)
  {
    if (millis() - timeCheck > timeDelay) {
      digitalWrite(LED, LOW);
      timeCheck = millis();
  }
}

void ISR_hallLight() {
  digitalWrite(LED, HIGH);
}
