#include "IRremote.h"

int signalPin = 7;
IRrecv irrecv(signalPin);
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(true);
}

void loop()
{
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        switch (results.decode_type){
            case NEC:
                Serial.println("NEC");
                break ;
            case SONY:
                Serial.println("SONY");
                break ;
            case RC5:
                Serial.println("RC5");
                break ;
            case RC6:
                Serial.println("RC6");
                break ;
            case DISH:
                Serial.println("DISH");
                break ;
            case SHARP:
                Serial.println("SHARP");
                break ;
            case JVC:
                Serial.println("JVC");
                break ;
            case SANYO:
                Serial.println("SANYO");
                break ;
            case MITSUBISHI:
                Serial.println("MITSUBISHI");
                break ;
            case PANASONIC:
                Serial.println("PANASONIC");
                break ;
          default:
            case UNKNOWN:
                Serial.println("UNKNOWN");
                break ;
          }
        irrecv.resume();
 }
}
