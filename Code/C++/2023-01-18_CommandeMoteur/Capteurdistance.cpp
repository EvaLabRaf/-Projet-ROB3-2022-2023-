#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

/*
This library is used to manage the laser captor.
*/

int Capteurdistance::distance(){    //This function measure the distance between the laser and the object in front of it.
  VL53L0X_RangingMeasurementData_t measure;   //Create the class measure from the Adafruit library.
  rangingTest(&measure, false);               //Function from Adafruit to measure.
  return measure.RangeMilliMeter;
  Serial.println("Mesure distance"); Serial.println(measure.RangeMilliMeter);
}

int Capteurdistance::scan(Servo servoinf, Servo servosup){    //This function manage the 2 axis arm into angles from 40° in height and 120° on sides.
  Serial.println(F("Processing scan"));
  for (int servosupposition = 80; servosupposition <= 120; servosupposition += 10) {  //height angles 5 positions.
    servosup.write(servosupposition);
    for (int servoinfposition = 20; servoinfposition <= 140; servoinfposition += 10) {  //side angles 13 positions.
      servoinf.write(servoinfposition);
      delay(150);
      //There I have to measure the distance and put it in a table.
    }
    delay(300);
  }
  servoinf.write(75);
  servosup.write(90);
}