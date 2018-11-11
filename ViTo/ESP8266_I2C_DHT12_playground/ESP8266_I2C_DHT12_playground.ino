
//https://github.com/xreef/DHT12_sensor_library

// Do not remove the include below
#include "Arduino.h"
#include <DHT12.h>

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`

float t12=255;
float h12=255;
int timeSinceLastRead=0;

// Set dht12 i2c comunication on default Wire pin
DHT12 dht12;
// Initialize the OLED display using Wire library
SSD1306  display(0x3c, D2, D1);

void setup()
{
	Serial.begin(112560);
  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
	
	// Start sensor
	dht12.begin();
}
//int timeSinceLastRead = 0;

void loop()
{
  lueanturi();
  displayTempHumid();
  display.display();
  delay (1000);
}
