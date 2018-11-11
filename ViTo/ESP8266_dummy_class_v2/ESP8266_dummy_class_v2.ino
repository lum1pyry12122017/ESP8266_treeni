/*kaantyy 16.10.2018*/

#include "Arduino.h"
#include "dummy.h"

void setup() {
Serial.begin(9600);

}
//Dummyclass control(); ei saa käyttää sulkuja jos luokka ei ota parametreja
Dummyclass control;

void loop()
{
  control.dummyfunction();
}
  
 
