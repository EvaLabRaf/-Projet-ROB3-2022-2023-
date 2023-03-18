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
    int getAngle();
    void setAngle(int angle);
    int scan(Servo servoinf, Servo servosup);
    int scantest(Servo servoinf, Servo servosup);
    int continuousScan(Servo servoinf);
    int servoInfPosition=0;
    int servoSupPosition=0;
    int Dist;
    static const int lenghtScanTableau = 9;
    int anglePosition = 0;
    int infAngleMin = 1;
    int infAngleMax = 129;
    int infPas = 16;
    int supAngleMin = 80;
    int supAngleMax = 120;
    int supPas = 10;
    int scanTableau[lenghtScanTableau]; 
    int min_v = 9000;
	  int min_i = 0;
    int i=0;
};

#endif