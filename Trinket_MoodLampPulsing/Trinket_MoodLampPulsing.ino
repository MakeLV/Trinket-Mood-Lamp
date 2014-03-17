/*
  Trinket Mood Lamp
  Pulsing and fading the lights
  
  Make Lehigh Valley
 */
 
// Pins 0, 1, and 4 have an LED connected.
// We will give each a name cooresponding to the color
const int redLed = 0;
const int greenLed = 1;
const int blueLed = 4;

// Pin 3 is an off button
const int offbutton = 3;

// Pin 2 is a mode button
const int modebutton = 2;

// This variable tracks what the current mode is
int mode = 1;

// How long should we pause in milliseconds 
// 1000 == 1 second
int pause = 500;

// the setup routine runs once when you press reset
void setup() {                
  // initialize pin 4's PWM capability
  PWM4_init();

  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);     
  pinMode(greenLed, OUTPUT);     
  pinMode(blueLed, OUTPUT);

  // initialize the buttons as inputs.
  pinMode(offbutton, INPUT);
  pinMode(modebutton, INPUT);
  
  // Turn all the LEDs off to start
  analogWr(redLed, 0);
  analogWr(greenLed, 0);
  analogWr(blueLed, 0);
}

// the loop routine runs over and over again forever
void loop() {
  
  // if the mode button is on, add one to the mode
  if (digitalRead(modebutton) == LOW) { 
    mode = mode + 1;
  }

  //if the off button is on, run the lights otherwise turn them off.
  if (digitalRead(offbutton) == HIGH) { 

    // Detect what mode we are currently in and run cooresponding code
    switch (mode) {
      case 1:
        // pulse each LED, one at a time
        pulse(redLed);
        pulse(greenLed);
        pulse(blueLed);
      case 2:
        //blink each LED for "pause" milliseconds
        digitalWrite(redLed, HIGH);
        delay(pause);
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        delay(pause);
        digitalWrite(greenLed, LOW);
        digitalWrite(blueLed, HIGH);
        delay(pause);
        digitalWrite(blueLed, LOW);
      default:
        // if no other option is selected above, set it the mode to 1
        mode = 1;
    }
    
  } else { // if the button state is off

    // turn off lights
    digitalWrite(redLed, LOW);    // turn the Red LED off by making the voltage LOW
    digitalWrite(greenLed, LOW);    // turn the Green LED off by making the voltage LOW
    digitalWrite(blueLed, LOW);    // turn the Blue LED off by making the voltage LOW

  }
}

// Pulse an LED using a sin wave cause it's pretty 
void pulse(int pin) {
  float in,out;
  
  for (in = 1.5; in < 7.8; in = in + 0.001) 
  {
    out = sin(in) * 127.5 + 127.5;
    out = -(out - 255);
    analogWr(pin,out);
  }
}

// Set up PWM on Trinket GPIO #4 (PB4, pin 3) using Timer 1
void PWM4_init() {
TCCR1 = _BV (CS10); // no prescaler
GTCCR = _BV (COM1B1) | _BV (PWM1B); // clear OC1B on compare
OCR1B = 127; // duty cycle initialize to 50%
OCR1C = 255; // frequency
}

// A single function to handle PWM any pin
void analogWr(int pin, uint8_t value) {
  if (pin == 4) { 
    OCR1B = value; // The PWM duty value between 0 and 255 (0 to 100%)
 } else {
    analogWrite(pin, value);
 }
}
