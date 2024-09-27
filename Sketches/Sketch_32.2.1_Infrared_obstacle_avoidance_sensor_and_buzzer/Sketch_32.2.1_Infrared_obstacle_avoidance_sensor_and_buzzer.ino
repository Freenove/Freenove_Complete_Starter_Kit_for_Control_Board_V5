/**********************************************************************
  Filename    : Sketch_31.2.1_Infrared_obstacle_avoidance_sensor_and_buzzer
  Description : Infrared obstacle avoidance sensor and buzzer
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 6;  // the number of the infrared motion sensor pin
int ledPin = 4;     // the number of the LED pin
int buzzerPin = 5;  // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);                       // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);                         // initialize the LED pin as output
  pinMode(buzzerPin, OUTPUT);                      // initialize the LED pin as output
  attachInterrupt(sensorPin, sensorEven, FALLING);  
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
