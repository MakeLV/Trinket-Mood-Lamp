/*
  Trinket Mood Lamp
  Pulsing and fading the lights  
 */
 
// Pins 1, 2, and 3 have an LED connected.
// We will give each a name
const int redLed = 1;
const int greenLed = 2;
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
  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);     
  pinMode(greenLed, OUTPUT);     
  pinMode(blueLed, OUTPUT);
  pinMode(button, INPUT);
  
  // initialize pin 4's PWM capability
  pwm4_init();
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH) { //if the button state is on, pulse the lights

    float in, out;
  
    for (in = 0; in < 6.283; in = in + 0.001)
    {
      out = sin(in) * 127.5 + 127.5;
      analogWrite(redLed,out);
    }

    delay(pause);

    for (in = 0; in < 6.283; in = in + 0.001)
    {
      out = sin(in) * 127.5 + 127.5;
      analogWrite(greenLed,out);
    }

    delay(pause);

    for (in = 0; in < 6.283; in = in + 0.001)
    {
      out = sin(in) * 127.5 + 127.5;
      analogWrite4(blueLed,out);
    }

  } else { // if the button state is off

    // turn off lights
    digitalWrite(redLed, LOW);    // turn the Red LED off by making the voltage LOW
    digitalWrite(greenLed, LOW);    // turn the Green LED off by making the voltage LOW
    digitalWrite(blueLed, LOW);    // turn the Blue LED off by making the voltage LOW

  }
}

void PWM4_init() {
// Set up PWM on Trinket GPIO #4 (PB4, pin 3) using Timer 1
TCCR1 = _BV (CS10); // no prescaler
GTCCR = _BV (COM1B1) | _BV (PWM1B); // clear OC1B on compare
OCR1B = 127; // duty cycle initialize to 50%
OCR1C = 255; // frequency
}

// Function to allow analogWrite on Trinket GPIO #4
void analogWrite4(uint8_t duty_value) {
OCR1B = duty_value; // duty may be 0 to 255 (0 to 100%)
}
