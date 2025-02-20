/**********************************************************************
  Filename    : Sketch_29.2.1_Touch_Sensor_and_RGB_LED
  Description : Touch Sensor and RGB LED
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int SensorPin = 9;    // the number of the push button pin
int ledPinRed = 6;    // the number of the LED pin
int ledPinGreen = 5;  // the number of the LED pin
int ledPinBlue = 3;   // the number of the LED pin

int sensorstate = 0;

void setup() {
  pinMode(SensorPin, INPUT);        // set push button pin into input mode
  pinMode(ledPinRed, OUTPUT);       // set LED pin into output mode
  pinMode(ledPinGreen, OUTPUT);     // set LED pin into output mode
  pinMode(ledPinBlue, OUTPUT);      // set LED pin into output mode
  digitalWrite(ledPinRed, HIGH);    //Make GPIO output HIGH level
  digitalWrite(ledPinGreen, HIGH);  //Make GPIO output HIGH level
  digitalWrite(ledPinBlue, HIGH);   //Make GPIO output HIGH level
}

void loop() {
  if (digitalRead(SensorPin) == LOW) {    // if the button is pressed
    delay(10);                            // delay for a certain time to skip the bounce
    if (digitalRead(SensorPin) == LOW) {  // confirm again if the button is pressed
      settingPattern();                   // reverse LED
      while (digitalRead(SensorPin) == LOW)
        ;         // wait for releasing
      delay(10);  // delay for a certain time to skip bounce when the button is released
    }
  }
  reverseLED();
}

void settingPattern() {
  sensorstate++;
  if (sensorstate > 3) {
    sensorstate = 0;
  }
}

void reverseLED() {
  switch (sensorstate) {
    case 1:
      digitalWrite(ledPinRed, LOW);     //Make GPIO output HIGH level
      digitalWrite(ledPinGreen, HIGH);  //Make GPIO output HIGH level
      digitalWrite(ledPinBlue, HIGH);   //Make GPIO output HIGH level
      break;
    case 2:
      digitalWrite(ledPinRed, HIGH);   //Make GPIO output HIGH level
      digitalWrite(ledPinGreen, LOW);  //Make GPIO output HIGH level
      digitalWrite(ledPinBlue, HIGH);  //Make GPIO output HIGH level
      break;
    case 3:
      digitalWrite(ledPinRed, HIGH);   //Make GPIO output HIGH level
      digitalWrite(ledPinGreen, LOW);  //Make GPIO output HIGH level
      digitalWrite(ledPinBlue, HIGH);  //Make GPIO output HIGH level
      break;
    case 0:
      digitalWrite(ledPinRed, HIGH);    //Make GPIO output HIGH level
      digitalWrite(ledPinGreen, HIGH);  //Make GPIO output HIGH level
      digitalWrite(ledPinBlue, HIGH);   //Make GPIO output HIGH level
      break;
  }
}
