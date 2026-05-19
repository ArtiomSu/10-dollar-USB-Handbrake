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


// instead of outputting the throttle, output the a button instead. This is handy for games that are more arcade and dont support proper handbrake.
// dont change this value manually, it will be set to 1 or 0 in the setupMode function depending on the position of the potentiometer. This way you can change modes on the fly.
int useButtonOutput = 0;

// this is for the button output mode.
const int buttonToPress = 0; // 0 is the "A" button on the xbox controller.

// this is for the button output mode.
const int buttonDeadZone = 5; // the size of the deadzone for the button output, leave a small deadzone to prevent accidental triggering of the button. reduce this value if you want a more sensitive button output, increase it if you want a less sensitive button output.

int potValue = 0;
int buttonState = 0;

void deadZone(){
  int mapped = getMappedValue();
  if(calculateDeadZone){
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);       // Print the value to the serial monitor
    Serial.print("JoyStick value     : ");
    Serial.println(mapped);
    Serial.println("");
    delay(100);  // Wait for 100 milliseconds before the next read
  }else if(useButtonOutput){
    if(flip ? mapped > buttonDeadZone : mapped < (255 - buttonDeadZone)){ // leave a small deadzone of 10 to prevent accidental triggering of the button
      buttonState = 1;
    }else{
      buttonState = 0;
    }
    Joystick.setButton(buttonToPress, buttonState);
  }else{
    Joystick.setThrottle(mapped);
  }
}

int getMappedValue(){
  int potContrained = constrain(potValue,minValue,maxValue);
  int mapped = 0; 
  if(flip){
    mapped = map(potContrained,maxValue,minValue,0,255);
  }else{
    mapped = map(potContrained,minValue,maxValue,0,255);
  }
  return mapped;
}

void setupMode(){
  potValue = analogRead(potPin);
  int mapped = getMappedValue();
  if(flip ? mapped > 100: mapped < (255 - 100)){
    useButtonOutput = 1;
  }else{
    useButtonOutput = 0;
  }
}

void setup(){
  pinMode(potPin, INPUT);
  if(calculateDeadZone){
    Serial.begin(9600);  // Start serial communication at 9600 baud
  }else{
    Joystick.begin();
    setupMode();
  }
}

void loop() {
  potValue = analogRead(potPin);  // Read the value from the potentiometer
  deadZone();
}
