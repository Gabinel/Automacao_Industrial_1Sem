int led = 8;
int bits, valor;

String text;

void setup() {

    pinMode(led, OUTPUT);
    Serial.begin(9600);

}

void loop() {

    valor = analogRead(A0);
    bits = map(valor, 6, 679, 0, 255);

    text = String(bits);

    analogWrite(led, bits);
    Serial.println("LED: " + text);

}