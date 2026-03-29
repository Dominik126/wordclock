#include <ESP8266WiFi.h>
//#include <WiFiManager.h>

#include "wifi.h"

void Wifi::setup() {
  WiFi.hostname("WordClock");
 // WiFi.mode(WIFI_STA);

 // WiFiManager wifiManager;
 // wifiManager.autoConnect("WordClock");
 
 const char* ssid     = "Sesamstrasse";
 const char* password = "xN3AbS7@JYa43%";
 
 IPAddress local_IP(192,168,178,8);
 IPAddress gateway(192,168,178,1);
 IPAddress subnet(255,255,255,0);
 IPAddress primDNS(192,168,178,1);
 IPAddress secDNS(8,8,8,8);
 
 if (!WiFi.config(local_IP, gateway, subnet, primDNS, secDNS) ){
	 Serial.println("IP settings failed to configure");
 }
 
 //Connect
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
 }
 // Print local IP address and start web server
 Serial.println("");
 Serial.println("WiFi connected.");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 
}

void Wifi::reset() {
  WiFi.disconnect(true);
}
