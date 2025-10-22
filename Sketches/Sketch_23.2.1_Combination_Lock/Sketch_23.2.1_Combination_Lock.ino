/**
 * @author: Vegetable-SYC
 *
 * @file: Sketch_23.2.1_Combination_Lock.ino
 *
 * @date: 2025/10/22
**/

#include <Servo.h>

// Define row and column pins
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[4] = {11, 10, 9, 8}; // Row pins
byte colPins[4] = {7, 6, 5, 4};   // Column pins

// Key mapping table
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Servo myservo;     // Create servo object to control a servo
int servoPin = 12;  // Define the servo pin
int buzzerPin = 13; // Define the buzzer pin

char passWord[] = {'1', '2', '3', '4'}; // Save the correct password

void setup() {
  myservo.attach(servoPin);   // Attaches the servo on servoPin to the servo object
  myservo.write(45);          // Let the steering gear move to the start position
  pinMode(buzzerPin, OUTPUT);

  // Configure row pins as OUTPUT and set HIGH initially
  for (byte r = 0; r < 4; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }
  // Configure column pins as INPUT with pull-up resistors
  for (byte c = 0; c < 4; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
}

void loop() {
  static char keyIn[4];     // Save the input character
  static byte keyInNum = 0; // Save the the number of input characters
  char keyPressed = getKey();  // Get the character input

  // Handle the input characters
  if (keyPressed) {
    // Make a prompt tone each time press the key
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    // Save the input characters
    keyIn[keyInNum++] = keyPressed;

// Judge the correctness after input
if (keyInNum == 4) {
  bool isRight = true;            // Save whether password is correct or not
  for (int i = 0; i < 4; i++) {   // Judge whether each character of the password is correct or not
      if (keyIn[i] != passWord[i])
          isRight = false;        // Mark wrong password if there is any wrong character.
  }

  if (isRight) {                  // If the input password is right
      myservo.write(135);         // Open the switch
      delay(2000);                // Delay a period of time
      myservo.write(45);          // Close the switch
  }
  else {                          // If the input password is wrong
      digitalWrite(buzzerPin, HIGH);// Make a wrong password prompt tone
      delay(500);
      digitalWrite(buzzerPin, LOW);
  }
  keyInNum = 0; // Reset the number of the input characters to 0
}
  }
}

char getKey() {
  // Scan each row sequentially
  for (byte r = 0; r < ROWS; r++) {
    digitalWrite(rowPins[r], LOW);              // Activate current row
    for (byte c = 0; c < COLS; c++) {
      if (digitalRead(colPins[c]) == LOW) {     // Check if key is pressed (LOW)
        delay(20);                              // Debounce delay
        while (digitalRead(colPins[c]) == LOW); // Wait for key release
        digitalWrite(rowPins[r], HIGH);         // Deactivate current row
        return keys[r][c];                      // Return corresponding key value
      }
    }
    digitalWrite(rowPins[r], HIGH);             // Deactivate current row
  }
  return '\0';                                  // No key pressed
}