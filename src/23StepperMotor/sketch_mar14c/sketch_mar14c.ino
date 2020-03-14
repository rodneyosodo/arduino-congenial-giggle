#include <Stepper.h>

// the steps of a circle
#define STEPS 100

// set steps and the connection
// Create instances in which we specify the pins to which we have connected the Stepper motor.
Stepper stepper(STEPS, 2, 4, 3, 5);

//stores previous value
int previous = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // The speed can range between 0 to 200
  stepper.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(0);
  
  Serial.println(val);
  //  Since we have 32 steps and 64 as the gear ratio we need to move 2048 (32*64=2048),
  // to make one complete rotation.
  // our analogRead max in 1024 so we multiply by 2
  val = val * 2;
  stepper.step(val - previous);

  previous = val;

}
