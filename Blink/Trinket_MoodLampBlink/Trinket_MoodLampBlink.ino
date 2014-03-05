/*
  Trinket Mood Lamp
  Cycles through three LEDs 
 */
 
// Pins 1, 2, and 3 have an LED connected.
// We'll give each a name:
int redLed = 1;
int greenLed = 2;
int blueLed = 3;

int pause = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);     
  pinMode(greenLed, OUTPUT);     
  pinMode(blueLed, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(redLed, HIGH);   // turn the Red LED on (HIGH is the voltage level)
  delay(pause);               // wait for a second
  digitalWrite(redLed, LOW);    // turn the Red LED off by making the voltage LOW
  delay(pause);               // wait for a second
  
  digitalWrite(greenLed, HIGH);   // turn the Green LED on (HIGH is the voltage level)
  delay(pause);               // wait for a second
  digitalWrite(greenLed, LOW);    // turn the Green LED off by making the voltage LOW
  delay(pause);               // wait for a second
  
  digitalWrite(blueLed, HIGH);   // turn the Blue LED on (HIGH is the voltage level)
  delay(pause);               // wait for a second
  digitalWrite(blueLed, LOW);    // turn the Blue LED off by making the voltage LOW
  delay(pause);               // wait for a second
}
