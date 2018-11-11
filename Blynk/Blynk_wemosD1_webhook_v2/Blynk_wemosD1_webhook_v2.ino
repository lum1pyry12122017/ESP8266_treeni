//Toimii
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to fetch data using WebHook GET method

  App project setup:
    WebHook widget on V0, method: GET, url: /pin/
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
// Allow for receiving messages up to 512 bytes long
#define BLYNK_MAX_READBYTES 1024

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "aca0dd3d64c140a18d0a98375fed6f05";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "241385";
char pass[] = "112233445566";

BLYNK_WRITE(V0)
{
  Serial.println("WebHook data:");
  Serial.println(param.asStr());
}

BLYNK_WRITE(V1)
{
  if(param.asInt()){
    //Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V0, "raw.githubusercontent.com/blynkkk/blynk-library/master/extras/logo.txt");  
  }
}
void setup()
{
  // Debug console
  Serial.begin(9600);

  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);

  Blynk.virtualWrite(V0, "https://raw.githubusercontent.com/blynkkk/blynk-library/master/extras/logo.txt");

  // You can perform HTTPS requests even if your hardware alone can't handle SSL
  // Blynk  can also fetch much bigger messages,
  // if hardware has enough RAM (set BLYNK_MAX_READBYTES to 4096)
  //Blynk.virtualWrite(V0, "https://api.sunrise-sunset.org/json?lat=50.4495484&lng=30.5253873&date=2016-10-01");
}

void loop()
{
  Blynk.run();
}
