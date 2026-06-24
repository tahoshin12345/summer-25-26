void setup() { 
// Pin type declaration for the red LED 
pinMode(5, OUTPUT); 
} 
void loop() { 
// Turning on the voltage at output pin 5 (for red LED) 
digitalWrite(5, HIGH); 
delay(1000);     //  LED is turned on for 1 second 
digitalWrite(5, LOW); 
delay(1000);     //  LED is turned off for 1 second 
} 
