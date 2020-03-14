// This turns on the onboard LED for 0.1s repeatedly

int led 13;

void setup(){
    // initialize the digital pin as output
  pinMode(led, OUTPUT);     
}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a 0.1 second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for a 0.1 second
}
