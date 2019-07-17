//kirjastot mukaan
#include "Arduino.h"
#include "lolin_RGBled.h"


//Konstruktori alkaa, tama selittaa mita tapahtuu kun joku luo luokasta instanssin
RgbLedControl::RgbLedControl() 
{
leds.begin();
}

//Funktiot alkavat tasta
void RgbLedControl::RgbLedControlFunction(uint8 ledposition, uint8 redValue, uint8 greenValue, uint8 blueValue)
{
  leds.setPixelColor(ledposition, leds.Color(redValue, greenValue, blueValue));
  leds.show();
  serialPrintRgbLedControlFunction(ledposition, redValue, greenValue, blueValue);
  delay(1);
  }
void RgbLedControl::dummy()
{
    delay(100);
}
void RgbLedControl::serialPrintRgbLedControlFunction(uint8 ledpositionp, uint8 redValuep, uint8 greenValuep, uint8 blueValuep)
{
//  Serial.print("ledposition: redValue: greenValue: blueValue: ");
  Serial.print(ledpositionp + redValuep + greenValuep + blueValuep);
  Serial.println();
}
