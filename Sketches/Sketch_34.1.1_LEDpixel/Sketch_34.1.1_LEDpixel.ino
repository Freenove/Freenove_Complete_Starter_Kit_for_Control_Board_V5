/**********************************************************************
  Filename    : Sketch_34.1.1_LEDpixel
  Description : LEDpixel
  Auther      : www.freenove.com 
  Modification: 2024/08/05
**********************************************************************/

#include <FastLED.h>  // Include FastLED library
#define NUM_LEDS 8    // Number of LEDs in the chain
#define DATA_PIN 6    // Data pin for LED control
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];  // Array to hold LED color data
int m_color[5][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 255 }, { 0, 0, 0 } };
int delayval = 100;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Loop through each LED and set it to blue
  for (int j = 0; j < 5; j++) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = CRGB(m_color[j][0], m_color[j][1], m_color[j][2]);
      FastLED.show();           // Update LEDs
      leds[dot] = CRGB::Black;  // Clear the current LED
      delay(delayval);               // Wait for a short period before moving to the next LED
    }
    delay(500); 
  }
}
