/**
 * @author: Vegetable-SYC
 *
 * @file: Sketch_23.1.1_Get_Input_Characters.ino
 *
 * @date: 2025/10/22
**/

// Define row and column pins
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {11, 10, 9, 8};  // Row pins
byte colPins[COLS] = {7, 6, 5, 4};    // Column pins

// Key mapping table
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void setup() {
  Serial.begin(9600);
  // Configure row pins as OUTPUT and set HIGH initially
  for (byte r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }
  // Configure column pins as INPUT with pull-up resistors
  for (byte c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
}

void loop() {
  char key = getKey();
  if (key != '\0') {
    Serial.print("Pressed: ");
    Serial.println(key);
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
