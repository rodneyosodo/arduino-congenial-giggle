int sensorValue;
int sensorPin = A0;

void setup(){
    Serial.begin(9600);                            // sets the serial port to 9600
}

void loop(){
    sensorValue = analogRead(sensorPin);       // read analog input pin 0
    Serial.print("Air quality: ");
    Serial.print(sensorValue, DEC);               // prints the value read
    Serial.println(" PPM");
    delay(500);                                   // wait 100ms for next reading
}
