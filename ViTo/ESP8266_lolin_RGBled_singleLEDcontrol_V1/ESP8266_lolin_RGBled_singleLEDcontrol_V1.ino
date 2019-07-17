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

void setup() {
  Serial.begin(9600);
  addVersionToSerialOutput();
   Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);

}

//Luo instanssi rgbledcontrol luokasta
RgbLedControl control;

void loop()
{
  Blynk.run();
//  control.dummy();
  control.RgbLedControlFunction(0,10,0,0);
  control.RgbLedControlFunction(1,20,0,0);
//  control.RgbLedControlFunction(2,0,10,0);
//  control.RgbLedControlFunction(3,0,20,0);
//  control.RgbLedControlFunction(4,0,0,10);
//  control.RgbLedControlFunction(5,0,0,20);
//  control.RgbLedControlFunction(6,10,10,10);
  delay(10);
}

void addVersionToSerialOutput()
{
    char fullPath[] = __FILE__;
    Serial.print(fullPath);
}
