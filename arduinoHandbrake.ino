#include "Joystick.h"

/* Wiring up the potentiometer with the knob pointing up
  Left pin -> GND ground
  middle pin -> Analog Input A0
  right pin -> VCC 5V
*/

// this is your analog pin on the arduino
const int potPin = A0;

// these two values are for your deadzone
const int maxValue = 651;
const int minValue = 365;

// change this value to 0 if your handbrake is going the wrong way eg. from 255 to 0 instead of 0 to 255
const int flip = 1;

// set this to 0 once you finished changing your deadzone maxValue and minValue values. And it will start working as a joystick
const int calculateDeadZone = 0;

int potValue = 0;

void deadZone(){
  int potContrained = constrain(potValue,minValue,maxValue);
  int mapped = 0; 
  if(flip){
    mapped = map(potContrained,maxValue,minValue,0,255);
  }else{
    mapped = map(potContrained,minValue,maxValue,0,255);
  }
  if(calculateDeadZone){
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);       // Print the value to the serial monitor
    Serial.print("JoyStick value     : ");
    Serial.println(mapped);
    Serial.println("");
    delay(100);  // Wait for 100 milliseconds before the next read
  }else{
    Joystick.setThrottle(mapped);
  }
}

void setup(){
  pinMode(potPin, INPUT);
  if(calculateDeadZone){
    Serial.begin(9600);  // Start serial communication at 9600 baud
  }else{
    Joystick.begin();
  }
}

void loop() {
  potValue = analogRead(potPin);  // Read the value from the potentiometer
  deadZone();
}
