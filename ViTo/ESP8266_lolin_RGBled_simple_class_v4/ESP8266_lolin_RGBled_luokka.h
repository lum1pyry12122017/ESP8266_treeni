#ifndef ESP8266_lolin_RGBled_luokka_h
#define ESP8266_lolin_RGBled_luokka_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define LED_NUM 7
#define PIN D4

// Setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
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

void led_set(uint8 R, uint8 G, uint8 B)
{
  for (int i = 0; i < LED_NUM; i++) {
    leds.setPixelColor(i, leds.Color(R, G, B));
    leds.show();
    delay(100);
  }
}

void update(  uint8 Red, uint8 Green, uint8 Blue)
{
  unsigned long currentMillis = millis();
  Serial.print("currentMillis - previousMillis: ");
  Serial.println(currentMillis - previousMillis);

  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;
    Serial.print("currentMillis - previousMillis >= OnTime: ");
    Serial.println(OnTime);
    previousMillis = currentMillis;
    led_set(0, 0, 0);
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;
    Serial.print("currentMillis - previousMillis >= OffTime: ");
    Serial.println(OffTime);
    previousMillis = currentMillis;
    led_set(Red, Green, Blue);
  }
 }
};
#endif
