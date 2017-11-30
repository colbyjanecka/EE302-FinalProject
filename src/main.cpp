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
**/

/*  SETUP
 * Performs initial setup of different variables and interfaces. Runs once. */
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

/* LOOP
 * Main loop that is performed continuously after the device is
 * powered and the SETUP() function has been completed. */
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
