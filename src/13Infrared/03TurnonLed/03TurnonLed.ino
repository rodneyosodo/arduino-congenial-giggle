#include "IRremote.h"

int signalPin = 7;
int ledPin = 8;
int waitTimeOn = 250;
int waitTimeOff = 250;
int waitTimeLed = 5000;
int i;
String irValue;
IRrecv irrecv(signalPin);
decode_results results;

void turn_on_led() {
    digitalWrite(ledPin, HIGH);
}
void turn_off_led() {
    digitalWrite(ledPin, LOW);
}

void blink_led_forever() {
    for(i = 0; i <= 5; i++) {
        digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(waitTimeOn);               // wait for a 1 second
        digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
        delay(waitTimeOff);
    }
}
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); 
    irrecv.enableIRIn();// start the receiver
    irrecv.blink13(true);
}

void loop()
{
    if (irrecv.decode(&results)){
        irValue = String(results.value, HEX);
        irValue.toUpperCase();
        Serial.println(irValue);
        Serial.println("\n");
        if (irValue == "FF629D"){
            turn_on_led();
        }
        else if (irValue == "FFA857") {
            turn_off_led();
        }
        else if (irValue == "FF02FD") {
            blink_led_forever();
        }
        irrecv.resume(); // Receive the next value
    }
}
