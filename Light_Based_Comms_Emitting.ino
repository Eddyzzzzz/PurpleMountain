// // Define the parameters
// const int carrierFrequency = 100000; // Carrier frequency in Hz
// const int modulationPin = 9; // Digital pin used for modulation
// int count = 0;
// int high = 1;
// int carrierValue;

// void setup() {
//   Serial.begin(9600);

//   // Set the modulation pin as an output
//   pinMode(modulationPin, OUTPUT);
// }

// void loop() {
//   // Generate a sine wave for modulation
//   for (int i = 0; i < 360; i++) {
//     if (count > 500000) {
//       count = 0;
//     }
//     // Calculate the modulation value (amplitude) from sine wave
//     float modulationValue = sin(i * PI / 180); // Sine wave modulation (-1 to 1)

//     // Generate the carrier signal
//     // The carrier signal is a square wave with the specified frequency
//     // It's modulated by multiplying with the modulation value
//     // The modulation value ranges from 0 to 1, so it scales the amplitude of the carrier signal
//     if (count < 250000) { // LOW
//       carrierValue = (modulationValue + 1) * 50; // Convert modulation value to 0-255 range
//     }
//     else { // HIGH
//       carrierValue = (modulationValue + 1) * 127.5;
//     }

//     // Output the modulated signal to the modulation pin
//     analogWrite(modulationPin, carrierValue);

//     // Delay to control the modulation frequency
//     delayMicroseconds(1000000 / carrierFrequency);

//     count += 333;

//   }

// }


// Light-based communication code for the IR LED sending out a message at 3000 Hz
// Message is HIGH for 250 ms and then low-ish for 250 ms

const int modulationPin = 6; // Digital pin used for modulation

void setup() {
  Serial.begin(9600);

  // Set the modulation pin as an output
  pinMode(modulationPin, OUTPUT);
}

int i = 0;
void loop() {
  for (int i = 0; i < 753; i++) {
    // Generate a square wave with a frequency of 3000 Hz
    analogWrite(modulationPin, HIGH); // Set the output pin HIGH to represent an AM signal with a higher peak
    delayMicroseconds(166); // Delay for half the period (1/2 * 1/3000 seconds = 166.67 microseconds)
    analogWrite(modulationPin, LOW); // Set the output pin LOW
    delayMicroseconds(166); // Delay for the other half of the period
  }
  for (int i = 0; i < 753; i++) {
    // Generate a square wave with a frequency of 3000 Hz
    analogWrite(modulationPin, 90); // Set the output pin to 90 to represent an AM signal with a lower peak
    delayMicroseconds(166); // Delay for half the period (1/2 * 1/3000 seconds = 166.67 microseconds)
    analogWrite(modulationPin, LOW); // Set the output pin LOW
    delayMicroseconds(166); // Delay for the other half of the period
  }
}
