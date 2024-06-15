int a = 6;
int b = 7;
int red = 8;
int green = 9;
int yellow = 10;

bool andLogic, orLogic, xorLogic, aState = false, bState = false;

String ledState;


void setup() {

    for(int i = 6; i <= 7; i++){
        pinMode(i, INPUT);
    }

    for(int i = 8; i <= 10; i++){
        pinMode(i, OUTPUT);
    }

    Serial.begin(9600);

}

void loop() {

    printState();
  	
  	aState = digitalRead(a);
  	bState = digitalRead(b);

    if(!aState && !bState){
        andLogic = false;
        orLogic = false;
        xorLogic = false;
    } else if(aState && !bState || !aState && bState){
        andLogic = false;
        orLogic = true;
        xorLogic = true;
    } else if(aState && bState){
        andLogic = true;
        orLogic = true;
        xorLogic = false;
    }
  
  	controlLed(andLogic, orLogic, xorLogic);

}

void controlLed(bool aLogic, bool oLogic, bool xLogic){

    digitalWrite(yellow, aLogic);
    digitalWrite(green, oLogic);
    digitalWrite(red, xLogic);

}

void printState() {
  
  	Serial.println("--------");

    ledState = String(digitalRead(red));
    Serial.println("XOR: " + ledState);

    ledState = String(digitalRead(green));
    Serial.println("OR: " + ledState);

    ledState = String(digitalRead(yellow));
    Serial.println("AND: " + ledState);
  
  	Serial.println("--------");
  
  	delay(100);

}