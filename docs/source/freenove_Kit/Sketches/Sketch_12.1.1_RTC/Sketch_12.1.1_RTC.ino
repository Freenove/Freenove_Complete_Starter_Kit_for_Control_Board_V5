/**********************************************************************
  Filename    : Sketch_11.1.1_RTC
  Description : RTC experiment
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// Include the RTC library
#include "RTC.h"

volatile bool irqFlag = false;  // Flag to indicate a periodic callback.
bool ledState = false;          // Current LED state: true for ON and false for OFF
const int led = LED_BUILTIN;    // Pin number for the built-in LED

void setup() {
  pinMode(led, OUTPUT);  // Configure the LED pin as output

  Serial.begin(9600);

  // Initialize the RTC
  RTC.begin();
  // Set an arbitrary time to the RTC (required for RTC.setPeriodicCallback to work)
  RTCTime mytime(13, Month::MAY, 2024, 05, 13, 00, DayOfWeek::MONDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  // Set the periodic callback to trigger every 2 seconds
  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop() {
  // Check if the periodic callback has been triggered
  if (irqFlag) {
    Serial.println("Timed CallBack");  // Output a debugging message
    ledState = !ledState;              // Toggle the LED state
    digitalWrite(led, ledState);       // Update the LED
    irqFlag = false;                   // Reset the flag
  }
}

// This is the callback function to be passed to RTC.setPeriodicCallback()
void periodicCallback() {
  // Set the flag to true to indicate the callback has been triggered
  irqFlag = true;
}