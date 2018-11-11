//toimii 1.10.2018 D1mini lolin RGBled
/*Intend to control the lolin 7pcs RGBled shield
 * 
 */
#ifndef lolin_RGBled
#define lolin_RGBled

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define LED_NUM 7
#define PIN D4

// Setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
//Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

class Flasher {
  long onTime;
  long offTime;
  int ledState = LOW;
  unsigned long previousMillis;
  Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

public:

  Flasher(long on, long off);
  void led_set(uint8 r, uint8 g, uint8 b);
  void update(uint8 red, uint8 green, uint8 blue);

};
#endif
