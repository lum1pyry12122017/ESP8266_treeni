//https://randomnerdtutorials.com/esp8266-0-96-inch-oled-display-with-arduino-ide/


void displayTempHumid(){
/*  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "Failed DHT");
    return;
  }
  */
  Serial.println(" displayTempHumid ");
  display.clear();
  display.drawString(0, 0, "Humidity: " + String(h12) + "%\t"); 
  display.drawString(0, 16, "Temp: " + String(t12) + "C"); 
//  display.drawString(0, 32, "Temp: " + String(f) + "F"); 
}

