float bits = 0;

void setup() {

    Serial.begin(9600);

}

void loop() {

    bits = analogRead(A0);
    Serial.println(bits);

}