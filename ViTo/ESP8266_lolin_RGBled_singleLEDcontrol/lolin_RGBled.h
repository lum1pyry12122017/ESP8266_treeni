#ifndef lolin_RGBled
#define lolin_RGBled

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define LED_NUM 7
#define PIN D4

class RgbLedControl {
  Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

public:

  RgbLedControl();
  void RgbLedControlFunction(int ledposition, int redValue, int greenValue, int blueValue);
  void dummy();
  
};
#endif
