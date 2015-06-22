#include "lilypad_pins.h"

int current_r = 0;
int current_g = 0;
int current_b = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(WHITE_1, OUTPUT);
  pinMode(WHITE_2, OUTPUT);
  pinMode(WHITE_3, OUTPUT);
  pinMode(WHITE_4, OUTPUT);
  pinMode(WHITE_5, OUTPUT); 
  Serial.begin(9600);      // open the serial port at 9600 bps: 
}

// the loop function runs over and over again forever
void loop() {
  int new_r = random(0, 255);
  int new_g = random(0, 255);
  int new_b = random(0, 255);
  
  rgbLED(0, 0, 255, 100);
  Serial.print("Hello there");
  delay(1000);
}

void lightLED(int pin, bool isOn, int delayTime)
{
  if(isOn)
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
   else // is off
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);              // wait for a second
}

void rgbLED(int r, int g, int b, int timeDelay)
{
  analogWrite(RGB_LED_RED, 255 - r);
  analogWrite(RGB_LED_GREEN, 255 - g);
  analogWrite(RGB_LED_BLUE, 255 - b);
  current_r = r;
  current_g = g;
  current_b = b;
  
  delay(timeDelay);
}

void fadeRGBLED(int new_r, int new_g, int new_b, int timeToNew)
{
  int diff_r = abs(new_r - current_r);
  int diff_g = abs(new_g - current_g);
  int diff_b = abs(new_b - current_b);
  
  int dir_r =  diff_r > 0 ? 1:-1;
  int dir_g =  diff_b > 0 ? 1:-1;
  int dir_b =  diff_b > 0 ? 1:-1;
  
  int speed_r = diff_r/timeToNew;
  int speed_g = diff_g/timeToNew;
  int speed_b = diff_b/timeToNew;
  
  for(; current_r == new_r; current_r += dir_r)
  {
    rgbLED(current_r, current_g, current_b, 50);
    current_g += dir_g;
    current_b += dir_b;
  }
}
