/**********************************************************************
  Filename    : Sketch_29.1.1_Touch_Sensor_and_LED
  Description : Touch Sensor and LED
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int buttonPin = 5;           // the number of the push button pin
int ledPin = 6;              // the number of the LED pin
boolean isLighting = false;  // define a variable to save the state of LED
int sensorstate = 0;
void setup() {
  pinMode(buttonPin, INPUT);  // set push button pin into input mode
  pinMode(ledPin, OUTPUT);    // set LED pin into output mode
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {    // if the button is pressed
    delay(10);                            // delay for a certain time to skip the bounce
    if (digitalRead(buttonPin) == LOW) {  // confirm again if the button is pressed
      settingPattern();                   // reverse LED
      while (digitalRead(buttonPin) == LOW)
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
      analogWrite(ledPin, map(10, 0, 100, 0, 255));
      break;
    case 2:
      analogWrite(ledPin, map(50, 0, 100, 0, 255));
      break;
    case 3:
      analogWrite(ledPin, map(100, 0, 100, 0, 255));
      break;
    case 0:
      analogWrite(ledPin, map(0, 0, 100, 0, 255));
      break;
  }
}
