#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "credentials.h"

//Front panel
const int BUTTON_PIN = 4;
const int LED_PIN = A0;

//Wi-Fi
WiFiClient espClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//MQTT Broker
PubSubClient client(MQTT_SERVER, MQTT_PORT, espClient);

//Set-time to update
const int UPDATE_POWER_STATE = 15; // Change to how many seconds you want it to push to the MQTT topic
int CYCLE = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_PIN, OUTPUT);

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
      Serial.print("Connection to MQTT failed: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void loop()
{
	delay(1000);
	client.loop();
	bool powerState = getPowerState();

	if(CYCLE == UPDATE_POWER_STATE){
		CYCLE = 0;
		bool mqttClientResponse = updateTopic(MQTT_TOPIC_STATUS, String(powerState).c_str());
		Serial.println(mqttClientResponse ? "Topic published." : "Error on publish.");
	}
	else CYCLE++;
}

void pushButton(int delayAmmount){
	digitalWrite(BUTTON_PIN, HIGH);
  Serial.println(">>> Button is 1? -" + String(digitalRead(BUTTON_PIN)));
  delay(delayAmmount);
  digitalWrite(BUTTON_PIN, LOW);
  Serial.println("<<< Button is 0? -" + String(digitalRead(BUTTON_PIN)));
}

bool getPowerState(){
 	float power = analogRead(LED_PIN);
  Serial.println("POWER VALUE: " + String(power));
	Serial.println("!!! Power is " + String(power > 100 ? "ON" : "OFF"));
  return power > 100 ? true : false;
}

bool updateTopic(const char *topic, const char *content){
	Serial.print("Sending message to MQTT topic: ");
  Serial.println(topic);
  Serial.print("With content: ");
  Serial.println(content);

	return client.publish(topic, content);
}
