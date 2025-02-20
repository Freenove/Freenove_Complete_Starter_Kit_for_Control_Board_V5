/**********************************************************************
  Filename    : Sketch_24.1.1_Infrared_Remote_Control
  Description : Infrared Remote Control
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// Include the necessary libraries
#include <IRremote.hpp>

// Define the pin numbers for the IR receiver
const int IR_RECEIVE_PIN = 12;

void setup() {
  Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
}

void loop() {
  // Check if there is any incoming IR signal
  if (IrReceiver.decode()) {
    // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the command in hexadecimal format
    // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Map and print the decoded IR signal to corresponding key value
    Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Map and print the decoded IR signal to corresponding key value

    IrReceiver.resume();  // Enable receiving of the next value
  }
}

// Function to map received IR signals to corresponding keys
String decodeKeyValue(long result) {
  // Each case corresponds to a specific IR command
  switch (result) {
    case 69:
      return "POWER";
    case 71:
      return "MENU";
    case 68:  // Receive the number 'TEST'
      return "TEST";
    case 64:  // Receive the number '+'
      return "+";
    case 67:
      return "Back";
    case 7:  // Receive the number '|<<'
      return "|<<";
    case 21:  // Receive the number '▶'
      return "▶";
    case 9:  // Receive the number '>>|'
      return ">>|";
    case 22:  // Receive the number '0'
      return "0";
    case 25:  // Receive the number '-'
      return "-";
    case 13:  // Receive the number 'C'
      return "C";
    case 12:  // Receive the number '1'
      return "1";
    case 24:  // Receive the number '2'
      return "2";
    case 94:  // Receive the number '3'
      return "3";
    case 8:  // Receive the number '4'
      return "4";
    case 28:  // Receive the number '5'
      return "5";
    case 90:  // Receive the number '6'
      return "6";
    case 66:  // Receive the number '7'
      return "7";
    case 82:  // Receive the number '8'
      return "8";
    case 74:  // Receive the number '9'
      return "9";
    default:
       break;
  }
}
