//Definindo variáveis
float bits = 0;
int led = 3;

float time;

//void Setup
void setup(){
	pinMode(led, OUTPUT);
  
  //Monitor Serial
  Serial.begin(9600);
}

//void loop
void loop(){
	bits = analogRead(A0)/4;
	
    //Regra de 3 -> escala de conversão de 0-255 -> 0-100%
  	time = bits / 64;
    Serial.println(time);
  
    if (time == 0){
        digitalWrite(led,LOW);
    } else {
        for (int i = 0; i <= 255; i++){
            analogWrite(led, i);
            delay((time*500) / 255);
        }


        for (int j = 255; j >= 0; j--){
            analogWrite(led, j);
            delay((time*500) / 255);
        }
    }
}