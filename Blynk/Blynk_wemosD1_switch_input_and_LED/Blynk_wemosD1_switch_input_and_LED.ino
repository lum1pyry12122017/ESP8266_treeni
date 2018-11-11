//Toimii 28.8.2018
//https://community.blynk.cc/t/read-switch-state-on-input-pin-using-blynk/6201/5
#define BLYNK_PRINT Serial
//#include <SPI.h>
//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "aca0dd3d64c140a18d0a98375fed6f05";
char ssid[] = "241385";
char pass[] = "112233445566";

void setup()
{
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);

  // Make pin D3 default HIGH, and attach INT to our handler
  pinMode(D3, INPUT_PULLUP);
}

int prevState = -1;
int currState = -1;
long lastChangeTime = 0;

void checkPin()
{
  // Invert state, since button is "Active LOW"
  int state = !digitalRead(D3);

  // Debounce mechanism
  long t = millis();
  if (state != prevState) {
    lastChangeTime = t;
  }
  if (t - lastChangeTime > 50) {
    if (state != currState) {
      currState = state;
      Blynk.virtualWrite(V12, state);
    }
  }
  Serial.print("prevState: ");
  Serial.println(prevState);
  Serial.print("currState: ");
  Serial.println(currState);
  prevState = state;

}

void loop()
{
  Blynk.run();
  checkPin();
}
