//toimii 1.10.2018 D1mini lolin RGBled
/*Intend to control the lolin 7pcs RGBled shield
 * 
 */
#include "lolin_RGBled.h"

Flasher::Flasher(long on, long off) {
  onTime = on;
  offTime = off;
  ledState = LOW;
  previousMillis = 0;

  leds.begin();
  leds.show(); //Initialize all OFF 
}

void Flasher::led_set(uint8 r, uint8 g, uint8 b) {
  for (int i = 0; i < LED_NUM; i++) {
    leds.setPixelColor(i, leds.Color(r, g, b));
    leds.show();
    delay(100);
  }
}

void Flasher::update(uint8 red, uint8 green, uint8 blue) {
  unsigned long currentMillis = millis();
  Serial.print("currentMillis - previousMillis: ");
  Serial.println(currentMillis - previousMillis);

  if((ledState == HIGH) && (currentMillis - previousMillis >= onTime)) {
    ledState = LOW;
    Serial.print("currentMillis - previousMillis >= OnTime: ");
    Serial.println(onTime);
    previousMillis = currentMillis;
    led_set(0, 0, 0);
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= offTime)) {
    ledState = HIGH;
    Serial.print("currentMillis - previousMillis >= OffTime: ");
    Serial.println(offTime);
    previousMillis = currentMillis;
    led_set(red, green, blue);
  }
 }
