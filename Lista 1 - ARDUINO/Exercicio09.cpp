//Declaração de valores inteiros que representarão as entradas físicas do arduino
//NÃO TEM BOTÃO NO EXERCICIO 2, portanto adicionei um no pino 2
int buttonHigh = 6;
int buttonLow = 5;
int led = 4;

void setup()
{
    pinMode(buttonHigh, INPUT);
    pinMode(buttonLow, INPUT);
    pinMode(led, OUTPUT);

    digitalWrite(led, LOW);
}

void loop(){

    while(digitalRead(buttonHigh) && digitalRead(buttonLow)){
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }

    if(digitalRead(buttonHigh)){
        digitalWrite(led, HIGH);
    } else if (digitalRead(buttonLow)){
        digitalWrite(led, LOW);
    }        

}