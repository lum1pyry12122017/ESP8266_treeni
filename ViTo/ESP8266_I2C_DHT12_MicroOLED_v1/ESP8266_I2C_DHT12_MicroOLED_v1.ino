
//https://learn.sparkfun.com/tutorials/micro-oled-breakout-hookup-guide#hardware-assembly
//https://github.com/xreef/DHT12_sensor_library

#include "Arduino.h"
#include <DHT12.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

float t12=255;
float h12=255;
int timeSinceLastRead=0;

DHT12 dht12; // Set dht12 i2c comunication on default Wire pin

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define DC_JUMPER 0

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration

void setup()
{
	Serial.begin(9600);
	
// Start sensor
	dht12.begin();

 // Initialize the OLED.
  oled.begin();
  
// clear(ALL) will clear out the OLED's graphic memory. clear(PAGE) will clear the Arduino's display buffer.
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
}

void loop()
{
  lueanturi();
  delay(1000);
  paivita_naytto0();
  delay(1000);
  paivita_naytto1();
  delay(1000);
  paivita_naytto2();
  delay(1000);
  paivita_naytto3();

}

void paivita_naytto0(){
  oled.clear(PAGE);
  oled.setFontType(0);
  Serial.println("Font type0");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("type0"); // Print a const string
  oled.setCursor(0, 16);  // Set the text cursor to the upper-left of the screen.
  oled.print("123456789"); // Print a const string
  oled.setCursor(0, 32);  // Set the text cursor to the upper-left of the screen.
  oled.print("123456789"); // Print a const string
  oled.display();
}
void paivita_naytto1(){
  oled.clear(PAGE);
    oled.setFontType(1);
  Serial.println("Font type1");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("type1"); // Print a const string
  oled.setCursor(0, 16);  // Set the text cursor to the upper-left of the screen.
  oled.print("1234567"); // Print a const string
  oled.setCursor(0, 32);  // Set the text cursor to the upper-left of the screen.
  oled.print("1234567"); // Print a const string
  oled.display();
}
void paivita_naytto2(){
  oled.clear(PAGE);
    oled.setFontType(2);
  Serial.println("Font type2");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("ty 2"); // Print a const string
  oled.setCursor(0, 24);  // Set the text cursor to the upper-left of the screen.
  oled.print("12345"); // Print a const string
  oled.display();
}
void paivita_naytto3(){
  oled.clear(PAGE);
    oled.setFontType(3);
  Serial.println("Font type3");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("t 3"); // Print a const string
  oled.display();
}


