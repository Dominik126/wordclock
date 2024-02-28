#ifndef WORDCLOCK_TEMPERATURE_H
#define WORDCLOCK_TEMPERATURE_H

#include <DHT.h>

class DhtValues {
  public:
	static float temp;
	static float humi;
	
    static void setup();
    static void loop();
};

#endif