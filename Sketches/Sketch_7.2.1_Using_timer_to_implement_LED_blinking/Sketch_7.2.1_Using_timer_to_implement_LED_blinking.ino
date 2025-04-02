/**********************************************************************
  Filename     : Sketch_7.2.1_Using_timer_to_implement_LED_blinking
  Description  : Using timer to implement LED blinking
  Auther       : www.freenove.com
  Modification : 2024/08/05
  CallbackTimerR4 is provided by Kingsman
  Urls         : https://github.com/embedded-kiddie/CallbackTimerR4
**********************************************************************/
#include <CBTimer.h>

const int ledpin = 13;

void callback_func(void) {
  int ledstate = digitalRead(ledpin);
  digitalWrite(ledpin, !ledstate);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  static CBTimer timer;
  timer.begin(1000, callback_func);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}