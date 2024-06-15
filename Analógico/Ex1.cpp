//Definindo variáveis
int bits = 0;
int led = 3;

//void Setup
void setup(){
	pinMode(led, OUTPUT);
  
  //Monitor Serial
  Serial.begin(9600);
}

//void loop
void loop(){
  	for (int i = 0; i <= 255; i++){
        analogWrite(led, i);
      	delay(5);
    }


    for (int j = 255; j >= 0; j--){
        analogWrite(led, j);
      	delay(5);
    }   
}