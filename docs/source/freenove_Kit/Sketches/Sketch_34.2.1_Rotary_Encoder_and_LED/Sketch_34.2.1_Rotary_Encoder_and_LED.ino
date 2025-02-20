/**********************************************************************
  Filename    : Sketch_33.2.1_Rotary_Encoder_and_LED
  Description : Rotary Encoder and LED
  Auther      : www.freenove.com 
  Modification: 2024/08/05
**********************************************************************/

int clkPin = 6;  // the number of the infrared motion sensor pin
int dtPin = 5;   // the number of the LED pin
int swPin = 4;   // the number of the LED pin
int ledPin = 3;  // the number of the LED pin

int symbol = 0;
int lastDTStatus = 0;
int currentDTStatus = 0;
int previousCounterValue = 0;
int currentCounterValue = 0;

void rotaryDeal() {
  int symbol = 0;
  int lastDTStatus = 0;
  int currentDTStatus = 0;
  lastDTStatus = digitalRead(dtPin);

  while (digitalRead(clkPin) == LOW) {
    // When not rotating, the value of GPIO.input (clkPin) is 1, and it will become 0 when rotating.
    currentDTStatus = digitalRead(dtPin);  // Record the current value when rotating.
    symbol = 1;
  }
  if (symbol == 1) {  // When rotating the encoder by hand
    symbol = 0;
    if ((lastDTStatus == 1) && (currentDTStatus == 0)) {
      //When rotate clockwise, the angular displacement increases, and the count value increases.
      previousCounterValue = previousCounterValue + 1;
    }
    if ((lastDTStatus == 0) && (currentDTStatus == 1)) {
      // When rotate counterclockwise, the angular displacement decreases, and the count value decreases.
      previousCounterValue = previousCounterValue - 1;
    }
  }
}

void setup() {
  pinMode(clkPin, INPUT);        // initialize the sensor pin as input
  pinMode(dtPin, INPUT);         // initialize the LED pin as output
  pinMode(swPin, INPUT_PULLUP);  // initialize the LED pin as output
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as output
  Serial.begin(9600);
}

void loop() {
  rotaryDeal();
  if (digitalRead(swPin) == LOW) {
    delay(120);
    if (digitalRead(swPin) == LOW) {
      // When the rotary encoder is pressed by hand, the count value is cleared.
      previousCounterValue = 0;
    }
  }
  if (previousCounterValue >= 100) {
    previousCounterValue = 100;
  }
  if (previousCounterValue <= 0) {
    previousCounterValue = 0;
  }
  if (currentCounterValue != previousCounterValue) {
    Serial.print("Counter= ");  
    Serial.print(previousCounterValue);
    Serial.print("\n");  
    currentCounterValue = previousCounterValue;
  }
  analogWrite(ledPin, map(previousCounterValue, 0, 100, 0, 255));//Mapping to PWM duty cycle
}
