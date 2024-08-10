/**********************************************************************
  Filename    : Sketch_24.2.1_Control_LED_through_Infrared_Remote
  Description : Control LED through Infrared Remote
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include <IRremote.hpp>

// Define the pin numbers for the IR receiver
const int IR_RECEIVE_PIN = 12;

decode_results results; // Create a decoding results class object

int ledPin = 5;           // the number of the LED pin
int buzzerPin = 13;       // the number of the buzzer pin

void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
  pinMode(ledPin, OUTPUT);          // set LED pin into output mode
  pinMode(buzzerPin, OUTPUT);       // set buzzer pin into output mode
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command); // Print out the decoded results
    handleControl(IrReceiver.decodedIRData.command); // Handle the commands from remote control
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

void handleControl(unsigned long value) {
  // Make a sound when it rereives commands
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  // Handle the commands
  switch (value) {
    case 22:  // Receive the number '0'
      analogWrite(ledPin, 0);   // Turn off LED
      break;
    case 12:  // Receive the number '1'
      analogWrite(ledPin, 7);   // Dimmest brightness
      break;
    case 24:  // Receive the number '2'
      analogWrite(ledPin, 63);  // Medium brightness
      break;
    case 94:  // Receive the number '3'
      analogWrite(ledPin, 255); // Strongest brightnss
      break;
  }
}

