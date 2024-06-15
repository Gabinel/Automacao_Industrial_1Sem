//Declaração de valores inteiros que representarão as entradas físicas do arduino
int button = 2;
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;

void setup()
{
  pinMode(button, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  display (HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
}

void loop()
{
    bool buttonState = digitalRead(button);

    if(buttonState){
        for (int i = 9; i >= 0; i--){
      	    switch(i){           
                case 1:
                    display (LOW, LOW, LOW, LOW, HIGH, HIGH, LOW);

                    break;

                case 2:
                    display (HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH);

                    break; 

                case 3:
                    display (HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH);

                    break;       

                case 4:
                    display (LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH);

                    break;    

                case 5:
                    display (HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH);

                    break;    

                case 6:
                    display (HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH);

                    break;

                case 7:
                    display (HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);

                    break;

                case 8:
                    display (HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);

                    break;

                case 9:
                    display (HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH);

                    break; 
            
                case 0:
                    display (HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);

                    break;
            }                               
        }
    }
}

//Função que irá controlar o funcionamento do display
int display (bool aState, bool bState, bool cState, bool dState, bool eState, bool fState, bool gState) { //Recebe a cor e o tempo no qual a luz ficará ligada
    digitalWrite(a, aState);
    digitalWrite(b, bState);
    digitalWrite(c, cState);
    digitalWrite(d, dState);
    digitalWrite(e, eState);
    digitalWrite(f, fState);
    digitalWrite(g, gState);
    delay(500);
}