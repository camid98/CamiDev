#include "Arduino.h"
#include "Music.h"
#include "pitches.h"

Music::Music(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Music::playOnce()
{
  tone(_pin, NOTE_G2, 1000);
  Serial.print("Note playing");
  Serial.print(_pin);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    delay(1000);
    // stop the tone playing:
    noTone(_pin);
    // delay before the next note is played
    delay(100);
}

void Music::playRepeat(int numberTimes)
{
}
