/*
  Tufts University EE31 Junior Design
  Phase 2A: Motor Control
  Team Purple Mountain Majesty
  Alex Lea, Connor Nightingale, Eddy Zhang, Jacob Carulli
*/

// Define Digital Pinouts
int s1 = 10;
int s2 = 3;
int s3 = 11;
int s4 = 5;

//Define millis for timing
unsigned long startMillis;
unsigned long currentMillis;


void setup() {
  // important for using serial monitor
  Serial.begin(9600);

  // initialize digital pins as outputs
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);

  // initialize state of pins
  digitalWrite(s1, LOW);  
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  digitalWrite(s4, HIGH);

  //Inital the start time
  startMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  //millisDelay(100);

  // turn on motor clockwise
  digitalWrite(s1, LOW);  
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  digitalWrite(s4, HIGH);

  millisDelay(1000);

  // decelerate motor
  digitalWrite(s1, LOW);  
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  digitalWrite(s4, LOW);

  millisDelay(1000);

  // turn on motor counter-clockwise
  digitalWrite(s1, HIGH);  
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  digitalWrite(s4, LOW);

  millisDelay(1000);

  // decelerate motor
  digitalWrite(s1, LOW);  
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  digitalWrite(s4, LOW);

  millisDelay(1000);
}


void millisDelay( long int delayTime){
  long int start_time = millis();
  while ( millis() - start_time < delayTime) ;
}