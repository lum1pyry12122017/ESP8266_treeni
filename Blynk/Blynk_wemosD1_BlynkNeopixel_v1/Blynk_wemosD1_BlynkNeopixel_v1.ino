
//http://www.mrhobbytronics.com/esp8266-blynk-neopixel/
//change the type to merged and assign it to virtual pin 21

#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define PIN D5
#define NUMPIXELS 3
#define BLYNK_PRINT Serial
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
char auth[] = "aca0dd3d64c140a18d0a98375fed6f05";
char ssid[] = "241385";
char pass[] = "112233445566";

void setup()
{
Serial.begin(9600);
   Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);
pixels.begin();
}
BLYNK_WRITE(V21)
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);
for(int i=0;i<NUMPIXELS;i++){

pixels.setPixelColor(i, pixels.Color(R,G,B));

pixels.show();
}
}

void loop()
{
Blynk.run();
}

