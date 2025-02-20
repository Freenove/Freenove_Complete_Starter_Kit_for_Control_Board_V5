/**********************************************************************
  Filename    : Sketch_31.1.1_Infrared_obstacle_avoidance_sensor_and_LED
  Description : Infrared obstacle avoidance sensor and LED
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int sensorPin = 6;  // the number of the infrared motion sensor pin
int ledPin = 5;     // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);                       // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);                         // initialize the LED pin as output
}

void loop() {
        if(digitalRead(sensorPin) == LOW){ 
            digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
            printf("led turned on >>>\n");    //Output information on terminal
        }
        else {
            digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
            printf("led turned off <<<\n");//Output information on terminal
        }
}
