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
  Serial.print("RgbLedControl: ");
  Serial.println(ledposition);
/*  Serial.println(redValue);
  Serial.println(greenValue);
  Serial.println(blueValue);
  */
  leds.setPixelColor(ledposition, leds.Color(redValue, greenValue, blueValue));
  leds.show();
//  serialPrintRgbLedControlFunction(ledposition, redValue, greenValue, blueValue);
  delay(1);
  }


/*void RgbLedControl::RgbLedControlFunction(uint8 ledposition, uint8 redValue, uint8 greenValue, uint8 blueValue)
{
int R;
int G;
int B;
BLYNK_WRITE(V21)
{
int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
/*Serial.println(R);
//Serial.println(G);
//Serial.println(B);

//for(int i=0;i<NUMPIXELS;i++){

//pixels.setPixelColor(i, pixels.Color(R,G,B));

//pixels.show();
}

 }
 
int lednumber;
BLYNK_WRITE(V22)
{
int lednumber = param[0].asInt();
Serial.print("lednumber: ");
Serial.println(lednumber);
}  
  
  leds.setPixelColor(lednumber, leds.Color(R, G, B));
  leds.show();
  }
*/
void RgbLedControl::dummy()
{
  Serial.print("Dummy");
  Serial.println();
  delay(100);
}
void RgbLedControl::serialPrintRgbLedControlFunction(uint8 ledpositionp, uint8 redValuep, uint8 greenValuep, uint8 blueValuep)
{
//  Serial.print("ledposition: redValue: greenValue: blueValue: ");
  Serial.print(ledpositionp + redValuep + greenValuep + blueValuep);
  Serial.println();
}
