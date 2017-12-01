#include <Arduino.h>

/*
 * EE302 Final Project
 * Automatic Line Following Robot
 *
 * Code written for Arduino Uno
 *
 * I/O Ports Used:
 *
 * | Port     | Destination   |     | Port     | Destination   |
 * |:--------:|:-------------:| --- |:--------:|:-------------:|
 * | D0       | MotorL Pin 1  |     | A0       | Left PhotoR   |
 * | D1       | MotorL Pin 2  |     | A1       | Middle PhotoR |
 * | D2       | MotorR Pin 1  |     | A2       | Right PhotoR  |
 * | D3       | MotorR Pin 2  |     | A3       | Left IR       |
 * | D4       |               |     | A4       | Middle IR     |
 * | D5       |               |     | A5       | Right IR      |
 * | D6       |               |     |          |               |
 * | D7       |               |     |          |               |
 * | D8       |               |     |          |               |
 * | D9       | MotorL Enable |     |          |               |
 * | D10      | MotorR Enable |     |          |               |
**/

// Initialize the functions and variables that will be used:

void blinkLED();      // Blinks LED
#define motorLPin1 0
#define motorLPin2 1
#define motorRPin1 2
#define motorRPin2 3
#define motorLEnable 9
#define motorREnable 10

int  photoLeft = 0;    // Analogs initialized as integers
int  photoMiddle = 1;
int  photoRight = 2;
int  irLeft = 3;
int  irMiddle = 4; 
int  irRight = 5; 

/*  SETUP
 * Performs initial setup of different variables and interfaces. Runs once. */
void setup() {

    pinMode(motorLEnable, OUTPUT);
    pinMode(motorREnable, OUTPUT);

    pinMode(motorLPin1, OUTPUT);
    pinMode(motorLPin2, OUTPUT);

    pinMode(motorRPin1, OUTPUT);
    pinMode(motorRPin2, OUTPUT);

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(A0, INPUT);  // It may not be requried to initialize these as inputs
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);

    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);

}


/* The next functions are to be called in the loop() or setup() routines: */


/*     adjustMotor
 * Adjusts motor speed depending on the gathered conditions from sensors. */
 void adjustMotor(){

   // . . . Get motor speed
   analogWrite(motorLEnable, 153);
   analogWrite(motorREnable, 255);

   digitalWrite(motorLPin1, HIGH);
   digitalWrite(motorLPin2, LOW);
   digitalWrite(motorRPin1, HIGH);
   digitalWrite(motorRPin2, LOW);           //call update sensors at the end of this to continue to poll8

}

/* blinkLED
 * Toggles the on-board led on for one second then turns it off. */
void blinkLED(){

   //function body
   digitalWrite(LED_BUILTIN, HIGH);   // sets the LED on
   delay(50);                         // waits for a second
   digitalWrite(LED_BUILTIN, LOW);    // sets the LED off
   delay(50);                         // waits for a second

}


void scanPhotoresistor(){

 float val_pr_left = analogRead(photoLeft);     // Not sure how to return these values from the function
 float val_pr_middle = analogRead(photoMiddle); // We need them outside of it, but I don't want to declare them
 float val_pr_right = analogRead(photoRight);  // As global variables

  
  if (val_pr_middle > /* minimum value of black reading */) && (val_pr_middle < /* maximum value of black reading */){      // Middle Reads black, check the other sides to figure out what way to turn

      if (val_pr_left > /* minimum value of black reading */) && (val_pr_left < /* maximum value of black reading */) /* and the other side is white */{ 
        //turn left function call
      }
       
      if (val_pr_right > /* minimum value of black reading */) && (val_pr_right < /* maximum value of black reading */) /*and the other side is white*/ {
        //turn right function call
      }
  }

  if (val_pr_middle > /*minimum value for red reading */) && (val_pr_middle < /* maximum value of red reading */){
      // stopMotor();  Need to define stop function

  }

  if (val_pr_middle > /*minimum value for white reading */) && (val_pr_middle < /*maximum value for white reading */){
      scanIRSensor();
  }
}

void scanIRSensor(){

float  val_ir_left = analogRead(irLeft);
float  val_ir_middle = analogRead(irMiddle);
float  val_ir_right = analogRead(irLeft);

  

}


/* updateData
 * This function gathers the most current contitions from each of the sensors. */
void updateData(){

    scanPhotoresistor();

    scanIRSensor();

}

/* LOOP
 * Main loop that is performed continuously after the device is
 * powered and the SETUP() function has been completed. */
void loop()
{

    blinkLED();       // Visually indicate the beginning of the program
    updateData();     // Gather newest sensor data
    adjustMotor();    // Sets left and right motor speed depending on desired direction

}
