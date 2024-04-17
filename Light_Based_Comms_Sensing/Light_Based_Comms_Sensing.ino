int val = 0;
int threshold = 150;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  delay(100);
  if (val > threshold) {
    delay(250);
    Serial.println("one");
    val = analogRead(A0);
    if (val < threshold) {
      delay(250);
      Serial.println("two");
      val = analogRead(A0);
      if (val > threshold) {
        delay(250);
        Serial.println("three");
        val = analogRead(A0);
        if (val < threshold) {
          start_challenge1();
        }
      }
    }
  }
}

void start_challenge1() {
  Serial.println("Starting challenge!");
}

