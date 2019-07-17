/*Toimii 29.11.2018 WemosD1 mini LolinRGB LED shield
 *
 */
#include "Arduino.h"
#include "lolin_RGBled.h"
#include "Settings.h"

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial

char auth[] = "63d27336e7ac485bb172c83664b803bc";
char ssid[] = "241385";
char pass[] = "112233445566";
int R = 5;
int G = 5;
int B = 5;
int lednumber = 0;

void setup() {
  Serial.begin(9600);
  addVersionToSerialOutput();
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);

}

//Luo instanssi rgbledcontrol luokasta
RgbLedControl control;

//Tama ohjaa RGB ledia

BLYNK_WRITE(V21)
{
R = param[0].asInt();
G = param[1].asInt();
B = param[2].asInt();
//Serial.println(R);
//Serial.println(G);
//Serial.println(B);

//for(int i=0;i<NUMPIXELS;i++){

//pixels.setPixelColor(i, pixels.Color(R,G,B));

//pixels.show();
}
//}

BLYNK_WRITE(V22)
{
lednumber = param.asInt();
Serial.print("Blynk write V22 lednumber: ");
Serial.println(lednumber);
}

void loop()
{
  Blynk.run();
  Serial.print("Loop lednumber: ");
  Serial.println(lednumber);
  Serial.print("Loop R: ");
  Serial.println(R);
  Serial.print("Loop G: ");
  Serial.println(G);
  Serial.print("Loop B: ");
  Serial.println(B);
  control.RgbLedControlFunction(lednumber,R,G,B);
  delay(2500);
}

void addVersionToSerialOutput()
{
    char fullPath[] = __FILE__;
    Serial.print(fullPath);
}
/*Serial.print("R: ");
Serial.println(R);
Serial.print("G: ");
Serial.println(G);
Serial.print("B: ");
Serial.println(B);
*/
