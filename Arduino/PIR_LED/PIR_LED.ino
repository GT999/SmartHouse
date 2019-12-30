const int LED = 13;
const int PIR = 3;
int value;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
 
}

void loop() {
  value = digitalRead(PIR);

  if (value == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }


}
