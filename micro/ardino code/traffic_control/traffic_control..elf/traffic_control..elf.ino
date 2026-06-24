//PINs are defined by the corresponding LED colors 
#define GREEN_PIN 8 
#define YELLOW_PIN 10 
#define RED_PIN 12 
 
// The delay amounts are declared in ms; 1 s = 1000 ms 
int red_on = 6000; 
int green_on = 3000; 
int yellow_blink = 500; 
 
 
void setup() { 
// pin connections for the LED lights 
pinMode(GREEN_PIN, OUTPUT); 
pinMode(YELLOW_PIN, OUTPUT); 
pinMode(RED_PIN, OUTPUT); 
} 
 
 
void loop() { 
//Turning on the voltage at output pin# 8 for the green LED 
digitalWrite(GREEN_PIN, HIGH); 
delay(green_on); // delays are in ms; 1 s = 1000 ms 
//Turning off voltage at output pin# 8 for the green LED 
digitalWrite(GREEN_PIN, LOW); 
 
//Turning the yellow LED on and off 4 times 
for(int i = 0; i < 4; i = i+1) 
{ 
digitalWrite(YELLOW_PIN, HIGH); 
delay(yellow_blink); 
digitalWrite(YELLOW_PIN, LOW); 
delay(yellow_blink); 
} 
 
//Turning on the voltage at pin# 12 for the red LED 
digitalWrite(RED_PIN, HIGH); 
delay(red_on); 
//Turning off the voltage at output pin# 8 for the red LED 
digitalWrite(RED_PIN, LOW); 
 
} // void loop() function ends and repeats 
