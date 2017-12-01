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
 * | D0       | MotorL Pin 1  |     | A0       |               |
 * | D1       | MotorL Pin 2  |     | A1       |               |
 * | D2       | MotorR Pin 1  |     | A2       |               |
 * | D3       | MotorR Pin 2  |     | A3       |               |
 * | D4       |               |     |          |               |
 * | D5       |               |     |          |               |
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
   digitalWrite(motorRPin2, LOW);

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

}

void scanIRSensor(){

}

void scanFlexSensor(){

}

/* updateData
 * This function gathers the most current contitions from each of the sensors. */
void updateData(){

    scanPhotoresistor();

    scanIRSensor();

    scanFlexSensor();

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
