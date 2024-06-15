int led = 9;

float bits = 0;

String inputState;

void setup() {

    pinMode(led, OUTPUT);
    Serial.begin(9600);

}

void loop() {

    bits = analogRead(A0) / 4;

    analogWrite(led, bits);

    inputState = String(bits);
    Serial.println("LED: " + inputState);

}