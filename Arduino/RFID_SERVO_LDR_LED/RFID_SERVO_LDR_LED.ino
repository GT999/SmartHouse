#include <Servo.h>
Servo servo;
const int servoPin = 5;
int servoPos = 90;
int door = 0;
//----------------------
const int LDR = A0;
const int RoomLight = 3;
int value;
int r;
int light = 0;
//----------------------
#include <MFRC522.h>
#include <SPI.h>
const int SS_PIN = 10;
const int RST_PIN = 9;
MFRC522 rfid(SS_PIN, RST_PIN);
byte uid[4];
bool toggle = true;
const int Green = 7;
const int Red = 6;
int counter = 0;
//----------------------
const int Button = 2;
//#################################################
unsigned long getRFIDTag(byte scanData[]) {
  unsigned long tag = 0;
  for (int i = 0; i < 4; i++) {
    tag <<= 8;
    tag += scanData[i];
  }
  return tag;
}
//#################################################
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(servoPos);
  pinMode(LDR, INPUT);
  pinMode(RoomLight, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  SPI.begin();      // Init SPI bus
  rfid.PCD_Init();  // Init MFRC522
  delay(4);         // For some boards
  pinMode(Button, INPUT);

}
//#################################################
void loop() {
  int Button_state = digitalRead(Button);
  if (Button_state == LOW) //To switch the light room On or Off manually using the button
  { delay (200);
    switch (counter)
    { case 0:
        counter = 1; light = 1; break;
      case 1:
        counter = 0; light = 0; break;
    }
  }
//-------------------------------------------------
  if (door == 1) //In case the door was opened by the card, the light room will turn On
  { digitalWrite (Green, HIGH);
    digitalWrite (Red, LOW);
    if (light == 1)
    { value = analogRead(LDR); //To adjust the room light according to the LDR
      if (value > 550) r = 0;
      else if (value > 400 && value < 500) r = 60;
      else if (value > 250 && value < 350) r = 120;
      else if (value > 100 && value < 200) r = 180;
      else if (value > 0 && value < 75) r = 255;
      analogWrite(RoomLight, r);
    }
    if (light == 0)
    {
      analogWrite(RoomLight, 0);
    }
  }


  if (door == 0) //In case the door was closed, the light room will turn Off
  {
    digitalWrite (Green, LOW);
    digitalWrite (Red, HIGH);
    if (light == 1)
    { value = analogRead(LDR); //To adjust the room light according to the LDR
      if (value > 550) r = 0;
      else if (value > 400 && value < 500) r = 60;
      else if (value > 250 && value < 350) r = 120;
      else if (value > 100 && value < 200) r = 180;
      else if (value > 0 && value < 75) r = 255;
      analogWrite(RoomLight, r);
    }
    if (light == 0)
    {
      analogWrite(RoomLight, 0);
    }
  }
 //-------------------------------------------------
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }
  rfid.PICC_HaltA();      // Stop reading
  rfid.PCD_StopCrypto1(); // Exit comm.
  unsigned long tag = getRFIDTag(rfid.uid.uidByte);
  Serial.println(tag);
  if (tag == 2722598940 && toggle == true) //Set here the special number of the card
  { delay (1000);
    toggle = false;
    door = 1; 
    counter = 1;
    light = 1; //To turn the room light On
    servoPos = 0; 
    servo.write(servoPos); //To Open the door by the servo  
    }
  else
  { delay (1000);
    toggle = true;
    door = 0; 
    counter = 0;
    light = 0; //To turn the room light Off
    servoPos = 90; 
    servo.write(servoPos); //To close the door by the servo
  }
}
