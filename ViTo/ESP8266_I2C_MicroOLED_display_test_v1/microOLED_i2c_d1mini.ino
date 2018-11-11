
void paivita_naytto0(){
  oled.clear(PAGE);
  oled.setFontType(0);
  Serial.println("Font type0");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("type0"); // Print a const string
  oled.setCursor(0, 16);  // Set the text cursor to the upper-left of the screen.
  oled.print("123456789"); // Print a const string
  oled.setCursor(0, 32);  // Set the text cursor to the upper-left of the screen.
  oled.print("123456789"); // Print a const string
  oled.display();
}
void paivita_naytto1(){
  oled.clear(PAGE);
    oled.setFontType(1);
  Serial.println("Font type1");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("type1"); // Print a const string
  oled.setCursor(0, 16);
  oled.print("1234567");
  oled.setCursor(0, 32);
  oled.print("1234567");
  oled.display();
}
void paivita_naytto2(){
  oled.clear(PAGE);
    oled.setFontType(2);
  Serial.println("Font type2");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("ty 2"); // Print a const string
  oled.setCursor(0, 24);
  oled.print("12345");
  oled.display();
}
void paivita_naytto3(){
  oled.clear(PAGE);
  oled.setFontType(3);
  Serial.println("Font type3");
  oled.setCursor(0, 0);  // Set the text cursor to the upper-left of the screen.
  oled.print("t 3"); // Print a const string
  oled.display();
}

float paivita_naytto_data(String lampo, String hum){
  oled.clear(PAGE);
  oled.setFontType(1);
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

