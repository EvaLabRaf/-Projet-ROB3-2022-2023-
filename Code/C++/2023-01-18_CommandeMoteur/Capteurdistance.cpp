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
  int i = 0;
  for (int servoSupPosition = supAngleMin; servoSupPosition <= supAngleMax; servoSupPosition += supPas) {  //height angles 5 positions.
    servosup.write(servoSupPosition);
    delay(100);
    for (int servoInfPosition = infAngleMin; servoInfPosition <= supAngleMax; servoInfPosition += supPas) {  //side angles 13 positions.
      servoinf.write(servoInfPosition);
      delay(150);
      Dist = distance();    //Measure the distance from the obstacle for each position 
      Serial.println(Dist);
      scanTableau[i]=Dist;
      i=i+1;
      //Then I have to process the distance and maybe put them in a table.
    }
    delay(300);
  Serial.println(i); 
  }
  Serial.println()
  servoinf.write(75);
  servosup.write(90);
}