int i, j;

void setup() {    
    // Setting all the pins connected to be OUTPUT PINS          
    for(i = 2; i <= 8; i++){
        pinMode(i, OUTPUT);
    }
}

void turnOff(){
    // Turn of all LED's
    for(i = 2; i <= 8; i++){
        digitalWrite(i, LOW);
    }
}

void displayDigit(){
    /*
        a(2)
    f(7)       b(3)
        g(8)
    e(6)        c(4)
        d(5)
    */
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(5, HIGH);
}

void loop() {
    turnOff();
    displayDigit();
}
