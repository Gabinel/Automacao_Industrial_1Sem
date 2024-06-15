int button = 2, cont;
String buttonState;

void setup() {

    pinMode(button, INPUT);
    Serial.begin(9600);

}

void loop() {
  
  	cont = 0;

    buttonState = String(digitalRead(button));
    Serial.println("BOTAO: " + buttonState);

    while(1) {

        while(digitalRead(button)){
            buttonState = String(digitalRead(button));
          	cont++;
          	if(cont == 1){
             	Serial.println("BOTAO: " + buttonState);
            }
        }
      	
      	if(cont >= 1){
        	break;
      	}

    }

}