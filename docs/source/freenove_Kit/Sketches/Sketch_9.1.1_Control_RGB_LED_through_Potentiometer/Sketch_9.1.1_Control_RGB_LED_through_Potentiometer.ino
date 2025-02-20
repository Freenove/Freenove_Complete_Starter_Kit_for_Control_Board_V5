/**********************************************************************
  Filename    : Sketch_8.1.1_Control_RGB_LED_through_Potentiometer
  Description : Control RGB LED through Potentiometer
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// set pin numbers:
int ledPinR = 11;   // the number of the LED R pin
int ledPinG = 10;   // the number of the LED G pin
int ledPinB = 9;    // the number of the LED B pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
  int adcValue;     // Define a variable to save the ADC value
  // Convert analog of A3 port into digital, and work as PWM duty cycle of ledPinR port
  adcValue = analogRead(A3);
  analogWrite(ledPinR, map(adcValue, 0, 1023, 0, 255));
  // Convert analog of A4 port into digital, and work as PWM duty cycle of ledPinG port
  adcValue = analogRead(A4);
  analogWrite(ledPinG, map(adcValue, 0, 1023, 0, 255));
  // Convert analog of A5 port into digital, and work as PWM duty cycle of ledPinB port
  adcValue = analogRead(A5);
  analogWrite(ledPinB, map(adcValue, 0, 1023, 0, 255));
}

