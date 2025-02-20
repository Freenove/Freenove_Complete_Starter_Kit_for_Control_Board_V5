/**********************************************************************
  Filename    : Sketch_26.1.1_Infrared_Motion_Sensor
  Description : Infrared Motion Sensor
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 12; // the number of the infrared motion sensor pin
int ledPin = 13;    // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
}

void loop() {
  // Turn on or off LED according to Infrared Motion Sensor
  digitalWrite(ledPin, digitalRead(sensorPin));
  delay(1000);              // wait for a second
}

