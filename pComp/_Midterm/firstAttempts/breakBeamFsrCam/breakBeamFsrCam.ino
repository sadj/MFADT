
#include <multiCameraIrControl.h>



const int bbPin = 4;

int beamState = 0, lastBeamState = 0;

const int fsr = 8;
Nikon camera(3);

int fsrState = 0, lastFsrState = 0;


void setup() {

  Serial.begin(9600);
  pinMode(bbPin, INPUT);
  pinMode(fsr, INPUT);

  digitalWrite(bbPin, HIGH);

}


void loop() {
  beamState = digitalRead(bbPin);
  if (beamState == LOW){
    camera.shutterNow();
  }
 if(beamState && !lastBeamState){
    Serial.println("Unbroken");
  }

  else if(!beamState && lastBeamState){
    Serial.println("Broken");
  }
  
  lastBeamState = beamState;

  //fsrState = digitalRead(fsr);
  //Serial.println(fsrState);
 
  

  //if (fsrState == HIGH){
    // camera.shutterNow();
    //} ;

   //if (fsrState != lastFsrState){
    //digitalWrite (fsr, LOW);
  // }
  
   
}
