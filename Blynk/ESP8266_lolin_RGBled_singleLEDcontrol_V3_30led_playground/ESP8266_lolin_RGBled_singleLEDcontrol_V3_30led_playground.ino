/*Toimii 30.11.2018 WemosD1 mini LolinRGB LED shield
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

//Tama ohjaa RGB ledia blynkista tulevilla variarvoilla
BLYNK_WRITE(V21) {
R = param[0].asInt();
G = param[1].asInt();
B = param[2].asInt();
Serial.print("Blynk write V21 red: ");
Serial.println(R);
}

BLYNK_WRITE(V22) {
lednumber = param.asInt();
Serial.print("Blynk write V22 lednumber: ");
Serial.println(lednumber);
}

void loop() {
  Blynk.run();
  //control.RgbLedControlFunction(lednumber,R,G,B);
  control.AllOnRgbLedControlFunction(R,G,B);
  delay(1000);
}

void addVersionToSerialOutput() {
    char fullPath[] = __FILE__;
    Serial.print(fullPath);
}
