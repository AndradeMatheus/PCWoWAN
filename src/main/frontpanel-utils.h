const int BUTTON_PIN = 0;
const int LED_PIN = A0;

void pushButton(int delayAmmount){
	digitalWrite(BUTTON_PIN, HIGH);
  Serial.println(">>> Button is 1? -" + String(digitalRead(BUTTON_PIN)));
  delay(delayAmmount * 1000);
  digitalWrite(BUTTON_PIN, LOW);
  Serial.println("<<< Button is 0? -" + String(digitalRead(BUTTON_PIN)));
}

bool getPowerState(){
 	float power = analogRead(LED_PIN);
  Serial.println("POWER ADC VALUE: " + String(power));
	Serial.println("!!! Power is " + String(power > 100 ? "ON" : "OFF"));
  return power > 100 ? true : false;
}
