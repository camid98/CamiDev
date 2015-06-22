#ifndef Music_h
#define Music_h

#include "Arduino.h"

class Music
{
  public:
    Music(int pin);
    void playOnce();
    void playRepeat(int numberTimes);
  private:
    int _pin;
};

#endif
