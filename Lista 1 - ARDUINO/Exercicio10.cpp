//Declaração de valores inteiros que representarão as entradas físicas do arduino
//NÃO TEM BOTÃO NO EXERCICIO 2, portanto adicionei um no pino 2
int buttonHigh = 6;
int buttonLow = 5;
int led = 4;

int i = 0;

void setup()
{
    pinMode(buttonHigh, INPUT);
    pinMode(buttonLow, INPUT);
    pinMode(led, OUTPUT);

    digitalWrite(led, LOW);
}

void loop(){

    while(digitalRead(buttonHigh) && digitalRead(buttonLow)){
        digitalWrite(led, LOW);
        i = 1;
    }

    if(digitalRead(buttonHigh) && i == 0){
        digitalWrite(led, HIGH);
    } else if (digitalRead(buttonLow) && i == 0){
        digitalWrite(led, HIGH);
    } else if (!digitalRead(buttonHigh) && !digitalRead(buttonLow)){
        i = 0;
    }       

}