int lowestPin = 4;
int highestPin = 13;
int delayTime = 250;

void setup(){
    for(int pin = lowestPin; pin <= highestPin; pin++){
        pinMode(pin, OUTPUT);
    }
}

void loop(){
    for(int pin = lowestPin; pin <= highestPin; pin++){
        digitalWrite(pin, HIGH);
        delay(delayTime);
    }
    for(int pin = highestPin; pin >= lowestPin; pin--){
        digitalWrite(pin, LOW);
        delay(delayTime);
    }
    for(int pin = highestPin; pin >= lowestPin; pin--){
        digitalWrite(pin, HIGH);
        delay(delayTime);
    }
    for(int pin = lowestPin; pin <= highestPin; pin++){
        digitalWrite(pin, LOW);
        delay(delayTime);
    }

}
