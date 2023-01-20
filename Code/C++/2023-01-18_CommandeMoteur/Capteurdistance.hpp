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
    int servoinfposition=0;
    int servosupposition=0;
};

#endif