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
  return measure.RangeMilliMeter;
}
/*
  VL53L0X_RangingMeasurementData_t measure;
  //Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
*/