String tempText;

int buzzer = 3, limit = 100, temp, cont = 0;

void setup() {

    Serial.begin(9600);

}

void loop() {

    temp = (map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125));
    tempText = String(temp);

    //Caso exceda o limite, toca o alarme por 1s e depois desliga
    if(temp >= limit && cont == 0){
        tone(buzzer, 200, 1000);
      	cont++;
    } else if(temp <= limit) {
    	cont = 0;
    }

    Serial.println("A temperatura e: " + tempText);

}