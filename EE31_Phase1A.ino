/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int red = 13;
int blue = 11;
int green = 10;

int brightness = 255;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //on_state();
  //off_state();
  //run_state();
}

// On state
// Doesn't fully run at 10Hz because of hardware delays? (runs slow)
void on_state() {
  digitalWrite(red, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for 0.1 s (10 Hz)
  digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 0.1 s (10 Hz)

  digitalWrite(blue, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
}

// Off state
void off_state() {
  digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(blue, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
}

void run_state() {

  // set the brightness of pin 12:
  analogWrite(green, brightness = 255);

  while (brightness > 0) {
    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount;
    
    // wait for 120 milliseconds to see the dimming effect
    delay(120);

    // write brightness
    analogWrite(green, brightness);
  }

  digitalWrite(green, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for 0.5 s (2 Hz)
  digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
  delay(500); 

  digitalWrite(green, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for 0.5 s (2 Hz)
  digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
  delay(500); 
  
}