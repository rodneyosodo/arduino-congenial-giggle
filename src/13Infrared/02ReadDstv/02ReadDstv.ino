#include "IRremote.h"

int signalPin = 7;
String irValue;
IRrecv irrecv(signalPin);
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();// start the receiver
    irrecv.blink13(true);
}

void loop()
{
    if (irrecv.decode(&results)){
        irValue = String(results.value, HEX);
        irValue.toUpperCase();
        Serial.println(irValue);
        irrecv.resume(); // Receive the next value
    }
}
