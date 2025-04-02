/**********************************************************************
  Filename    : Sketch_42.1.1_HID_Mouse
  
  Description : This code is designed to control mouse cursor movement using an Arduino Uno R4.
  When the button connected to pin 7 is pressed, the mouse moves 10 units to the right.
  Uncommenting the respective sections below the main loop will change the direction of movement.
  
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include <Mouse.h>  // Include the Mouse library for mouse control

const int upButton = 2;  // Define the pin where the button is connected
const int downButton  = 3;  // Define the pin where the button is connected
const int leftButton  = 4;  // Define the pin where the button is connected
const int rightButton = 5;  // Define the pin where the button is connected

void setup() {
  pinMode(upButton, INPUT_PULLUP);  // Set the button pin as an input
  pinMode(downButton, INPUT_PULLUP);  // Set the button pin as an input
  pinMode(leftButton, INPUT_PULLUP);  // Set the button pin as an input
  pinMode(rightButton, INPUT_PULLUP);  // Set the button pin as an input
  Mouse.begin();           // Initialize mouse control
  delay(1000);             // Wait for 1 second (1000 milliseconds) for hardware initialization
}

void loop() {
  // Check if the button is pressed (HIGH)
  if (digitalRead(rightButton) == LOW) {
    //right
    Mouse.move(10, 0);  // Move the mouse 10 units to the right
    delay(200);         // Wait for 200 milliseconds to slow down mouse movement
  }
  if (digitalRead(leftButton) == LOW) {
    //Left
    Mouse.move(-10, 0);
    delay(200);
  }
  if (digitalRead(downButton) == LOW) {
    // Down
    Mouse.move(0, 10);
    delay(200);
  }
  if (digitalRead(upButton) == LOW) {
    // Up
    Mouse.move(0, -10);
    delay(200);
  }
}
