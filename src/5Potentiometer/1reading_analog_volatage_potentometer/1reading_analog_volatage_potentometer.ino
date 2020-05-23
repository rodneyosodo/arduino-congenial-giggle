// This turns on the onboard LED for 1s and off for 0.5s repeatedly

int potentiometerPin = A5;
int readValue;
float voltageValue;

void setup(){
    // initialize the digital pin as output
  pinMode(potentiometerPin, INPUT);     
  Serial.begin(1200);
}

void loop() {
    readValue = analogRead(potentiometerPin);
    voltageValue = (5.0 / 1023.0) * readValue;
    Serial.println(voltageValue);
}
