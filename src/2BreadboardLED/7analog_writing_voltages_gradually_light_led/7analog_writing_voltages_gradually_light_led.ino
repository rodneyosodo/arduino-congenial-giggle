// This turns on the onboard LED for 1s and off for 0.5s repeatedly

int redLedPin = 8;
int redWaitTimeOn = 2000;
int redWaitTimeOff = 250;
int redNumBlink = 5;
int i ;
int voltageValue;

void setup(){
    // initialize the digital pin as output
  pinMode(redLedPin, OUTPUT);     
}

void loop() {
    for(i = 1 ; i <= 5 ; i++ ){
        voltageValue = 51 * i;
        analogWrite(redLedPin, voltageValue);   // turn the LED on (HIGH is the voltage level)
        delay(redWaitTimeOn);               // wait for a 1 second
    }
    analogWrite(redLedPin, 0);    // turn the LED off by making the voltage LOW
    delay(redWaitTimeOff); 

}
