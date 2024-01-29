/*
  Tufts University EE31 Junior Design
  Phase 1A 
  Team Purple Mountain Majesty
  Alex Lea, Connor Nightingale, Eddy Zhang, Jacob Carulli
*/

<<<<<<< HEAD
// Define Digital Pinouts
=======
//Define millis for timing
unsigned long startMillis;
unsigned long currentMillis;

// Define Pinouts
>>>>>>> 50fdef0f59e4e4bfe11845b5b7496323c6699bcd
int red = 8;
int green = 9;
int blue = 10;
int power_button = 11;
int sleep_button = 3;
int run_button = 4;
int diagnosis_button = 7;

// Define Analog Pinouts
int potent_pattern = 4;
int potent_brightness = 5;

// Define variables
int brightness = 255;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

int pattern_value;    // potentiometer value for the pattern of the run state
int brightness_value;  // potentiometer value for the brightness of the run state

// NOTE: enum variables return an integer (their index in the enumeration)
enum State { on, off, run, sleep, diagnostic };
//enum Button { power_, run_, sleep_, diagnostic_};
enum State curr_state;

// the setup function runs once when you press reset or power the board
void setup() {
  // important for using serial monitor
  Serial.begin(9600);

  // initialize digital pins as outputs.
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  // loop is current ISR function, might need adjustment
  attachInterrupt(digitalPinToInterrupt(power_button), power_pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(run_button), run_pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(sleep_button), sleep_pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(diagnosis_button), diagnostic_pressed, RISING);


  // NOTE: enum variables are set using the names of the enumerations
  curr_state = run;
  //Inital the start time
  startMillis = millis();
}

// the loop function runs over and over again forever
void loop() {
// NOTE: enum variables return an integer (their index in the enumeration)

<<<<<<< HEAD
  int pattern_value = analogRead(potent_pattern);
  int brightness_value = analogRead(potent_brightness);

  // if (curr_state == 0) {
  //   Serial.println("on");
  //   on_state();
  // }
  // else if (curr_state == 1) {
  //   Serial.println("off");
  //   off_state();
  // }
  // else if (curr_state == 2) {
  //   Serial.println("run");
  //   run_state(pattern_value, brightness_value);
  // }
  // else if (curr_state == 3) {
  //   Serial.println("sleep");
  //   sleep_state();
  // }
  // else {
  //   Serial.println("diagnostic");
  //   diagnostic_state();
  // }
  // //Serial.println(digitalRead(2));
  delay(300);

  
  Serial.println(potentiometer);
=======
  if (curr_state == 0) {
    Serial.println("on");
    on_state();
  }
  else if (curr_state == 1) {
    Serial.println("off");
    off_state();
  }
  else if (curr_state == 2) {
    Serial.println("run");
    run_state(potent_value);
  }
  else if (curr_state == 3) {
    Serial.println("sleep");
    sleep_state();
  }
  else {
    Serial.println("diagnostic");
    diagnostic_state();
  }
  //Serial.println(digitalRead(2));
  millisDelay(100);
>>>>>>> 50fdef0f59e4e4bfe11845b5b7496323c6699bcd
}

// Function Section below --------------------------------------------------------

// This function updated curr_state after the power button was pressed
void power_pressed() {
  Serial.println("power press");
  // wait .1 s to prevent loop from running multiple times during one press (CANNOT USE delay())
  
  if (curr_state == 1) {
    Serial.println("changing to on");
    curr_state = on; // change from off to on
  } else {
    Serial.println("changing to off");
    curr_state = off; // change to off
  } 


}

//Tell if we have pressed the run button
void run_pressed() {
    if (curr_state != 1) {
        Serial.println("changing to run");
        curr_state = run;
    }
}

//Tell if we have pressed sleep
void sleep_pressed() {
    if (curr_state != 1) {
        Serial.println("changing to sleep");
        curr_state = sleep;
    }
}

