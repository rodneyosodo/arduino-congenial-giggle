#include "IRremote.h"

int signalPin = 7;
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
        Serial.println(results.value, HEX);
        irrecv.resume(); // Receive the next value
    }
}
