//Toimii 27.9.2018 Wemos D1mini ja Lolin 7pcs RGB led shield
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

int ledState1 = LOW;
unsigned long previousMillis1 = 0;
long OnTime1 = 2000;
long OffTime1 = 3000;

int ledState2 = LOW;
unsigned long previousMillis2 = 0;
long OnTime2 = 1000;
long OffTime2 = 500;

void setup() {
  Serial.begin(9600);
  leds.begin(); // This initializes the NeoPixel library.
}

void led_set(uint8 R, uint8 G, uint8 B) {
  for (int i = 0; i < LED_NUM; i++) {
    leds.setPixelColor(i, leds.Color(R, G, B));
    leds.show();
    delay(200);
  }
}

void loop() {
  unsigned long currentMillis = millis();
//  Serial.println(currentMillis - previousMillis11);

  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;
    previousMillis1 = currentMillis;
    led_set(0, 0, 0);
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;
    previousMillis1 = currentMillis;
    led_set(10, 0, 0);
    
  }
  if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    ledState2 = LOW;
    previousMillis2 = currentMillis;
    led_set(0, 0, 0);
  }
  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    ledState2 = HIGH;
    previousMillis2 = currentMillis;
    led_set(0, 10, 0);
    
  }

  }
  
  /*Serial.println("Red");
  led_set(10, 0, 0);//red
  led_set(0, 0, 0);
  
  Serial.println("Green");
  led_set(0, 10, 0);//green
  led_set(0, 0, 0);

  Serial.println("Blue");
  led_set(0, 0, 10);//blue
  led_set(0, 0, 0);
*/

