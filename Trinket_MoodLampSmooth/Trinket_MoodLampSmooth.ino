//Adapted from: http://forum.arduino.cc/index.php/topic,11293.0.html

float RGB1[3];
float RGB2[3];
float INC[3];

int red, green, blue;

int redLed = 0;
int greenLed = 1;
int blueLed = 4;


void setup() 
{ 

  // initialize pin 4's PWM capability
  PWM4_init();

  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  analogWr(redLed, 0);
  analogWr(greenLed, 0);
  analogWr(blueLed, 0);

  randomSeed(analogRead(0));
  
  for (int x=0; x<3; x++) {
    RGB1[x] = random(256);
    RGB2[x] = random(256); 
  } 

} 
 
void loop() 
{ 
  randomSeed(analogRead(0));
  
  for (int x=0; x<3; x++) {
    INC[x] = (RGB1[x] - RGB2[x]) / 256; } 
  
  for (int x=0; x<256; x++) {
    
    red = int(RGB1[0]);
    green = int(RGB1[1]);
    blue = int(RGB1[2]);

    analogWr (redLed, red);  
    analogWr (greenLed, green);   
    analogWr (blueLed, blue);     
    delay(250);   

    for (int x=0; x<3; x++) {
         RGB1[x] -= INC[x];}
 
  }
  
  for (int x=0; x<3; x++) {
  RGB2[x] = random(956)-700;
  RGB2[x] = constrain(RGB2[x], 0, 255); 
  
  delay(1000);
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
