#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){
  // wait until serial port opens for native USB devices
  
  //Serial.println("test Adafruit VL53L0X");
  /*
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
  */
};

int Capteurdistance::distance() {
  Serial.println("test distance");
  VL53L0X_RangingMeasurementData_t measure;
  rangingTest(&measure, false);
  //return measure.RangeMilliMeter;
  return 1;
  }