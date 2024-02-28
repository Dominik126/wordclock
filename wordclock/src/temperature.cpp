#include "config.h"
#include "temperature.h"

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void DhtValues::setup() {
	dht_sensor.begin();
}

void DhtValues::loop() {
	DhtValues::temp = dht_sensor.readTemperature();
	DhtValues::humi = dht_sensor.readHumidity();
}

float DhtValues::temp = -1;
float DhtValues::humi = -1;