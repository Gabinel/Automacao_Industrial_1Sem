//Declaração de valores inteiros que representarão as entradas físicas do arduino
//NÃO TEM BOTÃO NO EXERCICIO 2, portanto adicionei um no pino 2
int button = 6;
int led = 4;

//Variável de contagem de vezes que o botão foi pressionado
int i = 0;

void setup()
{
    pinMode(button, INPUT);
    pinMode(led, OUTPUT);

    digitalWrite(led, LOW);
}

void loop(){

    digitalWrite(led, LOW);

    if (digitalRead(button)){
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
    }
}