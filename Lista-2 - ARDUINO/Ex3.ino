int red = 8;
int green = 9;
int yellow = 10;

String ledState;
String ledName;

void setup() {

    for(int i = 8; i <= 10; i++){
        pinMode(i, OUTPUT);
    }

    Serial.begin(9600);

}

void loop() {

    Serial.println("\nR - Vermelho\nV - Verde\nY - Amarelo\n");

    while(1) {

        if(Serial.available() > 0){
            String result = Serial.readString();
          	Serial.println(result);
            controlLed(result);
            break;
        }

    }

}

void controlLed(String led){

    for(int i = 8; i <= 10; i++){
        if(i == red && led == "R" || i == green && led == "G" || i == yellow && led == "Y"){
            digitalWrite(i, HIGH);
        } else {
            digitalWrite(i, LOW);
        }
      
      	ledName = String(i);
      	ledState = String(digitalRead(i));
      	Serial.println("Led " + ledName + ": " + ledState);
    }

}