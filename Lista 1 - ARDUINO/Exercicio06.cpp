//Declaração de valores inteiros que representarão as entradas físicas do arduino
//NÃO TEM BOTÃO NO EXERCICIO 2, portanto adicionei um no pino 2
int button = 2;
int ledRed = 3;
int ledYellow = 4;
int ledGreen = 5;

//Variável de contagem de vezes que o botão foi pressionado
int i = 0;

void setup()
{
    pinMode(button, INPUT);
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);

    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);    
}

void loop()
{

    if (digitalRead(button)){
        i++;
        delay(500);
    }

    switch(i){
        case 1:
            ledFunction(HIGH,LOW,LOW);

            break;


        case 2:
            ledFunction(LOW,HIGH,LOW);

            break;

        case 3:
            ledFunction(LOW,LOW,HIGH);
            i = 0;

            break;

        default:
            break;        
    }

}

//Função que irá controlar o acender dos LED's
int ledFunction (bool redState, bool yellowState, bool greenState) { 
    digitalWrite(ledRed, redState);
    digitalWrite(ledYellow, yellowState);
    digitalWrite(ledGreen, greenState);
}