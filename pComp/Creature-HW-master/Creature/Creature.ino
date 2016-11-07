/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int potPin2 = 5;
int potVal;    // variable to read the value from the analog pin


bool ledState = true;
int blinkWaitTime = 0; //correlates to value given by potPin2
unsigned long lastBlinkTime = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  potVal = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  potVal = map(potVal, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(potVal);                  // sets the servo position according to the scaled value
  //delay(15);                           // waits for the servo to get there

  blinkWaitTime = analogRead(potPin2);   //homage to AL
  blinkWaitTime = map(blinkWaitTime, 0, 1023, 100, 1000);

  unsigned long currentTime = millis();

  if(currentTime - lastBlinkTime > blinkWaitTime){

    ledState = !ledState;

    lastBlinkTime = millis();
    
  }

  if(ledState == true){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else {
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
  
}

