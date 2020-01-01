//#define BUTTON_SWITCH 2
//#define RGB_ENCODER 3

#define RGB_RED_LED 11
#define RGB_GREEN_LED 10
#define RGB_BLUE_LED 9

#define LDR_SENSOR A0


const int disco = 1000;

uint32_t time_check = 0;
bool OnOff = false;


enum LightMode {
  SINGLE_COLOR,
  AMBIENT,
  DISCO
};

enum LightMode lightMode = SINGLE_COLOR;


void setup() {
  pinMode(BUTTON_SWITCH, INPUT_PULLUP);
  pinMode(RGB_RED_LED, OUTPUT);
  pinMode(RGB_GREEN_LED, OUTPUT);
  pinMode(RGB_BLUE_LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_SWITCH), buttonPressed, FALLING);
}
void buttonPressed(){
  OnOff = !OnOff;
}

void SelectColor (int Red, int Green, int Blue) {
  analogWrite(RGB_RED_LED, Red);
  analogWrite(RGB_GREEN_LED, Green);
  analogWrite(RGB_BLUE_LED, Blue);
}

void loop() {
  lightState(OnOff);
}


/*
void lightState(bool isOn) {
  if (isOn) {
    lightModes();
  } else {
    //light off
    analogWrite(RGB_RED_LED, LOW);
    analogWrite(RGB_GREEN_LED, LOW);
    analogWrite(RGB_BLUE_LED, LOW);
  }
}

void lightModes() {
  switch (lightMode) {

    //can be used to chancge to any color
    case SINGLE_COLOR:
      singleColorMode();
      break;

    //adaptive lights
    case AMBIENT:
      ambientMode();
      break;

    //Colors switching disco style
    case DISCO:
      discoMode();
      break;

  }
}

void singleColorMode() {
  SelectColor (255, 255, 255);
}

void ambientMode() {
  //read the ldr and other sensors



  //execute the actual rgb led code
}

void discoMode() {
  if (millis() - time_check > disco)
  {
    SelectColor (255, 0, 0); //Red }
    if (millis() - time_check > (disco * 2))
    {
      SelectColor (0, 0, 255); //Blue
    }
    if (millis() - time_check > (disco * 3))
    {
      SelectColor (0, 255, 0); //Green
    }
    if (millis() - time_check > (disco * 4))
    {
      SelectColor (255, 0, 255); //Purple
    }
    if (millis() - time_check > (disco * 5))
    {
      SelectColor (255, 255, 255); //White Blue
      time_check = millis();
    }
  }
}
*/
