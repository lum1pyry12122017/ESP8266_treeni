//Toimii 8.8.2018
//Switch ON in APP,, will turn status of real LED on ESP8266
//https://community.blynk.cc/t/basic-physical-led-control-via-blynk/22320/12

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "aca0dd3d64c140a18d0a98375fed6f05";
char ssid[] = "241385";
char pass[] = "112233445566";

BLYNK_WRITE(V11)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1) {                 // If value is 1 run this command
    digitalWrite(D7, HIGH);          //D1 output from Wemos D1 mini
  }
  else {                                     // If value is 0 run this command
    digitalWrite(D7, LOW);          //D1 output from Wemos D1 mini
  }
  Serial.print("V1 Button value is: ");
  Serial.println(pinValue);
}

void setup()
{
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);
  pinMode(D7, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  }

void loop()
{
  Blynk.run();
}
