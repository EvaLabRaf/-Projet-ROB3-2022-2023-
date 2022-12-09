#ifndef CAPTEURDISTANCE_H
#define CAPTEURDISTANCE_H
#include "Arduino.h"
#include "Adafruit_VL53L0X.h"

class Capteurdistance{
  public:
    Capteurdistance();
    int InstantTime;
    void Forward();
};

#endif