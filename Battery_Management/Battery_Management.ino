int output = 6;
int val = 0;
int brightness;


void setup() {
  Serial.begin(9600);
  pinMode(output, OUTPUT);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  brightness = (val - 700);
  analogWrite(output, brightness);
  delay(500);
}
