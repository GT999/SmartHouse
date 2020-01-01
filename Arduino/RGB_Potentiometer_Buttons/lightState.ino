
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
