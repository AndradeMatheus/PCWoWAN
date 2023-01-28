//Wi-Fi
const char *NET_SSID = ""; //Your WiFi SSID name
const char *NET_PASS = ""; //Your WiFi password

//MQTT
const char *MQTT_SERVER = ""; //Your MQTT broker URL
const int MQTT_PORT = 1883; //Your MQTT broker PORT
const char *MQTT_CLIENT = ""; //Your MQTT client id, can be any identifier you like
const char *MQTT_USER = ""; //Your MQTT broker user
const char *MQTT_PASS = ""; //Your MQTT broker password
const char *MQTT_TOPIC_STATUS = ""; //Topic to watch over the PC's power state
const char *MQTT_TOPIC_BUTTON = ""; //Topic to change the PC's power state

//Client Custom Private-key
const char *USER_PK = ""; //PK for Token Guard generated (same as the mobile app)
