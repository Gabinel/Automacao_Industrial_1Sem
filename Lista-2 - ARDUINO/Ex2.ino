int led = 3;
String ledState;

void setup() {

    pinMode(led, OUTPUT);
    Serial.begin(9600);

}

void loop() {

    for(int i = 0; i <= 255; i++){
        analogWrite(led, i);
        ledState = String(i);
        Serial.println("LED: " + ledState);
        delay(500 / 256);
    }

    for(int i = 255; i >= 0; i--){
        analogWrite(led, i);
      	ledState = String(i);
        Serial.println("LED: " + ledState);
        delay(500 / 256);
    }

}