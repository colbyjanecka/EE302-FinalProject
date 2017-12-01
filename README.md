# EE302-FinalProject

### Objective:

Automatic Line Following Robot

### This Repo:

This Project contains Code written for Arduino Uno which is used to control our
robot, including supplying PVM-modulated power to both of the motors depending
on the current readings from different sensors used.

You can find the code in [/src/main.cpp](https://github.com/colbyjanecka/EE302-FinalProject/blob/master/src/main.cpp)

### Parts List:

* Arduino Uno (Rev3)
   *Used instead of MyDAQ, due to easier interfacing and programming*
* 2 x DC Motor
* 1 x L293D H-Bridge IC
* 4 x AA Battery
* 1 x AA Battery Case (4xAA)
* 1 x 9V Battery
* 1 x Flex Sensor
* 1 x GPZY0A0ZYK0F IR Distance Sensor
* 2 x Photo-resistors

### Arduino I/O Ports Used:

| Port     | Destination   |     | Port     | Destination   |
|:--------:|:-------------:| --- |:--------:|:-------------:|
| D0       | MotorL Pin 1  |     | A0       |               |
| D1       | MotorL Pin 2  |     | A1       |               |
| D2       | MotorR Pin 1  |     | A2       |               |
| D3       | MotorR Pin 2  |     | A3       |               |
| D4       |               |     |          |               |
| D5       |               |     |          |               |
| D6       |               |     |          |               |
| D7       |               |     |          |               |
