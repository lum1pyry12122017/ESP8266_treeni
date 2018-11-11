#include "Arduino.h"
#ifndef ESP8266_lolin_RGBled_luokka_h
#define ESP8266_lolin_RGBled_luokka_h
#define LED_NUM 7
#define PIN D4
#include <Adafruit_NeoPixel.h>

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

class Flasher
{
  long OnTime;
  long OffTime;
  
  int ledState = LOW;
  unsigned long previousMillis;


// Constructor 
public:
Flasher(long on, long off)
{
  OnTime = on;
  OffTime = off;
  ledState = LOW;
  previousMillis = 0;
  leds.begin(); // This initializes the NeoPixel library.
}

  void led_set(uint8 R, uint8 G, uint8 B) {
  for (int i = 0; i < LED_NUM; i++) {
    leds.setPixelColor(i, leds.Color(R, G, B));
    leds.show();
    delay(200);
  }
}

void update() {
  unsigned long currentMillis = millis();
//  Serial.println(currentMillis - previousMillis1);

  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;
    previousMillis = currentMillis;
    led_set(0, 0, 0);
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;
    previousMillis = currentMillis;
    led_set(10, 0, 0);
  }
 }
};
#endif
