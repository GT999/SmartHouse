
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
