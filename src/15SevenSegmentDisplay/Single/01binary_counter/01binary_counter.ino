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
        digitalWrite(i,LOW);
    }
}

void displayDigit(int digit){
    /*
        a
    f       b
        g
    e        c
        d
    */

    //Conditions for displaying segment a
    if(digit!=1 && digit != 4)
    digitalWrite(2,HIGH);
 
    //Conditions for displaying segment b
    if(digit != 5 && digit != 6)
    digitalWrite(3,HIGH);
    
    //Conditions for displaying segment c
    if(digit !=2)
    digitalWrite(4,HIGH);
    
    //Conditions for displaying segment d
    if(digit != 1 && digit !=4 && digit !=7)
    digitalWrite(5,HIGH);
    
    //Conditions for displaying segment e 
    if(digit != 1 && digit != 3 && digit != 4 && digit != 5 && digit != 7 && digit != 9)
    digitalWrite(6,HIGH);
    
    //Conditions for displaying segment f
    if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
    digitalWrite(7,HIGH);

    if (digit!=0 && digit!=1 && digit !=7)
    digitalWrite(8,HIGH);
}

void loop() {
    for(int j=0;j<10;j++){
        displayDigit(j);
        delay(500);
        turnOff();
    }
}
