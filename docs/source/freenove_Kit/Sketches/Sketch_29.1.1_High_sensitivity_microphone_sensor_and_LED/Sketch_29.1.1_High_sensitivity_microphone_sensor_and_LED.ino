/**********************************************************************
  Filename    : Sketch_28.1.1_High_sensitivity_microphone_sensor_and_LED
  Description : High sensitivity microphone sensor and LED
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 3;  // the number of the infrared motion sensor pin
int ledPin = 2;     // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
}

void loop() {
  // // Turn on or off LED according to Infrared Motion Sensor
  // digitalWrite(ledPin, digitalRead(sensorPin));
  // delay(1000);              // wait for a second
  if (digitalRead(sensorPin) == HIGH) {  // The sensor is blocked
    digitalWrite(ledPin, HIGH);          //Make GPIO output HIGH level
    delay(5000);
    digitalWrite(ledPin, LOW);
  } else {                           // The sensor is not blocked
    digitalWrite(ledPin, LOW);       //Make GPIO output LOW level
  }
}
