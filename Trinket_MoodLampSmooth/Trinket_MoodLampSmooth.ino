//Adapted from: http://forum.arduino.cc/index.php/topic,11293.0.html

float RGB1[3];
float RGB2[3];
float INC[3];

int red, green, blue;

int redLed = 0;
int greenLed = 1;
int blueLed = 4;

 
void setup_smooth_colors() 
{ 

  randomSeed(analogRead(0));
  
  for (int x=0; x<3; x++) {
    RGB1[x] = random(256);
    RGB2[x] = random(256); 
  } 

} 
 
void smooth_colors() 
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
