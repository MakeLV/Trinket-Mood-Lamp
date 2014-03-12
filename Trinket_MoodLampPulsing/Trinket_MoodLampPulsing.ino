/*
  Trinket Mood Lamp
  Pulsing and fading the lights  
 */
 
// Pins 1, 2, and 3 have an LED connected.
// We will give each a name
const int redLed = 0;
const int greenLed = 1;
const int blueLed = 4;

// Pin 3 has a button on it
const int button = 3;

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
  // initialize pin 4's PWM capability
  PWM4_init();

  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);     
  pinMode(greenLed, OUTPUT);     
  pinMode(blueLed, OUTPUT);
  pinMode(button, INPUT);
  analogWr(redLed, 0);
  analogWr(greenLed, 0);
  analogWr(blueLed, 0);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH) { //if the button state is on, pulse the lights

    pulse(redLed);
    pulse(greenLed);
    pulse(blueLed);

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
  
  for (in = 0; in < 6.283; in = in + 0.001)
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
