/*toimii 19.09.2018, d1mini.
https://learn.sparkfun.com/tutorials/micro-oled-breakout-hookup-guide#hardware-assembly
https://github.com/xreef/DHT12_sensor_library */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "Arduino.h"
#include <DHT12.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

//DHT12 stuff
DHT12 dht12; // Set dht12 i2c comunication on default Wire pin
float t12=255;
float h12=255;
int timeSinceLastRead=0;

//Blynk stuff
char auth[] = "01e8a3de5afa4efd863bc52b6023817f";
//char ssid[] = "241385";
//char pass[] = "112233445566";
//char ssid[] = "as_guest";
//char pass[] = "sports38#Reward@";
char ssid[] = "CPARK_CLIENTS";
char pass[] = "";
BlynkTimer timer;

// MicroOLED stuff
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define DC_JUMPER 0
// MicroOLED Object Declaration
MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration


void setup(){
	Serial.begin(9600);
  Serial.println("Hello, board started.");  // Start board
	dht12.begin();                            // Start sensor
  oled.begin();                             // Initialize the OLED.
  oled.clear(ALL);  // clear(ALL) will clear out the OLED's graphic memory. clear(PAGE) will clear the Arduino's display buffer. Clear the display's memory (gets rid of artifacts)
  t12 = luetemperaturedata();               //Get first values on display
  h12 = luehumiditydata();
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);  //start blynk
}

void loop(){
  delay(1000);
  t12 = luetemperaturedata();
  h12 = luehumiditydata();
  senddatatoblynk();
  String lampo = String(t12);
  String hum = String(h12);
  paivita_naytto_data(lampo,hum);
  delay(4000);
  welcome();
  Blynk.run();

// Setup a function to be called every second
//  timer.setInterval(1000L, sendSensor);
//  timer.run(); 
}
