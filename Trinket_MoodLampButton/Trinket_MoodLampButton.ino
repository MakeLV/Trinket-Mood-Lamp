/*
  Trinket Mood Lamp
  A button is used to change the states of the lights
 */
 
// Pins 1, 2, and 3 have an LED connected.
// We'll give each a name:
int redLed = 1;
int greenLed = 2;
int blueLed = 4;

// Pin 3 has a button on it
int button = 3;

// These variables keep track the current 
// button and light state.
// 0 means off and 1 means on, so they start off.
int buttonState = 0;
byte lightState = 0;

// How long should we pause in milliseconds 
// 1000 == 1 second
int pause = 500;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);     
  pinMode(greenLed, OUTPUT);     
  pinMode(blueLed, OUTPUT);
  pinMode(button, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH) { //if the button state is on, turn on the lights
  
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

  } else { // if the button state is off

    // turn off lights
    digitalWrite(redLed, LOW);    // turn the Red LED off by making the voltage LOW
    digitalWrite(greenLed, LOW);    // turn the Green LED off by making the voltage LOW
    digitalWrite(blueLed, LOW);    // turn the Blue LED off by making the voltage LOW

  }
}
