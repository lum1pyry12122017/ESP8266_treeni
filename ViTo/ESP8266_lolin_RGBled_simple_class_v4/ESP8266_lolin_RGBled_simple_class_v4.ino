/*
Toimii 28.9.2018 Wemos D1mini ja Lolin 7pcs RGB led shield
https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/RGB_LED_Shield/simple
https://github.com/adafruit/Adafruit_NeoPixel
https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all
*/

//Pitaisi muuttaa taman ohjeen mukaiseksi kahden tiedoston (.h ja .cpp) libraryksi. https://www.arduino.cc/en/Hacking/LibraryTutorial


#include "Arduino.h"
#include "ESP8266_lolin_RGBled_luokka.h"

void setup() {
  Serial.begin(9600);
//  leds.begin(); // This initializes the NeoPixel library.
}

Flasher ledRed(3000, 7000);
Flasher ledGreen(4000, 7000);
Flasher ledBlue(5000, 7000);

void loop()
{
  ledRed.update(10,0,0);
  ledGreen.update(0,10,0);
  ledBlue.update(0,0,10);  
}
  
 
