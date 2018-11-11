
float paivita_naytto_data(String lampo, String hum){
  oled.clear(PAGE);
  oled.setFontType(1);
  //Serial.print(lampo);
  oled.setCursor(10, 0);
  oled.print(lampo);
  oled.setCursor(10, 24);
  oled.print(hum);
  oled.display();
}
void welcome(){
  oled.clear(PAGE);
    oled.setFontType(1);
  Serial.println("Font type1");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print(" Peace"); // Print a const string
  oled.setCursor(0, 16);
  oled.print("   &   ");
  oled.setCursor(0, 32);
  oled.print("  Love");
  oled.display();
}

