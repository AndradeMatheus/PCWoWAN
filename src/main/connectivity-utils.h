//Wi-Fi
WiFiClient espClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

const char * getToken(){
    timeClient.begin();
    //temp
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
  char *p = reinterpret_cast<char*>(payload);
  Serial.println((String)"PAYLOAD: " + p + " - FROM: " + topic);

  const char *value = strtok(p, ";");
  const char *tokenReceived = strtok(NULL, ";");

  Serial.println((String)"VALUE: " + value + " - TOKEN: " + tokenReceived);

  const char *token = getToken();

  if(token == getToken())
    pushButton(String(value).toInt());
}
