const int BUTTON_PIN = D1;
const int LED_PIN = A0;

void pushButton(int delayAmmount){
	digitalWrite(BUTTON_PIN, HIGH);
  Serial.println((String)">>> Button is 1? - " + digitalRead(BUTTON_PIN) + " Delay: " + delayAmmount);
  delay(delayAmmount * 1000);
  digitalWrite(BUTTON_PIN, LOW);
  Serial.println((String)"<<< Button is 0? - " + digitalRead(BUTTON_PIN));
}

bool getPowerState(){
 	float power = analogRead(LED_PIN);
  Serial.println("POWER ADC VALUE: " + String(power));
	Serial.println("!!! Power is " + String(power > 100 ? "ON" : "OFF"));
  return power > 100 ? true : false;
}
