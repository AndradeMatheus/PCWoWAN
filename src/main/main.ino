#include "credentials.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "frontpanel-utils.h"
#include "connectivity-utils.h"

const int BAUD_RATE = 115200;
bool POWER_STATE_PREVIOUS = false;

void setup()
{
	Serial.begin(BAUD_RATE);
	pinMode(BUTTON_PIN, OUTPUT);
	digitalWrite(BUTTON_PIN, LOW);

	while (WiFi.begin(NET_SSID, NET_PASS) != WL_CONNECTED) {
		Serial.println("Connecting to WiFi...");
		delay(5000);
	}
	Serial.println("Connected to WiFi.");

	while (!client.connected()) {
		Serial.println("Connecting to MQTT...");
 
		if (client.connect(MQTT_CLIENT, MQTT_USER, MQTT_PASS))
			Serial.println("Connected to MQTT.");
		else {
			Serial.println((String)"Connection to MQTT failed: " + client.state());
			delay(2000);
		}
	}

	while(!getTopic(MQTT_TOPIC_BUTTON))
		delay(1000);

	POWER_STATE_PREVIOUS = getPowerState();
	while(!pushTopic(MQTT_TOPIC_STATUS, String(POWER_STATE_PREVIOUS).c_str()))
		delay(1000);

	while(!deleteTopic(MQTT_TOPIC_STATUS))
		delay(1000);
}

void loop()
{
	delay(1000);
	client.loop();

	bool powerState = getPowerState();
	if(powerState != POWER_STATE_PREVIOUS){
		POWER_STATE_PREVIOUS = powerState;
		while(!pushTopic(MQTT_TOPIC_STATUS, String(powerState).c_str()))
			delay(1000);

		while(!deleteTopic(MQTT_TOPIC_STATUS))
			delay(1000);

		while(!deleteTopic(MQTT_TOPIC_BUTTON))
			delay(1000);

		Serial.println("Topic published.");
	}
}
