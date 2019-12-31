#define BUTTON_SWITCH
#define RGB_RED_LED
#define RGB_GREEN_LED
#define RGB_BLUE_LED
#define RGB_POTPIN
#define LDR_SENSOR


const int INTERVAL = 150;
const int disco = 1000;
uint32_t time_check = 0;


enum LightMode {
  AMBIENT,
  SINGLE_COLOR,
  DISCO
} lightMode;

//##################################################
void setup() {
  pinMode (BUTTON_ON, INPUT);
  pinMode (BUTTON_OFF, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}
//##################################################
void loop() {

}






void lightState(bool isOn) {
  if (isOn) {
    lightMode(lightMode);
  } else {
    analogWrite(RED_LED, LOW);
    analogWrite(GREEN_LED, LOW);
    analogWrite(BLUE_LED, LOW);
  }
}

void lightMode(enum LightMode mode) {
  switch (mode) {
    //adaptive lights
    case AMBIENT:
      ambientMode();
      break;

    //can be used to chancge to any color
    case SINGLE_COLOR:

      break;
    //Colors switching disco style
    case DISCO:
      discoMode();
      break;
  }
}

void ambientMode() {
  //read the ldr and other sensors


  //execute the actual rgb led code

}


void singleColorMode() {

}

void discoMode() {
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

void SelectColor (int Red, int Green, int Blue)
{ analogWrite(RED_LED, Red);
  analogWrite(GREEN_LED, Green);
  analogWrite(BLUE_LED, Blue);
}
