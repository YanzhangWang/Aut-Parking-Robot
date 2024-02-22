/* 
Link to original code:
https://www.hackster.io/ingo-lohs/light-sensing-with-the-flying-fish-series-from-mh-0e51ab#things

*/

// A0:

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1024.0);

  // the lower the voltage, the brighter it is
  if ((voltage >= 0) && (voltage <= 0.4)) {
    Serial.print ("it is dark - ");
  } else if ((voltage > 0.4) && (voltage <= 2)) {
    Serial.print ("it is bright - ");
  } else {
    Serial.print ("it is bright - ");
  }
  // print out the value you read:
  Serial.println(voltage);

// D0:

// when sensor pin D0 is connected, the sensor only knows the state light (0.14V) and dark (5.0V).
// The brightness at which the particular state is to be set can be set using the rotary potentiometer.

}
