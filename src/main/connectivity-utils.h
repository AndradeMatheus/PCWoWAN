//Wi-Fi
WiFiClient espClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//MQTT Broker
void getMessage(char* topic, byte* payload, unsigned int length);
PubSubClient client(MQTT_SERVER, MQTT_PORT, getMessage, espClient);

bool pushTopic(const char *topic, const char *content){
	Serial.print("Sending message to MQTT topic: ");
  Serial.println(topic);
  Serial.print("With content: ");
  Serial.println(content);

	return client.publish(topic, content);
}

bool getTopic(const char *topic){
  Serial.print("Subscribing to MQTT topic: ");
  Serial.println(topic);

  return (int)client.subscribe(topic);
}

void getMessage(char* topic, byte* payload, unsigned int length) {
  char *p = reinterpret_cast<char*>(payload);
  Serial.print("PAYLOAD: ");
  Serial.print(p);
  Serial.print(" - FROM: ");
  Serial.println(topic);
}