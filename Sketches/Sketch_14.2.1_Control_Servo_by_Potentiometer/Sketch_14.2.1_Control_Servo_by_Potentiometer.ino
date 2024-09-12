/**********************************************************************
  Filename    : Sketch_13.2.1_Control_Servo_by_Potentiometer
  Description : Control Servo by Potentiometer
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int servoPin = 3;           // define the pin of servo signal line
int potPin = 0;             // analog pin used to connect the potentiometer
int potVal;                 // variable to read the potValue from the analog pin

void setup() {
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
}

void loop() {
  potVal = analogRead(potPin);          // reads the potValue of the potentiometer
  potVal = map(potVal, 0, 1023, 0, 180);// scale it to use it with the servo
  myservo.write(potVal);                // sets the servo position
  delay(15);                            // waits for the servo to get there
}

