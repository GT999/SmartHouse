const int BUTTON_ON = 2;
const int BUTTON_OFF = 4;
const int RED_POT = A1;
const int GREEN_POT = A2;
const int BLUE_POT = A3;
const int RED_LED = 9;
const int GREEN_LED = 10;
const int BLUE_LED = 11;
int READ1, READ2, READ3;
int Mode = 0;
int RandomLight;
const int INTERVAL = 150;
const int disco = 1000;
unsigned long First_time;
unsigned long Second_time;

//##################################################
void SelectColor (int Red, int Green, int Blue) { 
  analogWrite(RED_LED, Red);
  analogWrite(GREEN_LED, Green);
  analogWrite(BLUE_LED, Blue);
}
//##################################################
void setup() {
  pinMode(RED_POT, INPUT);
  pinMode(GREEN_POT, INPUT);
  pinMode(BLUE_POT, INPUT);
  pinMode (BUTTON_ON, INPUT);
  pinMode (BUTTON_OFF, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  First_time = millis();
}
//##################################################
void loop() {
  unsigned long current_time = millis();
  READ1 = analogRead(RED_POT);
  READ2 = analogRead(GREEN_POT);
  READ3 = analogRead(BLUE_POT);
  int KeyOn_State = digitalRead(BUTTON_ON);
  int KeyOff_State = digitalRead(BUTTON_OFF);

//--------------------------------------------------
  if (current_time - First_time > INTERVAL)
  {
    if (KeyOn_State == LOW)
    { delay (200);
      Mode++;
      if (Mode == 5)
      {
        Mode = 1;
      }
    }
//---------------------------
    if (KeyOff_State == LOW)
    { delay (200);
      Mode = 0;
    }
    First_time = current_time;
  }
//--------------------------------------------------
  if (Mode == 0) //Light Off
  {
    analogWrite(RED_LED, LOW);
    analogWrite(GREEN_LED, LOW);
    analogWrite(BLUE_LED, LOW);
  }
//--------------------------------------------------
  if (Mode == 1) //RGB adjustable
  { analogWrite(RED_LED, READ1 / 4);
    analogWrite(GREEN_LED, READ2 / 4);
    analogWrite(BLUE_LED, READ3 / 4);
  }
//--------------------------------------------------
  if (Mode == 2) //White light adjustable By using the red Potentiometer
  {
    analogWrite(RED_LED, READ1 / 4);
    analogWrite(GREEN_LED, READ1 / 4);
    analogWrite(BLUE_LED, READ1 / 4);
  }
//--------------------------------------------------
  if (Mode == 3) //Random Colors
  {
    if (current_time - Second_time > disco)
    {
      analogWrite(RED_LED, random(0, 255));
      analogWrite(GREEN_LED, random(0, 255));
      analogWrite(BLUE_LED, random(0, 255));
      Second_time = current_time;
    }
  }
//--------------------------------------------------
  if (Mode == 4) //Disco
  {
    if (current_time - Second_time > disco)
    {
      SelectColor (255, 0, 0); //Red }
      if (current_time - Second_time > (disco * 2))
      {
        SelectColor (0, 0, 255); //Blue
      }
      if (current_time - Second_time > (disco * 3))
      {
        SelectColor (0, 255, 0); //Green
      }
      if (current_time - Second_time > (disco * 4))
      {
        SelectColor (255, 0, 255); //Purple
      }
      if (current_time - Second_time > (disco * 5))
      {
        SelectColor (255, 255, 255); //White Blue
        Second_time = current_time;
      }
    }
  }
//--------------------------------------------------

}
