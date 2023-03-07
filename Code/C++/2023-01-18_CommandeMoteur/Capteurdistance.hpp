#ifndef CAPTEURDISTANCE_H
#define CAPTEURDISTANCE_H
#include "Arduino.h"
#include "Adafruit_VL53L0X.h"
#include "Servo.h"

/*

*/

class Capteurdistance : public Adafruit_VL53L0X {
  public:
    Capteurdistance();
    int distance();
    int scan(Servo servoinf, Servo servosup);
    int scantest(Servo servoinf, Servo servosup);
    int servoInfPosition=0;
    int servoSupPosition=0;
    int Dist;
    int infAngleMin = 1;
    int infAngleMax = 129;
    int infPas = 16;
    int supAngleMin = 80;
    int supAngleMax = 120;
    int supPas = 10;
    int scanTableau[9]; 
    int i=0;
};

#endif