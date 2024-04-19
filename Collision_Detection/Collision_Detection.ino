// Collision Detection System Code

float threshold_2in = 800;

bool is_wall_detected(float threshold) {
  return (analogRead(A0) >= threshold);
}

void setup() {
  Serial.begin(9600);
  Serial.print("STARTING TASK\n");
}

void loop() {
  for (;;) {
    Serial.println(analogRead(A0));
    Serial.println(is_wall_detected(threshold_2in));
    delay(1000);
  }
}