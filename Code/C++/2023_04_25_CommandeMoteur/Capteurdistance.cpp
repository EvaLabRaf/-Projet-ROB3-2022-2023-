#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

/*
This library is used to manage the laser captor.
*/
int Capteurdistance::getAngle() {
  return anglePosition;
}

void Capteurdistance::setAngle(int angle) {
  anglePosition = angle;
}

int Capteurdistance::getDist() {
  return dist;
}

int Capteurdistance::getMin() {
  return min_i;
}

int Capteurdistance::distance() {            //This function measure the distance between the laser and the object in front of it.
  VL53L0X_RangingMeasurementData_t measure;  //Create the class measure from the Adafruit library.
  rangingTest(&measure, false);              //Function from Adafruit to measure.
  return measure.RangeMilliMeter;
  Serial.println("Mesure distance");
  Serial.println(measure.RangeMilliMeter);
}

int Capteurdistance::scanSweep(Servo servoinf) {
  Serial.println(F("==> scanSweep"));
  int i = 0;
  min_v = 9000;
  min_i = 0;

  for (int servoInfPosition = infAngleMin; servoInfPosition <= infAngleMax; servoInfPosition += infPas) {
    servoinf.write(servoInfPosition);
    delay(150);
    scanTableau[i] = distance();
    Serial.print(F("La valeur de i = "));
    Serial.print(i);
    Serial.print(F(" est : "));
    Serial.println(scanTableau[i]);
    if (scanTableau[i] < min_v) {
      min_v = scanTableau[i];
      min_i = i;
    }
    i++;
  }

  Serial.print("La valeur min est ");
  Serial.print(min_v);
  Serial.print(" et elle est en position ");
  Serial.println(min_i);
  Serial.println(F("==> scanSweep finished"));
  servoinf.write(65);
}

int Capteurdistance::continuousScan(Servo servoinf) {
  int k = 0;

  while (k <= anglePosition) {
    servoInfPosition = infAngleMin + k * infPas;
    k++;
  }

  servoinf.write(servoInfPosition);
  dist = distance();
  return (dist);
}

int Capteurdistance::angleIncrement() {

  if (sensScan == true) {
    anglePosition++;
    if (anglePosition >= lenghtScanTableau + 1) {
      sensScan = false;
      anglePosition--;
    }
  }
  
  else if (sensScan == false) {
    anglePosition=anglePosition - 1;
    if (anglePosition < 0) {
      sensScan = true;
      anglePosition++;
    }
  }  
}