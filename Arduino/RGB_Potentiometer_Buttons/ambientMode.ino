
void ambientMode() {
  if (millis() - timeCheck > 1000) {
    //reads the temperature, hummidity, lum
    temperature = DHT11.getTemperature();
    humidity = DHT11.getHumidity();
    illumination = getLux();
    //reset millis()
    timeCheck = millis();
  }
  //execute the actual rgb led code
  Serial.println(illumination);
}
