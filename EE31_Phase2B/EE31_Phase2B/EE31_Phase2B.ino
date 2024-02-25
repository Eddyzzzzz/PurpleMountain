int enablePinA = 5;
int enablePinB = 6;
int in1 = 9;
int in2 = 10;
int in3 = 11;
int in4 = 12;

void setup() {
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enablePinA, 255); // full speed
  analogWrite(enablePinB, 255); // full speed
  delay(2000); // Move for 2 seconds

  // Stop
  analogWrite(enablePinA, 0);
  analogWrite(enablePinB, 0);
  delay(1000); // Stop for 1 second

  // Turn right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enablePinA, 150); // reduce speed to 78%
  analogWrite(enablePinB, 150);
  delay(1000); // Turn for 1 second

  // Stop
  analogWrite(enablePinA, 0);
  analogWrite(enablePinB, 0);
  delay(1000); // Stop for 1 second

}
