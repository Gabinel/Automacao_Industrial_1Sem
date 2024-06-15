//Declaração de valores inteiros que representarão as entradas físicas do arduino
//NÃO TEM BOTÃO NO EXERCICIO 2, portanto adicionei um no pino 2
int button = 6;
int led = 4;

//Variável de contagem de vezes que o botão foi pressionado
int i = 0;

unsigned long currentTime;

void setup()
{
    pinMode(button, INPUT);
    pinMode(led, OUTPUT);

    digitalWrite(led, LOW);
}

void loop()
{

    if (i >= 1){ 

        currentTime = millis();

        while (millis() < currentTime + (1000 / i)){
            digitalWrite(led, HIGH);

            if (digitalRead(button)){
                i++;
                delay(50);
            }

        }

        currentTime = millis();

        while (millis() < currentTime + (1000 / i)){
            digitalWrite(led, LOW);

            if (digitalRead(button)){
                i++;
                delay(50);
            }

        }

    } else {

        if (digitalRead(button)){
            i++;
            delay(50);
        }

    }
}