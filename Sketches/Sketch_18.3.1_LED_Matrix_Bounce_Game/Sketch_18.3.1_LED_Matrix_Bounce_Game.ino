/**********************************************************************
  Filename    : Sketch_18.3.1_LED_Matrix_Bounce_Game
  Description : LED Matrix Bounce Game
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

uint8_t game_over[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
  { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int y = 4;           // starting y position
int x = 4;           // starting x position
int b = 1;           // starting y direction
int a = 1;           // starting x direction
int anticipate = 5;  // variable used to anticipate whether ball hits bat
int speed = 300;     // initial delay which decreases each time ball hit


void loop() {
  int batcenter = (analogRead(A0) / 204);
  frame[batcenter][11] = 1;
  frame[batcenter + 1][11] = 1;
  frame[batcenter + 2][11] = 1;
  frame[y][x] = 1;
  matrix.renderBitmap(frame, 8, 12);
  delay(speed);
  frame[batcenter][11] = 0;
  frame[batcenter + 1][11] = 0;
  frame[batcenter + 2][11] = 0;
  frame[y][x] = 0;
  matrix.renderBitmap(frame, 8, 12);
  delay(1);

  if (y == 7) {
    b = -b;
  }
  if (y == 0) {
    b = -b;
  }
  if (x == 10) {  // when ball reaches line in front of batcenter, checks if batcenter hit
    anticipate = (y + b);
    speed = (speed - 20);  // reduces delay each time batcenter hit
    if ((anticipate == batcenter) or (anticipate == (batcenter + 1)) or (anticipate == (batcenter + 2))) {
      a = -a;
    } else {  // game over grid
      matrix.renderBitmap(game_over, 8, 12);
      delay(2000);
      x = 4;
      y = 4;
      a = -1;
      b = -1;
      speed = 300;
    }
  }
  if (x == 0) {
    a = -a;
  }
  y = (y + b);  // adjusts ball position
  x = (x + a);
}