#include "lilypadPins.h"
#include "pitches.h"
#include "Music.h"

Music music(BUZZER_PIN);

// notes in the melody:
int melody[] = {
  NOTE_G2, NOTE_G2, NOTE_G2, NOTE_C3, 
  NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, 
  NOTE_C4, NOTE_G3, 
  NOTE_F3, NOTE_E3, NOTE_D3, 
  NOTE_C4, NOTE_G3, 
  NOTE_F3, NOTE_E3, NOTE_F3, NOTE_E3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 8, 
  8, 2, 2, 2, 
  8, 4, 
  2, 2, 2, 
  8, 4, 
  2, 2, 2, 8
};

int pauseDuration[] = {
  2, 2, 2, 8, 
  8, 2, 2, 2, 
  8, 4, 
  2, 2, 2, 
  8, 4, 
  2, 2, 2, 8
};

void setup() {
  pinMode(WHITE_1, OUTPUT);
  pinMode(WHITE_2, OUTPUT);
  pinMode(WHITE_3, OUTPUT);
  pinMode(WHITE_4, OUTPUT);
  pinMode(WHITE_5, OUTPUT); 
  Serial.begin(9600);      // open the serial port at 9600 bps: 
  Serial.print("before music");
  music.playOnce();
  Serial.print("music done");
}


void loop() {
  // put your main code here, to run repeatedly:

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
  
  delay(timeDelay);
}
