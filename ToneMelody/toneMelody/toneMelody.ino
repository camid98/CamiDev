/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 7

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"
const int buzzerPin = 7;

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
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(noteDurations); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / (10-noteDurations[thisNote]);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
    // delay before the next note is played
    delay(pauseDuration[thisNote]+1);
  }
}

void loop() {
  // no need to repeat the melody.
}
