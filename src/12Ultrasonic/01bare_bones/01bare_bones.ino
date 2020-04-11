// print distance to serial — hy_sr05
// Ty Seyoum

#define ECHOPIN 2 // Pin to receive echo pulse
#define TRIGPIN 3 // Pin to send trigger pulse

void setup() {
  Serial.begin(9600); //
  pinMode(13, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  digitalWrite(13, LOW);
  digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
  delay(1);
  digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
  delay(1);
  digitalWrite(TRIGPIN, LOW); // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH); // Read in times pulse
  distance = distance / 58; // Calculate distance from time of pulse
  if (distance <= 50) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
  Serial.println(distance);
  delay(1000); // Wait 50mS before next ranging
}
