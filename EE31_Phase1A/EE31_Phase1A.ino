/*
  Tufts University EE31 Junior Design
  Phase 1A 
  Team Purple Mountain Majesty
  Alex Lea, Connor Nightingale, Eddy Zhang, Jacob Carulli
*/

// Define Pinouts
int red = 8;
int green = 9;
int blue = 10;
int power_button = 11;
int sleep_button = 3;
int run_button = 4;
int diagnosis_button = 5;

// Define variables
int brightness = 255;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

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
}

// the loop function runs over and over again forever
void loop() {
// NOTE: enum variables return an integer (their index in the enumeration)
  //Will have to make this value dependant on the 
  int potent_value = 0;

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
  delay(100);
}

// Function Section below --------------------------------------------------------

// This function updated curr_state after the power button was pressed
void power_pressed() {
  Serial.println("power press");
  // wait one second to detect short vs. long press
  //delay(1000);
  //enum State next_state;

  // long press turns system on or off
  if (curr_state == 1) {
    curr_state = on; // change from off to on
  } else {
    curr_state = off; // change to off
  } 
  

}

//Tell if we have pressed the run button
void run_pressed() {
  //Serial.println("run press");
  // function button can only be accessed from on state
    if (curr_state == 0) {
        curr_state = on;
    }
}

//Tell if we have pressed sleep
void sleep_pressed() {
  //Serial.println("sleep press");
  // function button can only be accessed from on state
    if (curr_state == 0) {
        curr_state = sleep;
    }
}

//Tell if we have diagnostic sleep
void diagnostic_pressed() {
  //Serial.println("diagnostic press");
  // function button can only be accessed from on state
    if (curr_state == 0) {
      curr_state = diagnostic;
    }
}

/*
 * NOTE: This function has been decomposed into power_pressed and function_pressed
 * If we get those working, this one can be deleted
 *
State get_next_state(State prev_state, Button button_pressed) {
  // wait one second to detect short vs. long press
  delay(1000);
  if (button_pressed = power) {
    // long press turns system on or off
    if (digitalRead(power_button) == HIGH) {
      if (prev_state == off) {
        return on;
      } else {
        return off;
      } 
    // short press enters or exits sleep mode
    } else {
      if (prev_state == on) {
        return sleep;
      } else if (prev_state == sleep) {
        return on;
      } else if (prev_state != off) {
        return sleep;
      }
    }
  } else {
    // function button can only be accessed from on state
    if (prev_state == on) {
      // for short press, enter run state
      if (digitalRead(function_button) == LOW) {
        return run;
      // for long press, enter diagnostic state
      } else {
        return diagnostic;
      }
    }
  }

  // if button press not valid, do not change state
  return prev_state;
}
*/


// State      : On 
// Description: Red LED Blinks @ 10 Hz 
// Status     : Doesn't fully run at 10Hz because of hardware delays? (runs slow)
void on_state() {
  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(green, LOW); 

  digitalWrite(red, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for 0.1 s (10 Hz)
  digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 0.1 s (10 Hz)
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
void run_state(int potent) {
  Serial.print("top");
  int potentiometer = analogRead(4);
  //Serial.print(potentiometer);

  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(red, LOW); 

  // set the brightness of pin 12:
  analogWrite(green, brightness = 255);

  

  while (brightness > 0) {
    //Serial.print("in loop");
    
    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount;
    
    // wait for 120 milliseconds to see the dimming effect
    delay(120);

    // write brightness
    analogWrite(green, brightness);
  }

  for (int i = 0; i < 2; i++) {
    digitalWrite(green, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500 - potent);                 // wait for 0.5 s (2 Hz)
    digitalWrite(green, LOW);   // turn the LED off by making the voltage LOW
    delay(500 - potent); 
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
    delay(250);               
    digitalWrite(blue, LOW);   // turn the LED off by making the voltage LOW
    delay(250); 
  } 

  // Fade 
  // set the brightness of pin 11:
  analogWrite(blue, brightness = 255);

  while (brightness > 0) {
    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount;
    
    // wait for 20 milliseconds to see the dimming effect
    delay(20);

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

  // for now, just blink red once

  // turn the other LEDs off by making the voltage LOW
  digitalWrite(blue, LOW);   
  digitalWrite(green, LOW); 

  //for (int i = 0; i < num_error; i++) {
    digitalWrite(red, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(200);                      
    digitalWrite(red, LOW);   // turn the LED off by making the voltage LOW
    delay(200);                      
  //}

  // delay(10000)                // delay for 10 seconds 
}