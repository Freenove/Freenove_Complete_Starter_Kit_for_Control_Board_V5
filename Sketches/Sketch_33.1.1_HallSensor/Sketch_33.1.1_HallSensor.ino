/**********************************************************************
  Filename    : Sketch_32.1.1_HallSensor
  Description : HallSensor and LED
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 3;  // the number of the infrared motion sensor pin
int ledPin = 5;     // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
}

void loop() {
  // // Turn on or off LED according to Infrared Motion Sensor
  // digitalWrite(ledPin, digitalRead(sensorPin));
  // delay(1000);              // wait for a second
  if (digitalRead(sensorPin) == LOW) {  // The sensor is blocked
    digitalWrite(ledPin, HIGH);          //Make GPIO output HIGH level
  } else {                           // The sensor is not blocked
    digitalWrite(ledPin, LOW);       //Make GPIO output LOW level
  }

}