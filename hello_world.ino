/*

Name: Ishan Vyas
UCID: 30068270
Course: CPSC 599.88
Project: Hello World
Due Date: January 27th, 2022

*/

// Include the servo library
#include <Servo.h>

// Declare the pins for the button, LED and the Servo (constant because values don't change)
const int buttonPin = 4;
const int ledPin = 2;
const int servoPin = 3;

// Create a new servo
Servo Servo1;

// Initialize the servoPosition to 0
int servoPosition = 0;

// Flag to trigger different directions of rotation
bool rotate = false;

// Code setup
void setup()
{
  // Attach the servo pin
  Servo1.attach(servoPin);

  // Change the servo's position to the initial position declared 
  Servo1.write(servoPosition);

  Serial.begin(9600);


  // Set LED pin as output and button pin as input
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// Loop
void loop()
{
  // Variable to keep track of the button state
  int buttonState = digitalRead(buttonPin);

  // Print servo position to console
  Serial.println(servoPosition);

  // If the button is pressed (HIGH) light the LED and start rotating the hand
  if(buttonState == HIGH ){

    // Turn on the LED
    digitalWrite(ledPin, HIGH);

    // Write the servo's position to the servo
    Servo1.write(servoPosition);

    // If the servo is less than 90, rotate left
    if(servoPosition < 90 && rotate == false){

      // Increment servo position
      servoPosition++;
        
    }
    // Else rotate right
    else{
      
      if(servoPosition >= 0 && rotate == true){

        // Decrement servo position
        servoPosition--;
        
      }
    }

    // Switch direction of rotation
    if(servoPosition == 0){
      
      rotate = false;
        
    }

    // Switch direction of rotation
    if(servoPosition == 90){
      
      rotate = true;
        
    }

    // Delay for 5 milliseconds
    delay(5);
    
  }
  // If the button is not pressed (LOW) then turn off the LED and stop rotating
  else{

    // Turn off the LED
    digitalWrite(ledPin,LOW);
    
  }
}
