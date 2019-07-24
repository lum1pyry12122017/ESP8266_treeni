https://www.hackster.io/monica/blynk-board-everything-led-f44113

/******************************************************************************

This file supports LED experiments

Development environment specifics:
Arduino IDE 1.6.7
SparkFun BlynkBoard - ESP8266
******************************************************************************/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Ticker.h>
#include <Adafruit_NeoPixel.h>

//////////
// WiFi //
////////// // Enter your WiFi credentials here:
const char WiFiSSID[] = "WiFiNetworkName";
const char WiFiPSWD[] = "WiFiPassword";

///////////
// Blynk //
///////////             // Your Blynk auth token here
const char BlynkAuth[] = "0a1b2c3d4e5f";

////////////////////////////////////
// Blynk Virtual Variable Mapping //
//////////////////////////////////// //
#define RGB_VIRTUAL               V0 
#define BUTTON_VIRTUAL            V1 
#define RED_VIRTUAL               V2 
#define GREEN_VIRTUAL             V3 
#define BLUE_VIRTUAL              V4 

#define RGB_RAINBOW_VIRTUAL       V9 

#define RGB_MAX_BRIGHTNESS_VIRTUAL V15
#define RGB_STRIP_NUM_VIRTUAL     V29 

#define NUMPIXELS      18
#define DEFAULT_MAX_BRIGHTNESS 32
uint8_t blinkCount = 0; // Timer iteration counter
bool rgbSetByProject = false;

//////////////////////////
// Hardware Definitions //
//////////////////////////
const int LED_PIN = 5;
const int RGB_PIN = 4;
Adafruit_NeoPixel rgb = Adafruit_NeoPixel(18, RGB_PIN, NEO_GRB + NEO_KHZ800);
void setLED(uint8_t red, uint8_t green, uint8_t blue);

//////////////////////////
// LIGHT VALUES
//////////////////////////
byte blynkRed = 0; // Keeps track of red value
byte blynkGreen = 0; // Keeps track of green value
byte blynkBlue = 0; // Keeps track of blue value
unsigned int rgbMaxBrightness = DEFAULT_MAX_BRIGHTNESS;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn off blue LED
  rgb.begin(); // Set up WS2812
  setLED(0, 0, 32); // LED blue

  // Initialize Blynk, and wait for a connection before doing anything else
  Serial.println("Connecting to WiFi and Blynk");
  Blynk.begin(BlynkAuth, WiFiSSID, WiFiPSWD);
  while (!Blynk.connected())
    Blynk.run();
  Serial.println("Blynk connected!");
  setLED(0, 32, 0); // LED green
}

void loop()
{
  updateBlynkRGB();
}

/* 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 0 Experiment 0: zeRGBa                0
 0 Widget(s):                          0
 0  - zeRGBa: Merge, V0                0
 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 */


void updateBlynkRGB(void)
{
  
  // Show the new LED color:  
  for (int i=0; i<rgb.numPixels() ; i++)
    rgb.setPixelColor(i, rgb.Color(map(blynkRed, 0, 255, 0, rgbMaxBrightness), 
                                   map(blynkGreen, 0, 255, 0, rgbMaxBrightness),
                                   map(blynkBlue, 0, 255, 0, rgbMaxBrightness)));
  rgb.show();
}

bool firstRGBWrite = true; // On startup

BLYNK_WRITE(RGB_VIRTUAL)
{
  // RGB widget may send invalid buffer data. If we try to read those in
  // the ESP8266 crashes. At a minimum, for valid data, the buffer 
  // length should be >=5. ("0,0,0" ?)
  if (param.getLength() < 5)
    return;
  
  blynkRed = param[0].asInt();
  blynkGreen = param[1].asInt();
  blynkBlue = param[2].asInt();

  
  if (!firstRGBWrite)
  {
    // Set all attached pixels (usually it'll only be 1)
    updateBlynkRGB();
  }
  else
  {
    firstRGBWrite = false;
  }
}

void setLED(uint8_t red, uint8_t green, uint8_t blue)
{
  rgb.setPixelColor(0, rgb.Color(red, green, blue));
  rgb.show();
}
