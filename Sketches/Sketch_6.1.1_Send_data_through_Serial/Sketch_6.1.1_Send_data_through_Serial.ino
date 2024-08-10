/**********************************************************************
  Filename    : Sketch_6.1.1_Send_data_through_Serial
  Description : Send data through Serial
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int counter = 0;  // define a variable as a data sending to serial port

void setup() {
  Serial.begin(9600);                 // initialize the serial port, set the baud rate to 9600
  Serial.println("UNO is ready!");    // print the string "UNO is ready!"
}

void loop() {
  // print variable counter value to serial
  Serial.print("counter:");   // print the string "counter:"
  Serial.println(counter);    // print the variable counter value
  delay(500);                 // wait 500ms to avoid cycling too fast
  counter++;                  // variable counter increases 1
}

