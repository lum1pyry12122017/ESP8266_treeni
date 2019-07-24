#include "Blink_class.h"

Blinkclass::Blinkclass() 
{
  pinMode(LED_BUILTIN, OUTPUT);

}

void Blinkclass::blinkfunction(int onnn, int offf)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(offf);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(onnn);
}

