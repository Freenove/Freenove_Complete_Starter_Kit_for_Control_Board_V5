/**********************************************************************
  Filename    : Sketch_18.1.1_LED_Matrix
  Description : LED Matrix is onboard
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "Arduino_LED_Matrix.h"  // Include the LED_Matrix library

ArduinoLEDMatrix matrix;  // Create an instance of the ArduinoLEDMatrix class

byte frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 }
};

unsigned long frame2[] = {
  0x0000F010,
  0x82942042,
  0x641080F0
};

const uint32_t fullOn[] = {
  0xffffffff,
  0xffffffff,
  0xffffffff
};
const uint32_t fullOff[] = {
  0x00000000,
  0x00000000,
  0x00000000
};

void setup() {
  matrix.begin();  // Initialize the LED matrix
  matrix.loadFrame(fullOn);
  delay(250);
  matrix.loadFrame(fullOff);
  delay(250);
}

void loop() {
  //matrix.loadFrame(frame2);
  matrix.renderBitmap(frame, 8, 12);
  delay(250);
}
