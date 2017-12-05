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

#define motorLPin1 2
#define motorLPin2 3
#define motorRPin1 4
#define motorRPin2 5
#define motorLEnable 9
#define motorREnable 10


const int  photoLeft = 0;    // Analogs initialized as integers
const int  photoMiddle = 1;
const int  photoRight = 2;
const int  irLeft = 3;
const int  irMiddle = 4;
const int  irRight = 5;

/*  SETUP
 * Performs initial setup of different variables and interfaces. Runs once. */
void setup() {

    String direction;

    Serial.begin(9600);           // Start Console

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
 int adjustMotor(int s){

   // . . . Get motor speed
   analogWrite(motorLEnable, 100);
   analogWrite(motorREnable, 100);


  if (s == 1){
    digitalWrite(motorLPin1, LOW);
    digitalWrite(motorLPin2, HIGH);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);

  }
  else if (s == 2) {
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, LOW);
    digitalWrite(motorRPin2, HIGH);

  }
  else if (s == 3){
    digitalWrite(motorLPin1, LOW);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, LOW);
    digitalWrite(motorRPin2, LOW);
  }
  else {
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);
  }

//  scanPhotoresistor();
//  scanIRFrontSensor();        //call update sensors at the end of this to continue to poll8

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

 //Serial.println(val_pr_left);
 //Serial.println(val_pr_middle);
 //Serial.println(val_pr_right);

  //if (val_pr_middle > 650 /* minimum value of black reading */){      // Middle Reads black, check the other sides to figure out what way to turn

      if (val_pr_left > 600 /* minimum value of black reading */){

        //turn left function call
        Serial.println(" Queue Turn Left Function");
        adjustMotor(1);

        }

      if (val_pr_right > 600/* right reading differently, thfre more  */){
        //turn right function call
        Serial.println(" Queue Turn Right Function");
        adjustMotor(2);
        }

      else{

        adjustMotor(0);

      }

 // }

  if ((val_pr_middle > 400 /*minimum value for red reading */) && (val_pr_middle < 475 /* maximum value of red reading */)){

      // stopMotor();  Need to define stop function
      Serial.println(" Queue Stop Function");
      adjustMotor(3);
  }

  if ((val_pr_middle < 350 /*maximum value for white reading */) && (val_pr_left < 350) && (val_pr_right <350)){
      // run scanIRSideSensor();s
  }

}

void scanIRSideSensor(){

  float  val_ir_left = analogRead(irLeft);
  float  val_ir_right = analogRead(irLeft);

  if(val_ir_left > val_ir_right){

  //Call right turn function
  adjustMotor(2);

  }

  if(val_ir_left < val_ir_right){

    //Call left turn function
    adjustMotor(1);
  }

  else{

    //Call straight turn function
    adjustMotor(0);
  }
}

void scanIRFrontSensor(){

  float val_ir_middle = analogRead(irMiddle);

  if(val_ir_middle > 2.48){
      //Call stop function
      adjustMotor(3);
  }

  else{

  //Call Straight turn function
    adjustMotor(0);
  }
}


/* updateData
 * This function gathers the most current contitions from each of the sensors. */
void updateData(){

    scanPhotoresistor();

  //  scanIRSideSensor();

//    scanIRFrontSensor();

}

void motorTest(){

    adjustMotor(1);    // Turn Left
    delay(5000);
    adjustMotor(2);   //Turn right
    delay(5000);
    adjustMotor(0);   //Go Straight
    delay(5000);
  }


/* LOOP
 * Main loop that is performed continuously after the device is
 * powered and the SETUP() function has been completed. */
void loop()
{

    blinkLED();       // Visually indicate the beginning of the program
    updateData();     // Gather newest sensor data

}
