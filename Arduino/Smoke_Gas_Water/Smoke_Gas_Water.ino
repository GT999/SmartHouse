const int GasAndSmoke = A1;
const int Water = A2;
const int Button = 2;
const int Buzzer = 3;
const int Red = 12;
const int Green = 13;
const int Blue = 11;
const int Freq1 = 450;
const int Freq2 = 100;
const int SmokeAlarmValue = 300;
const int SmokeAlarmOffValue = 200;
const int WaterAlarmValue = 500;
const int WaterAlarmOffValue = 300;
int FirstDelay = 350;
int SecondDelay = 100;
int WaitingPeriod = 10000;
bool Toggle1 = true;
bool Toggle2 = true;
bool Lock = true;
int Mode = 0;
const int Interval = 150;
unsigned long First_time;
unsigned long Second_time;


void setup() {

  Serial.begin(9600);
  pinMode(GasAndSmoke, INPUT);
  pinMode(Water, INPUT);
  pinMode(Button, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  digitalWrite(Green, HIGH);
  First_time = millis();
}


void loop() {
  unsigned long current_time = millis();
  int SmokeValue = analogRead(A1);
  int WaterValue = analogRead(A2);

  Serial.print("GasAndSmoke = ");
  Serial.print(SmokeValue);
  Serial.print("   ");
  Serial.print("Water = ");
  Serial.println(WaterValue);


  if (SmokeValue < SmokeAlarmOffValue && Toggle1 == false)
  { Toggle1 = true;
    Lock = true;
    if (WaterValue < WaterAlarmOffValue)
    {
      Mode = 0;
    }
    else
    {
      Mode = 2;
    }
  }

  if (WaterValue < WaterAlarmOffValue && Toggle2 == false)
  { Toggle2 = true;
    Lock = true;
    if (SmokeValue < SmokeAlarmOffValue)
    {
      Mode = 0;
    }
    else
    {
      Mode = 1;
    }
  }
  if (SmokeValue > SmokeAlarmValue && Toggle1 == true)
  { Toggle1 = false;
    Mode = 1;
  }

  if (WaterValue > WaterAlarmValue && Toggle2 == true)
  { Toggle2 = false;
    Mode = 2;
  }


  if (Mode == 0) // The Normal situation
  { digitalWrite(Red, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Green, HIGH);
    noTone(Buzzer);
  }

  if (Mode == 1) // The Gas And Smoke Alarm situation
  {
    if (Lock == true)
    { Second_time = current_time;
      Lock = false;
    }
    if (current_time - Second_time > FirstDelay)
    { digitalWrite(Blue, LOW);
      digitalWrite(Red, HIGH);
      digitalWrite(Green, LOW);
      tone(Buzzer, Freq1);
    }
    if (current_time - Second_time > (FirstDelay * 2))

    { digitalWrite(Red, LOW);
      noTone(Buzzer);
      Second_time = current_time;
    }
  }

  if (Mode == 2) // The Water Alarm situation
  {
    if (Lock == true)
    { Second_time = current_time;
      Lock = false;
    }
    if (current_time - Second_time > SecondDelay)
    { digitalWrite(Red, LOW);
      digitalWrite(Blue, HIGH);
      digitalWrite(Green, LOW);
      tone(Buzzer, Freq2);
    }
    if (current_time - Second_time > (SecondDelay * 2))

    { digitalWrite(Blue, LOW);
      noTone(Buzzer);
      Second_time = current_time;
    }


  }

  if (Mode == 3) // The Waiting situation
  { digitalWrite(Red, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Blue, LOW);
    noTone(Buzzer);
    delay (WaitingPeriod);
    Toggle1 = true;
    Toggle2 = true;
    Mode = 0;

  }

  int btn_state = digitalRead(2);
  if (current_time - First_time > Interval)
  {
    if (btn_state == LOW && Mode != 0)
    {
      delay (200);
      Mode = 3;
    }
    First_time = current_time;
  }
}
