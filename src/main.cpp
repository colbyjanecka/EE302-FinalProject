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
   analogWrite(motorLEnable, 115);      // I think it's best to call this in the if statements rather than in the adjustmotor function so that they're aren't any infinite loops.
   analogWrite(motorREnable, 115);



  if (s == 1){
    digitalWrite(motorLPin1, LOW);
    digitalWrite(motorLPin2, HIGH);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);
    analogWrite(motorLEnable, 90);

    //scanIRFrontSensor();

  }
  else if (s == 2) {
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, LOW);
    digitalWrite(motorRPin2, HIGH);
    analogWrite(motorREnable, 90);

    //scanIRFrontSensor();

  }
  else if (s == 3){
    digitalWrite(motorLPin1, LOW);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, LOW);
    digitalWrite(motorRPin2, LOW);

    //scanIRFrontSensor();
  }
  else if (s == 4){       // Slight Left Turn
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);
    analogWrite(motorLEnable, 80);
    analogWrite(motorREnable, 200);
  }
  else if (s == 5){       //Slight Right Turn
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);
    analogWrite(motorLEnable, 140);
    analogWrite(motorREnable, 80);
<<<<<<< HEAD
  }
  else if (s == 6){
    digitalWrite(motorLPin1, LOW);
    digitalWrite(motorLPin2, HIGH);
    digitalWrite(motorRPin1, LOW);
    digitalWrite(motorRPin2, HIGH);
=======
>>>>>>> 6f2d62a57e2164890f9a0f3b27c5c9b7a2ae10e1
  }
  else {
    digitalWrite(motorLPin1, HIGH);
    digitalWrite(motorLPin2, LOW);
    digitalWrite(motorRPin1, HIGH);
    digitalWrite(motorRPin2, LOW);

    //scanIRFrontSensor();
  }

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

void scanIRSideSensor(){

  Serial.println("Scanning IR Side Sensors");

  float  val_ir_left = analogRead(irLeft);
  float  val_ir_right = analogRead(irRight);

  if (val_ir_left > val_ir_right) {

  //Call right turn function
  adjustMotor(5);

  }

  else if (val_ir_left < val_ir_right){

    //Call left turn function
    adjustMotor(4);
  }

  else if (val_ir_left == val_ir_right){

    //Call straight turn function
    adjustMotor(0);
  }
}

void scanIRFrontSensor(){

    float val_ir_middle = analogRead(irMiddle);

  if(val_ir_middle > 500){
      //Call stop function
      adjustMotor(3);
  }

  else {

  //Call Straight turn function //Maybe just going back to the main loop would be best for this condition so that we don't get stuck in an infinite loop.
    adjustMotor(0);
  }
}

void scanPhotoresistor(){

 float val_pr_left = analogRead(photoLeft);     // Not sure how to return these values from the function
 float val_pr_middle = analogRead(photoMiddle); // We need them outside of it, but I don't want to declare them
 float val_pr_right = analogRead(photoRight);  // As global variables

 float val_ir_middle = analogRead(irMiddle);



<<<<<<< HEAD
 //Serial.println(val_pr_left);
 Serial.println(val_pr_middle);
=======
 Serial.println(val_pr_left);
 //Serial.println(val_pr_middle);
>>>>>>> 6f2d62a57e2164890f9a0f3b27c5c9b7a2ae10e1
 //Serial.println(val_pr_right);
 //Serial.println(val_pr_left + val_pr_middle + val_pr_right);

  //if (val_pr_middle > 650 /* minimum value of black reading */){      // Middle Reads black, check the other sides to figure out what way to turn
    //if ((val_pr_left < 700 /* maximum value of red reading */) && (val_pr_left > 600 /* maximum value of red reading */) && (val_pr_middle < 700) && (val_pr_middle > 600) &&  (val_pr_right < 700) && (val_pr_right > 600) || (val_ir_middle > 600)){
<<<<<<< HEAD
    if ((val_pr_left < 625/* maximum value of red reading */) && (val_pr_left > 525 /* maximum value of red reading */) && (val_pr_middle < 625) && (val_pr_middle > 550) || (val_pr_middle < 625) && (val_pr_middle > 550) && (val_pr_right < 700) && (val_pr_right > 625) || (val_ir_middle > 575)){
=======
    if ((val_pr_left < 600/* maximum value of red reading */) && (val_pr_left > 525 /* maximum value of red reading */) && (val_pr_middle < 650) && (val_pr_middle > 600) || (val_pr_middle < 650) && (val_pr_middle > 600) && (val_pr_right < 700) && (val_pr_right > 640) || (val_ir_middle > 580)){
>>>>>>> 6f2d62a57e2164890f9a0f3b27c5c9b7a2ae10e1

      adjustMotor(6);
      delay(200);
      adjustMotor(3);
      delay(1000);
      Serial.println(" Queue Stop Function");
      }



      else if (val_pr_left > 550 /* minimum value of black reading */){

        //turn left function call
        Serial.println(" Queue Turn Left Function");
        adjustMotor(1);

        }

      else if (val_pr_right > 550 /* right reading differently, thfre more  */){
        //turn right function call
        Serial.println(" Queue Turn Right Function");
        adjustMotor(2);
      }

      else if ((val_pr_middle < 500 /*maximum value for white reading */) && (val_pr_left < 500) && (val_pr_right < 500)){
          adjustMotor(0);
          //elay(300);
           scanIRSideSensor();
      }

        else /** if ((val_pr_middle > 550) && (val_pr_left < 550) && (val_pr_right < 550)) **/ {

        adjustMotor(0);

        }



}

/* updateData
 * This function gathers the most current contitions from each of the sensors. */
void updateData(){

    //scanIRFrontSensor();

    scanPhotoresistor();

  //  scanIRSideSensor();

    //scanIRFrontSensor();

}

void motorTest(){

    adjustMotor(1);    // Turn Left
    delay(5000);
    adjustMotor(2);   //Turn right
    delay(5000);
    adjustMotor(3);   //Go Straight
    delay(5000);
  }


/* LOOP
 * Main loop that is performed continuously after the device is
 * powered and the SETUP() function has been completed. */
void loop()
{

    blinkLED();       // Visually indicate the beginning of the program
    updateData();     // Gather newest sensor data
    //motorTest();

}
