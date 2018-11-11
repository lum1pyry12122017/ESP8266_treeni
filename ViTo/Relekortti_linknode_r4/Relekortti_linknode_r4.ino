/*Turn on and off the S3 relay in every second */
 void setup()
 {
   pinMode(12,OUTPUT); 
   Serial.begin(9600); 
 }
 void loop()
 {
   digitalWrite(12,HIGH);
   Serial.println("Relay ON\n");
   delay(1000);
   digitalWrite(12,LOW);
   Serial.println("Relay OFF\n");
   delay(1000);  
 }
