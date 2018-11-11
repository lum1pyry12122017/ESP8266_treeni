/*
Toimii 28.9.2018 Wemos D1mini ja Lolin 7pcs RGB led shield
Timer controlled state: OK.

NOTE!NeoPixel Jewel Product Selector (http://adafru.it/3047)
https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/RGB_LED_Shield/simple
https://github.com/adafruit/Adafruit_NeoPixel
https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all
*/
/*TODO
 * OTA https://arduino-esp8266.readthedocs.io/en/2.4.2/ota_updates/readme.html
 * Control individual leds
 * Switch cotrolled state
 * HW interrupt (button)
 * Blynk interface
 * DHT12 interface
 * Map temperature to RGB
 * Deep sleep
 */


#include "Arduino.h"
#include "lolin_RGBled.h"

void setup() {
  Serial.begin(9600);
}

Flasher tehtava1_ledRed(3000, 7000);
Flasher tehtava2_ledGreen(4000, 7000);
Flasher tehtava3_ledBlue(5000, 7000);

void loop()
{
  tehtava1_ledRed.update(10,0,0);
  tehtava2_ledGreen.update(0,10,0);
  tehtava3_ledBlue.update(0,0,10);  
}
  
 
