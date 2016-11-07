
#include <multiCameraIrControl.h> //call functions in MultiCameraIRLibrary by Sebastian Setz


int beamPin = 4; //set IR breakbeam receiver pin; IR transmitter and IR receiver on either arm of the chair
int fsrPin = 8; //set Force Sensitive Resistor pin inside of pillow
Nikon dslrPin(3); //call function from MultiCamera library to read pin 3
int beamBroke = 0; //variable for storing state of IR breakbeam
int fsrPress = 0; //variable for storing state of Force Sensitive Resistor
unsigned long beamTimer = 0; //timer for storing how long IR breakbeam is in a given state
unsigned long fsrTimer = 0; //timer for storing how long FSR is in a given state


void setup() {
  pinMode(beamPin, INPUT); //set IR breakbeam sensor and FSR "sensor" pins as inputs
  pinMode(fsrPin, INPUT);
  }

void loop() {
  digitalWrite(beamPin, HIGH); //pullup IR breakbeam so that it begins in a state of on
  
  unsigned long currentMillis = millis(); //establish variable for current time
  
  beamBroke = digitalRead(beamPin); //establish variable for reading IR breakbeam
  fsrPress = digitalRead(fsrPin); //establish variable for reading FSR

  unsigned long fsrTimer; //establish timer to keep track of how long FSR is in a given state
  
  if (beamBroke == LOW){  //IR breakbeam begins HIGH; when it is broken by a person, trigger the IR LED to pulse
    dslrPin.shutterNow(); //IR LED pulses so camera IR sensor triggers the camera shutter once
    beamBroke != beamBroke; //after the shutter is triggered once, reset the IR breakbeam to previous state
    } 
    else if (fsrPress == HIGH && (beamBroke == HIGH || beamBroke == LOW)){ //if someone is sitting on FSR regardless of IR breakbeam
       fsrTimer = millis(); //start timing how long the FSR sensor is receiving pressure
     } 
     else {
          fsrTimer = 0; //if neither of the conditions above are met, do nothing
      }

   for (fsrTimer = 0; fsrTimer > 0; fsrTimer++){ //for each time the FSR has been HIGH for any length of time,
    dslrPin.shutterNow(); //make the shutter go off while the person is sitting on the FSR
    delay(250); //create a delay because I think the MultiCameraIRLibrary will stop working if the IR LED is not given a pause
         }
}
   

