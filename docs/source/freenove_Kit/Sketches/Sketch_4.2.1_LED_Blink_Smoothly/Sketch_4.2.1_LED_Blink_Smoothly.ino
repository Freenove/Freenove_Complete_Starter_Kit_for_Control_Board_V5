/**********************************************************************
  Filename    : Sketch_4.2.1_LED_Blink_Smoothly
  Description : LED Blink Smoothly
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// set pin numbers:
int ledPin = 5;             // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // call breath() cyclically
  breath(ledPin, 6);
  delay(500);
}

void breath(int ledPin, int delayMs) {
  for (int i = 0; i <= 255; i++) {  // "i" change from 0 to 255
    analogWrite(ledPin, i);         // corespongding duty cycle change from 0%-100%
    delay(delayMs);                 // adjust the rate of change of brightness
  }
  for (int i = 255; i >= 0; i--) {  // "i" change from 255 to 0
    analogWrite(ledPin, i);         // corespongding duty cycle change from 0%-100%
    delay(delayMs);                 // adjust the rate of change in brightness
  }
}

