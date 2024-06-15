String ledState;

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

}

void loop() {

    digitalWrite(LED_BUILTIN, HIGH);
  	ledState = String(digitalRead(LED_BUILTIN));
    Serial.println("LED: " + ledState);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
  	ledState = String(digitalRead(LED_BUILTIN));
    Serial.println("LED: " + ledState);
    delay(1000);

}