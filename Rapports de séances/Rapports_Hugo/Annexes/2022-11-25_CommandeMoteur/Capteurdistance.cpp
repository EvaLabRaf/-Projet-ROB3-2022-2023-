#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

int Capteurdistance::distance() {
  
  VL53L0X_RangingMeasurementData_t measure;
  rangingTest(&measure, false);
  return measure.RangeMilliMeter;
  Serial.println("Mesure distance"); Serial.println(measure.RangeMilliMeter);
}
