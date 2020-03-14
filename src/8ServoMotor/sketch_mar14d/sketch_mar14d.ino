#include <Servo.h>

// Creating a servo objectt
Servo myservo;

int pos = 0;
void setup() {
  // put your setup code here, to run once:
  // Attach servo to pin 9
  myservo.attach(9);
  // Back to 0 degreees
  myservo.write(0);
  // Wait for 2 seconds
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(1);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(1);
  }

}
