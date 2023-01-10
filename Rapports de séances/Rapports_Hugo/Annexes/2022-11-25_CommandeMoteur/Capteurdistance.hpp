#ifndef CAPTEURDISTANCE_H
#define CAPTEURDISTANCE_H
#include "Arduino.h"
#include "Adafruit_VL53L0X.h"

class Capteurdistance : public Adafruit_VL53L0X {
  public:
    Capteurdistance();
    //Adafruit_VL53L0X lox = Adafruit_VL53L0X();
    int distance();
    int frontdistance;
};

#endif