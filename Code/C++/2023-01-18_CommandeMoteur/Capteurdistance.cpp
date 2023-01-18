#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

int Capteurdistance::distance(){
  
  VL53L0X_RangingMeasurementData_t measure;
  rangingTest(&measure, false);
  return measure.RangeMilliMeter;
  Serial.println("Mesure distance"); Serial.println(measure.RangeMilliMeter);
}

int Capteurdistance::scan(Servo servoinf, Servo servosup){
  Serial.println(F("Processing scan"));

  for (int servosupposition = 80; servosupposition <= 120; servosupposition += 10) {
    servosup.write(servosupposition);
    Serial.println(servosupposition);
    for (int servoinfposition = 20; servoinfposition <= 140; servoinfposition += 10) {
      servoinf.write(servoinfposition);
      //Serial.println(servoinfposition);
      delay(300);
    }
    delay(100);
  }
  servoinf.write(75);
  servosup.write(90);
}