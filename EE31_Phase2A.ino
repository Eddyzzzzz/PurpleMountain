/*
  Tufts University EE31 Junior Design
  Phase 2A: Motor Control
  Team Purple Mountain Majesty
  Alex Lea, Connor Nightingale, Eddy Zhang, Jacob Carulli
*/

// Define Digital Pinouts
int in1 = 10;
int in2 = 3;
int in3 = 11;
int in4 = 5;

//Define millis for timing
unsigned long startMillis;
unsigned long currentMillis;


void setup() {
  // important for using serial monitor
  Serial.begin(9600);

  // initialize digital pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // initialize state of pins
  digitalWrite(in1, LOW);  
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  //Inital the start time
  startMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  millisDelay(100);

  // turn on motor clockwise
  digitalWrite(in1, HIGH);  
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  millisDelay(1000);

  // decelerate motor
  digitalWrite(in1, HIGH);  
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  millisDelay(1000);
}


void millisDelay( long int delayTime){
  long int start_time = millis();
  while ( millis() - start_time < delayTime) ;
}