#include <multiCameraIrControl.h>



const int pushButtonPin = 4;
Sony A900(3);

int buttonState = 0;
int lastButtonState = 0;

void setup() {

 Serial.begin(9600); 
 pinMode(pushButtonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(pushButtonPin);
  Serial.println(buttonState);

  if(buttonState != lastButtonState && buttonState == HIGH){
    A900.shutterNow();
  }

   lastButtonState = buttonState;
}

