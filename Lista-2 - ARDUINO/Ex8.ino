String temp;

void setup() {

    Serial.begin(9600);

}

void loop() {

    temp = String(map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125));

    Serial.println("A temperatura e: " + temp);

}