//Declaração de valores inteiros que representarão as entradas físicas do arduino
int ledRed = 3;
int ledYellow = 4;
int ledGreen = 5;

void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
}

void loop()
{

    for (float i = 5000; i >= 5; i -= i * 0.2){
        ledLoop(i);
    }

}

//Função que irá controlar o piscar dos LED's e o delay
int ledLoop (float timeFunction) { 
    digitalWrite(ledRed, HIGH);
    delay(timeFunction);
    digitalWrite(ledRed, LOW);
    delay(timeFunction);
    digitalWrite(ledYellow, HIGH);
    delay(timeFunction);
    digitalWrite(ledYellow, LOW);
    delay(timeFunction);
    digitalWrite(ledGreen, HIGH);
    delay(timeFunction);
    digitalWrite(ledGreen, LOW);
    delay(timeFunction);
}