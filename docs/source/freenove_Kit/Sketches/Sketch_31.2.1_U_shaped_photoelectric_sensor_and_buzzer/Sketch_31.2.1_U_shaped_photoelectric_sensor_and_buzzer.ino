/**********************************************************************
  Filename    : Sketch_30.2.1_U_shaped_photoelectric_sensor_and_buzzer
  Description : U shaped photoelectric sensor and buzzer
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 2;  // the number of the infrared motion sensor pin
int ledPin = 13;     // the number of the LED pin
int buzzerPin = 5;  // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);                       // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);                         // initialize the LED pin as output
  pinMode(buzzerPin, OUTPUT);                      // initialize the LED pin as output
  attachInterrupt(sensorPin, sensorEven, CHANGE);  
}

void alarm(int times) {
  while (times--) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
}

void sensorEven(void) {
  alarm(3);
}

void loop() {
  delay(1000);
}
