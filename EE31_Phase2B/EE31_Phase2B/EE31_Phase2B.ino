int in1 = 6;
int in2 = 5;
int in3 = 10;
int in4 = 11;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Move forward
  analogWrite(in1, 155);
  analogWrite(in2, 0);
  analogWrite(in3, 155);
  analogWrite(in4, 0);
  delay(2000); // Move for 2 seconds

  // Stop
  analogWrite(in1, 0);
  analogWrite(in3, 0);
  delay(1000); // Stop for 1 second

  // Turn left
  analogWrite(in1, 0);
  analogWrite(in2, 110);
  analogWrite(in3, 110);
  analogWrite(in4, 0);
  delay(1000); // Turn for 2 second

  // Stop
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  delay(1000); // Stop for 1 second

}
