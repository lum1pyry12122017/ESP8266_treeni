//Toimii 28.9.2018 Wemos D1mini ja Lolin 7pcs RGB led shield
//https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/RGB_LED_Shield/simple
//Install [Adafruit_NeoPixel_Library](https://github.com/adafruit/Adafruit_NeoPixel) first.
//https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all


#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define PIN   D4
#define LED_NUM 7

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

// Constructor - creates a Flasher 
// and initializes the member variables and state
public:
Flasher(long on, long off)
{
  OnTime = on;
  OffTime = off;
  ledState = LOW;
  previousMillis = 0;
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

void setup() {
  Serial.begin(9600);
  leds.begin(); // This initializes the NeoPixel library.
}

Flasher led(3000, 4000);

void loop()
{
  led.update();
}
  
 
