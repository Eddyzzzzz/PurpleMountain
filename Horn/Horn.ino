int outputPin = 8; // Output pin for the square wave

void setup() {
  pinMode(outputPin, OUTPUT);
  for (int i = 0; i < 2; i++) {
    playSound();
    playNoSound();
  }
}

void loop() {
  
}

void playSound() {
  for (int i = 0; i < 1202; i++) {
    digitalWrite(outputPin, HIGH); // Set the output pin HIGH
    delayMicroseconds(208); // Delay for half of the square wave period (208 us)
    digitalWrite(outputPin, LOW); // Set the output pin LOW
    delayMicroseconds(208); // Delay for half of the square wave period (208 us)
  }
}

void playNoSound() {
  digitalWrite(outputPin, LOW);
  delay(100);
}