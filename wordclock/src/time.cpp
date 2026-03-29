#include <Arduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#include "time.h"
#include "grid.h"
#include "utcOffset.h"
#include "temperature.h"
#include "ping.h"

void Time::setup() {
  Time::ntpClient.begin();
  Time::ntpClient.update();
}

void Time::loop() {
  Time::ntpClient.update();

  int h = Time::ntpClient.getHours();
  int m = Time::ntpClient.getMinutes();
  int s = Time::ntpClient.getSeconds();
  
  if (s!= Time::second){
	Time::second = s;
	//Serial.print(DhtValues::temp);  Serial.print("°C ");
	//Serial.print(DhtValues::humi);  Serial.println("%");
	Grid::setTime(Time::hour, Time::minute);
  }

  if((m != Time::minute) ){
    if(m == 0 && h == Time::hour) {
      h = (h + 1) % 24;
    }

    Time::hour = h;
    Time::minute = m;
    Grid::setTime(Time::hour, Time::minute);

    if (Config::automatic_timezone) {
      UtcOffset::updateLocalizedUtcOffset();
      Time::ntpClient.setTimeOffset(Config::timezone);
    }
	
	DhtValues::loop();
	
	Devices::isAvailable();
	//Serial.println(Devices::available);
  }
}

int Time::hour = -1;
int Time::minute = -1;
int Time::second = -1;
WiFiUDP Time::udp;
NTPClient Time::ntpClient = NTPClient(Time::udp);
