/**********************************************************************
  Filename    : Sketch_6.2.1_Receive_Data_through_Serial_Port
  Description : Receive Data through Serial Port
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

char inChar;      // define a variable to store characters received from serial port

void setup() {
  Serial.begin(9600);                 // initialize serial port, set baud rate to 9600
  Serial.println("UNO is ready!");    // print the string "UNO is ready!"
}

void loop() {
  if (Serial.available()) {         // judge whether data has been received
    inChar = Serial.read();         // read one character
    Serial.print("UNO received:");  // print the string "UNO received:"
    Serial.println(inChar);         // print the received character
  }
}

