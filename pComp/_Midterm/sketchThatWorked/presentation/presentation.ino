
#include <multiCameraIrControl.h>

//const int bbPin = 4;
//int beamState = 0, lastBeamState = 0;

const int fsr = 8;
int fsrState = 0, lastFsrState = 0;

Nikon camera(3);

void setup() {

  //pinMode(bbPin, INPUT);
  //digitalWrite(bbPin, HIGH);
  Serial.begin(9600);
}


void loop() {
  //beamState = digitalRead(bbPin);
  
  fsrState = digitalRead(fsr);
  Serial.println(fsrState);
 
  if (fsrState == 1){
     camera.shutterNow();
    }
   
}
