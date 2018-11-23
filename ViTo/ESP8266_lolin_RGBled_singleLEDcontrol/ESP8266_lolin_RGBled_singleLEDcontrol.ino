#include "Arduino.h"
#include "lolin_RGBled.h"
#include "Settings.h"

void setup() {
  Serial.begin(9600);
//  addVersionToSerialOutput();
}

RgbLedControl control;

void loop()
{
  control.dummy();
  control.RgbLedControlFunction(0,10,0,0);
  control.RgbLedControlFunction(1,20,0,0);
//  control.RgbLedControlFunction(2,0,10,0);
//  control.RgbLedControlFunction(3,0,20,0);
//  control.RgbLedControlFunction(4,0,0,10);
//  control.RgbLedControlFunction(5,0,0,20);
//  control.RgbLedControlFunction(6,10,10,10);
  delay(1000);
}

void addVersionToSerialOutput()
{
    char fullPath[] = __FILE__;
    char *slash;
    slash = strrchr(fullPath, '/');
    slash++;
    strcpy(fullPath, slash);
    byte length = strlen(fullPath);
    char fileName[20] = "";
    strncpy(fileName, fullPath, (length - 4));
    strcat(fileName, ".ino");
    Serial.print(fileName);
}
