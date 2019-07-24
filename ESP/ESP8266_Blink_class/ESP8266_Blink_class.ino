/*
Toimii 5.10.2018 D1mini.
*/

#include "Arduino.h"
#include "Blink_class.h"

void setup()
{

}

Blinkclass avaainstanssi;

void loop()
{
  avaainstanssi.blinkfunction(3000,4000);
}
