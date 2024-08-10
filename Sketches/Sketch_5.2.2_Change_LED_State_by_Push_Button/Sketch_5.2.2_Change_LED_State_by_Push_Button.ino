/**********************************************************************
  Filename    : Sketch_5.2.2_Change_LED_State_by_Push_Button
  Description : Change LED State by Push Button
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int buttonPin = 12; // the number of the push button pin
int ledPin = 9;     // the number of the LED pin
boolean isLighting = false; // define a variable to save the state of LED

void setup() {
  pinMode(buttonPin, INPUT);  // set push button pin into input mode
  pinMode(ledPin, OUTPUT);    // set LED pin into output mode
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {        // if the button is pressed
    reverseLED();                             // reverse LED
    while (digitalRead(buttonPin) == LOW);    // wait for releasing
  }
}

void reverseLED() {
  if (isLighting) {             // if LED is lighting,
    digitalWrite(ledPin, LOW);  // switch off LED
    isLighting = false;         // store the state of LED
  }
  else {                        // if LED is off,
    digitalWrite(ledPin, HIGH); // switch LED
    isLighting = true;          // store the state of LED
  }
}

