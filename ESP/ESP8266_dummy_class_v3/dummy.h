#ifndef dummy
#define dummy

#include "Arduino.h"

class Dummyclass {
  
unsigned long luokkaSleeptime;

public:

  Dummyclass();
  void dummyfunction();
  void sleepfunction(unsigned long functioSleeptime);
};
#endif
