//Pakollinen konstruktori kirjastolle, estaa kayttamasta tata tuplana
#ifndef lolin_RGBled
#define lolin_RGBled

//Otetaan tarvittavat kirjastot mukaan ja maaritellaan pysyvat asiat
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define LED_NUM 7
#define PIN D4

//luokan esittely
class RgbLedControl {
  Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

public:

  RgbLedControl();
  void RgbLedControlFunction(uint8 ledposition, uint8 redValue, uint8 greenValue, uint8 blueValue);
  void dummy();
  void serialPrintRgbLedControlFunction(uint8 ledpositionp, uint8 redValuep, uint8 greenValuep, uint8 blueValuep);

private:
  
};
#endif
