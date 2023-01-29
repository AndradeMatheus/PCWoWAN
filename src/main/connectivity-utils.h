//Wi-Fi
WiFiClient espClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//TODO: Implement token generation from USER_PK
const char * getToken(){
	timeClient.begin();
	//temporarily using PK as token
	return USER_PK;
}

//MQTT Broker
void getMessage(char* topic, byte* payload, unsigned int length);
PubSubClient client(MQTT_SERVER, MQTT_PORT, getMessage, espClient);

bool pushTopic(const char *topic, const char *content){
	Serial.println((String)"Sending message to MQTT topic: " + topic + " - With content: " + content);

	return client.publish(topic, content);
}

bool getTopic(const char *topic){
	Serial.println((String)"Subscribing to MQTT topic: " + topic);

	return (int)client.subscribe(topic);
}

void getMessage(char* topic, byte* payload, unsigned int length) {
	char *payloadFormatted = reinterpret_cast<char*>(payload);
	Serial.println((String)"PAYLOAD: " + payloadFormatted + " - FROM: " + topic);

	const char *payloadDelay = strtok(payloadFormatted, ";");
	const char *payloadToken = strtok(NULL, ";");

	if(String(payloadToken) == String(getToken()))
		pushButton(String(payloadDelay).toInt());
}