//Tell if we have diagnostic sleep
void diagnostic_pressed() {
    if (curr_state != 1) {
      Serial.println("changing to diagnostic");
      curr_state = diagnostic;
    }
}


// State      : On 
// Description: Red LED Blinks @ 10 Hz 
// Status     : Doesn't fully run at 10Hz because of hardware delays? (runs slow)
void on_state() {
  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(green, LOW); 

  digitalWrite(red, HIGH);  // turn the LED on (HIGH is the voltage level)
  millisDelay(100);                      // wait for 0.1 s (10 Hz)
  digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
  millisDelay(100);                      // wait for 0.1 s (10 Hz)
}

// State      : Off
// Description: All LED turn off
// Status     : Fully Funtional
void off_state() {
  digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(blue, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
}

// State      : Run
// Description: Green LED decay with time constant of 6 secs. 
//              Flashes twice for duty cycle of 0.5 secs, then repeats while in state.
// Status     : Fully functional
<<<<<<< HEAD
void run_state(int pattern, int brightness_potentiometer) {
  
=======
void run_state(unsigned long potent) {
  Serial.print("top");
  int potentiometer = analogRead(4);
  //Serial.print(potentiometer);

>>>>>>> 50fdef0f59e4e4bfe11845b5b7496323c6699bcd
  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(red, LOW); 

  // set the brightness of pin 12:
  analogWrite(green, brightness = 255);

  

  while (brightness > 0) {
    //Serial.print("in loop");
    
    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount - brightness_potentiometer;
    
    // wait for 120 milliseconds to see the dimming effect
    millisDelay(120);

    // write brightness
    analogWrite(green, brightness);
  }

  for (int i = 0; i < 2; i++) {
    digitalWrite(green, HIGH);  // turn the LED on (HIGH is the voltage level)
<<<<<<< HEAD
    delay(500 - (pattern/2));                 // wait for 0.5 s (2 Hz)
    digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
    delay(500 - (pattern/2)); 
=======
    millisDelay(500 - potent);                 // wait for 0.5 s (2 Hz)
    digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
    millisDelay(500 - potent); 
>>>>>>> 50fdef0f59e4e4bfe11845b5b7496323c6699bcd
  } 
  
}

// State      : Sleep
// Description: Blue LED blinks @ 4 Hz for 1 sec (4 times/second), Fade for 1 sec.  
//              Last blink fades to off over Fade.
// Status     : Working
void sleep_state() {
  // turn the other LEDs off by making the voltage LOW
  digitalWrite(green, LOW);   
  digitalWrite(red, LOW); 

  // Blink @ 4 Hz for 1 sec
  for (int i = 0; i < 2; i++) {
    digitalWrite(blue, HIGH);  // turn the LED on (HIGH is the voltage level)
    millisDelay(250);               
    digitalWrite(blue, LOW);   // turn the LED off by making the voltage LOW
    millisDelay(250); 
  } 

  // Fade 
  // set the brightness of pin 11:
  analogWrite(blue, brightness = 255);

  while (brightness > 0) {
    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount;
    
    // wait for 20 milliseconds to see the dimming effect
    millisDelay(20);

    // write brightness
    analogWrite(blue, brightness);
  }

}

// State      : Diagnostic
// Description: Red LED Blinks N number of times for N list of problems.  
//              A) Show 5 problems situations.
//              B) Show 8 problems situations.
// Status     : Working
void diagnostic_state() {
  // we eventually need to blink N times for N problems
  const unsigned long period = 200;

  // for now, just blink red once

  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(green, LOW); 

  //for (int i = 0; i < num_error; i++) {
    digitalWrite(red, HIGH);  // turn the LED on (HIGH is the voltage level)
    millisDelay(200);                      
    digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
    millisDelay(200);                      
  //}

  // delay(10000)                // delay for 10 seconds 
}

void millisDelay( long int delayTime){
  long int start_time = millis();
  while ( millis() - start_time < delayTime) ;
}