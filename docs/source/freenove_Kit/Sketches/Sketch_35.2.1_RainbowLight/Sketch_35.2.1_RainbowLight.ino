/**********************************************************************
  Filename    : Sketch_34.2.1_RainbowLight
  Description : RainbowLight
  Auther      : www.freenove.com 
  Modification: 2024/08/05
**********************************************************************/

#include <FastLED.h>  // Include FastLED library
#define NUM_LEDS 8    // Number of LEDs in the chain
#define DATA_PIN 6    // Data pin for LED control
#define BRIGHTNESS 64

int red = 0;
int green = 0;
int blue = 0;
CRGB leds[NUM_LEDS];  // Array to hold LED color data

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for (int j = 0; j < 256 * 5; j++) {
    for (int i = 0; i < 8; i++) {
      Wheel(((i * 256 / 8) + j)%255);
      leds[i] = CRGB(red, green, blue);
    }
    FastLED.show();           // Update LEDs
    delay(10);
  }
}

void Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    red = 255 - WheelPos * 3;
    green = 0;
    blue = WheelPos * 3;
  }
  else if (WheelPos < 170) {
    WheelPos -= 85;
    red = 0;
    green = WheelPos * 3;
    blue = 255 - WheelPos * 3;
  }
  else {
    WheelPos -= 170;
    red = WheelPos * 3;
    green = 255 - WheelPos * 3;
    blue = 0;
  }
}