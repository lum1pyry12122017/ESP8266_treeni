//Toimii 25.07.2019 Wemos D1 ja BMP180 shield
//source https://community.blynk.cc/t/bmp180-with-nodemcu/10837/8

#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

//#include <BH1750.h>  // https://github.com/claws/BH1750
//BH1750 lightMeter;

char ssid[] = "241385";
char pass[] = "112233445566";
char auth[] = "-iURIcNaAq8MfGtSCbfcc_ShqFMKNj9U";  // Put your Auth Token here. (see Step 3 above)

SimpleTimer timer;

//#define I2C_SCL 12      // D6  Barometric Pressure Sensor (BMP085)
//#define I2C_SDA 13      // D7
Adafruit_BMP085 bmp;

float dst, bt, bp, ba;
char dstmp[20], btmp[20], bprs[20], balt[20];
bool bmp085_present = true;

void setup()
{
  WiFi.mode(WIFI_STA);
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);
//  Wire.begin(I2C_SDA, I2C_SCL);
  delay(10);
  
  if (!bmp.begin()) 
  {
      Serial.println("Could not find a valid BMP085 sensor, check wiring!");
      //while (1) {}
  }

  timer.setInterval(100000L, sendWifi);
  timer.setInterval(20000L, sendUptime);
//  lightMeter.begin();


}


void sendWifi() 
{
  Blynk.virtualWrite(1, map(WiFi.RSSI(), -105, -40, 0, 100) );
}



void sendUptime()
//  uint16_t lux = lightMeter.readLightLevel();
//  Blynk.virtualWrite(4, lux);

{

  float bp =  bmp.readPressure()/1;
  Blynk.virtualWrite(9, bp); // virtual pin

  float ba =  bmp.readAltitude();
  Blynk.virtualWrite(7, ba); // virtual pin

  float bt =  bmp.readTemperature();
  Blynk.virtualWrite(12, bt); // virtual pin

  float dst =  bmp.readSealevelPressure(529)/100;
  Blynk.virtualWrite(13, dst); // virtual pin

}

void loop()
{
  Blynk.run();
  timer.run();
}
