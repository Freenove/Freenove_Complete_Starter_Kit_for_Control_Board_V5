/**********************************************************************
  Filename    : Sketch_8.1.1_ADC
  Description : ADC experiment 
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int adcValue;   // Define a variable to save ADC value
float voltage;  // Define a variable to save the calculated voltage value

void setup() {
  Serial.begin(9600);  // Initialize the serial port and set the baud rate to 9600
  // analogReadResolution(10);  //change to 10-bit resolution
  // analogReadResolution(12);  //change to 12-bit resolution
  // analogReadResolution(14);  //change to 14-bit resolution
}

void loop() {
  int reading = analogRead(A0);         // returns a value between 0-1023
  voltage = reading * (5.0 / 1023.0);  // Calculate voltage according to digital
  // int reading = analogRead(A0);         // returns a value between 0-4095
  // voltage = reading * (5.0 / 4095.0);  // Calculate voltage according to digital
  // int reading = analogRead(A0);         // returns a value between 0-16383
  // voltage = reading * (5.0 / 16383.0);  // Calculate voltage according to digital
  Serial.print("convertValue:");
  Serial.println(reading);
  Serial.print("Voltage:");
  Serial.println(voltage);
  delay(500);
}
