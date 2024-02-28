#ifndef WORDCLOCK_PING_H
#define WORDCLOCK_PING_H

#include <ESPping.h>

class Devices{
  public: 
    static void isAvailable();
    static bool available;
};

#endif