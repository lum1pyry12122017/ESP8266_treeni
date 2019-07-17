/*Toimii 30.11.2018 WemosD1 mini LolinRGB LED shield
 *
 */
#include "Arduino.h"
#include "lolin_RGBled.h"
#include "Settings.h"

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial

char auth[] = "f4cb0080290741c29279a4960710dd71";
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

void loop() {
  Blynk.run();
  control.RgbLedControlFunction(lednumber,R,G,B);
  delay(2500);
}

//Nouda koodin tiedot boot printtiin
void addVersionToSerialOutput() {
    char fullPath[] = __FILE__;
    Serial.print(fullPath);
}

//Tama ohjaa RGB ledia Blynkista tulevilla colorarvoilla
BLYNK_WRITE(V21){
R = param[0].asInt();
G = param[1].asInt();
B = param[2].asInt();
}

//Blynkilta tuleva ohjattavan ledin numero
BLYNK_WRITE(V22){
lednumber = param.asInt();
Serial.print("Blynk write V22 lednumber: ");
Serial.println(lednumber);
}
