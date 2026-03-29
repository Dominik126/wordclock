#ifndef WORDCLOCK_TEMPERATURE_H
#define WORDCLOCK_TEMPERATURE_H

#include <DHT.h>
#include <espnow.h>

typedef struct dht_message{
  int8_t id;
  float temp;
  float humi;
} dht_message;

class DhtValues {
  public:
	static float temp;
	static float humi;
	
    static void setup();
    static void loop();
};

#endif