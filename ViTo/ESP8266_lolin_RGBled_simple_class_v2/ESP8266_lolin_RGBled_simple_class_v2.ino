//Toimii 28.9.2018 Wemos D1mini ja Lolin 7pcs RGB led shield
//https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/RGB_LED_Shield/simple
//Install [Adafruit_NeoPixel_Library](https://github.com/adafruit/Adafruit_NeoPixel) first.
//https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all
//https://www.arduino.cc/en/Hacking/LibraryTutorial


#include "Arduino.h"
#include "ESP8266_lolin_RGBled_luokka.h"

void setup() {
  Serial.begin(9600);
//  leds.begin(); // This initializes the NeoPixel library.
}

Flasher led(3000, 4000);

void loop()
{
  led.update();
}
  
 
