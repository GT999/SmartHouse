
float getLux() {
    // read the analog value
    int sensorValue = analogRead(LDR_SENSOR);
    float resistance_sensor;

    // and convert to resistance in Kohms
    resistance_sensor = (float)(1023 - sensorValue) * 10 / sensorValue;

    // convert the resitance to Lux 
    float lux;
    lux = 325 * pow(resistance_sensor, -1.4);

  return lux;
}
