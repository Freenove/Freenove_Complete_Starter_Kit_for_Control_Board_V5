/**********************************************************************
  Filename     : SSketch_4.1.1_Serial_print_using_timer
  Description  : Serial print using timer
  Auther       : www.freenove.com
  Modification : 2024/08/05
  CallbackTimerR4 is provided by Kingsman
  Urls         : https://github.com/embedded-kiddie/CallbackTimerR4
**********************************************************************/
#include <CBTimer.h>

int counter;
bool counter_flag;

void callback_func(void) {
  counter_flag = true;
  counter += 1;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  static CBTimer timer;
  timer.begin(1000, callback_func);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(counter_flag == true)
  {
    counter_flag = false;
    Serial.print("counter:");
    Serial.println(counter);
  }
}
