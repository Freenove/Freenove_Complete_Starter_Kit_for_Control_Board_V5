/**********************************************************************
  Filename    : Sketch_2.1.3_Two_LEDs_Blink
  Description : Two LEDs Blink
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// set pin numbers:
int led1Pin = 5;            // the number of the LED1 pin
int led2Pin = 4;            // the number of the LED2 pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  setLed1(HIGH);     // set LED1 on, and LED2 off.
  setLed1(LOW);      // set LED1 off, and LED2 on.
}

void setLed1(int led1) {
  digitalWrite(led1Pin, led1);   // the state of LED1 is determined by variable led1.

  if (led1 == HIGH)              // the state of LED2 is determined by variable led1.
    digitalWrite(led2Pin, LOW);  // if LED1 is turned on, LED2 will be turned off.
  else
    digitalWrite(led2Pin, HIGH); // if LED1 is turned off, LED2 will be turned on.

  delay(1000);                   // wait for a second
}

