/**********************************************************************
  Filename    : Sketch_18.3.1_LED_Matrix_Bounce_Game
  Description : LED Matrix Bounce Game,Simple Snake Game for Arduino Uno R4 Wifi
  Auther      : www.freenove.com
  Modification: 2024/08/05

  This experiment comes from the Internet. If you want to know more about the experiment,
  you can visit the following link:
  https://www.eeplayground.com/posts/snake-game-arduino/

**********************************************************************/

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  matrix.begin();
}

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

// Global variables
byte frame[8][12];
byte dir = RIGHT;
byte snake_len = 2;
byte col_idx[96];
byte row_idx[96];
byte food_col = random(2,12);
byte food_row = random(1,8);
byte speed = 500;
byte food_hit = 1;
byte blank_frame[8][12];

uint8_t gameover[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
  { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int get_dir(){
  // Get values from ADC (joy stick)
  int x = analogRead(A0);
  int y = analogRead(A1);

  if((x >= 0) && (x<= 300) && dir != RIGHT){
    return LEFT;
  }
  else if( (x >=723) && (x <= 1023) && dir != LEFT){
    return RIGHT;
  }
  else if((y >= 0) && (y <= 300) && dir != DOWN){
    return UP;
  }
  else if((y >= 723) && (y <= 1023) && dir != UP){
    return DOWN;
  }
  else return dir;
}

void display_frame(){
  // Clear the frame first - Turn off all LEDs
  for(int i=0; i<8; i++){
    for(int j=0; j<12; j++){
      frame[i][j] = 0;
    }
  }  

  // Turn on LEDs for snake
  for(int i=0; i<snake_len; i++){
    // Turn on LED for Body
    frame[row_idx[i]][col_idx[i]] = 1;
  }

  // Turn on LEDs for food
  frame[food_row][food_col] = 1;

  // Display frame value in the LED matrix
  matrix.renderBitmap(frame, 8, 12);
}

void game_over(){
  // Pause Snake movement and blink for 5 times
  for(int i=0; i<5; i++){
    // Display current frame (paused movement)
    matrix.renderBitmap(frame, 8, 12);
    delay(100);
    // Display blank frame (to make LEDs blink)
    matrix.renderBitmap(blank_frame, 8, 12);
    delay(100);
    matrix.renderBitmap(gameover, 8, 12);
    delay(2000);
  }
  // Reset the length of snake 
  snake_len = 2;
}

void chk_snake_body_hit(){
  for(int i=1; i<snake_len; i++){
    // Check if head hit the body
    if((row_idx[i] == row_idx[0]) && (col_idx[i] == col_idx[0])){
      game_over();
    }
  }
}

void chk_food_hit(){
  // Logic to detect food is hit
  if(col_idx[0] == food_col && row_idx[0] == food_row){
    // Increment snake length if food is hit
    snake_len = snake_len + 1;
    // Set food_hit to 1 to enable generation of new food coordinates
    food_hit = 1;
  }
}

void get_snake_position(){
  // Logic to Calculate the next frame
  // body
  for(int i=snake_len-1; i>0; i--){
    col_idx[i] = col_idx[i-1];
    row_idx[i] = row_idx[i-1];
  }
  // head
  if (dir == RIGHT) {
    // Wrap around to left
    if(col_idx[0] == 11){
      col_idx[0] = 0;
    }
    else {
      col_idx[0] = col_idx[0] + 1;
    }
  }
  if(dir == LEFT) {
    // Wrap around to right
    if(col_idx[0] == 0){
      col_idx[0] = 11;
    }
    else{
      col_idx[0] = col_idx[0] - 1;
    }
  }
  if (dir == DOWN) {
    // Wrap around to top
    if(row_idx[0] == 7){
      row_idx[0] = 0;
    }
    else{
      row_idx[0] = row_idx[0] + 1;
    }
  }
  if(dir == UP) {
    // Wrap around to bottom
    if(row_idx[0] == 0){
      row_idx[0] = 7;
    }
    else{
      row_idx[0] = row_idx[0] - 1;
    }
  }
}

void gen_food(){
 // Generate coordinates for food
  if(food_hit == 1){
    food_col = random(0,12);
    food_row = random(0,8);
    // Set food_hit to 0 so it will not randomize food coordinates unless hit
    food_hit = 0;
  }
}

void loop() {
  // Get the snake direction
  dir = get_dir();
  // Display food and snake in the LED Matrix 
  display_frame();
  // Check if snake body is hit by its head
  chk_snake_body_hit();
  // Check if the food is hit
  chk_food_hit();
  // Get the snake positions for the next frame
  get_snake_position();
  // Generate random coordinates for food 
  gen_food();
  // Speed of the animation/snake movement
  delay(speed);
}
