//toimii 30.08.2018
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "aca0dd3d64c140a18d0a98375fed6f05";
char ssid[] = "241385";
char pass[] = "112233445566";
int prevState = -1;
int currState = -1;
int LEDbrightness = 127;
long lastChangeTime = 0;

BLYNK_WRITE(V11)
{
  int pinValue = param.asInt();             // assigning incoming value from pin V1 to a variable
  if (pinValue == 1) {                      // If value is 1 run this command
    digitalWrite(D7, HIGH);                 //D7 output from Wemos D1 mini HIGH
    Serial.print("V1 Button value is: ");   //Print to serial port
    Serial.println(pinValue);               //Print to serial port
  }
  else {                                    // If value is 0 run this command
    digitalWrite(D7, LOW);                  //D7 output from Wemos D1 mini LOW
    Serial.print("V1 Button value is: ");   //Print to serial port
    Serial.println(pinValue);               //Print to serial port
  }
}

void checkPin()
{
  int state = !digitalRead(D3);       // Invert state, since button is "Active LOW"
  long t = millis();                  // Debounce mechanism
  if (state != prevState) {
    lastChangeTime = t;
  }
  if (t - lastChangeTime > 50) {
    if (state != currState) {
      currState = state;
        if (currState = 1){
          Blynk.virtualWrite(V12, LEDbrightness);
          Serial.print("kytkin 1");
          Serial.print("lastChangeTime: ");
          Serial.println(lastChangeTime);

        }
        else {
          Blynk.virtualWrite(V12, 0);
          Serial.print("kytkin 0");
          Serial.print("lastChangeTime: ");
          Serial.println(lastChangeTime);
              }
        }
    }
  currState = state;
}

void virtualledstatus()
{
  if (currState > 0) {
    Blynk.virtualWrite(V12, LEDbrightness);
    Serial.println("led 1");
    }
  else {
    Blynk.virtualWrite(V12, 0);
    Serial.println("led 0");
    }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, IPAddress(95,179,135,52), 8080);
  pinMode(D3, INPUT_PULLUP);          // Make pin D3 default HIGH and input
  pinMode(D7, OUTPUT);                // Initialize the D7 pin as an output
}

void loop()
{
  Blynk.run();
  checkPin();
  virtualledstatus();
  delay(1000);                          //poista delay
}

//TODO
//debounce kirjasto
//Fastled kirjasto RGB ledille
//Functiot ja asetukset erilliseen tiedostoon
//Deep sleep
//real time clock ja NTP
