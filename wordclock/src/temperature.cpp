#include "config.h"
#include "temperature.h"

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
uint8_t loggerAddress[] = {0xC8, 0xC9, 0xA3, 0x10, 0x95, 0xBE};

void OnDataSent(uint8_t *mac, uint8_t status){
	if (status != 0){
		Serial.println("Delivery failed: " + String(status));
	}
}

void DhtValues::setup() {
	dht_sensor.begin();
	
	 // Init ESP-NOW
	 if (esp_now_init() != 0) {
		Serial.println("Error initializing ESP-NOW");
		return;
	 }
	 
	 // Once ESPNow is successfully Init, we will register for Send CB to
	 // get the status of Trasnmitted packet
	 esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
	 esp_now_register_send_cb(OnDataSent);
	  
	 // Register peer
	 esp_now_add_peer(loggerAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

dht_message dhtData;

void DhtValues::loop() {
	DhtValues::temp = dht_sensor.readTemperature();
	DhtValues::humi = dht_sensor.readHumidity();
	
	dhtData.id = 1;
	dhtData.temp = (DhtValues::temp);
	dhtData.humi = (DhtValues::humi);
	
/*	uint8_t debugData[sizeof(dht_message)+1];
	memcpy(&debugData, &dhtData, sizeof(dht_message));
	for (int i=0; i< sizeof(dht_message); i++) {Serial.print(debugData[i]);} Serial.println();
	
	
	Serial.println(String(dhtData.id) + " ; " + String(dhtData.temp) + " ; " + String(dhtData.humi) );*/
	
	int result = esp_now_send(loggerAddress, (uint8_t *) &dhtData, sizeof(dht_message));
	if (result != 0) {
		Serial.println("Error sending: " + String(result));
	}
}

float DhtValues::temp = -1;
float DhtValues::humi = -1;