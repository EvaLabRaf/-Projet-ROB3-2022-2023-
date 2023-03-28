#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

/*
This library is used to manage the laser captor.
*/
int Capteurdistance::getAngle() {
  return anglePosition;
}

/**
 * @brief 
 * 
 * @param angle 
 */
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

int Capteurdistance::scan(Servo servoinf, Servo servosup) {  //This function manage the 2 axis arm into angles from 40° in height and 120° on sides.
  Serial.println(F("Processing scan"));
  int i = 0;
  for (int servoSupPosition = supAngleMin; servoSupPosition <= supAngleMax; servoSupPosition += supPas) {  //height angles 5 positions.
    servosup.write(servoSupPosition);
    delay(100);
    for (int servoInfPosition = infAngleMin; servoInfPosition <= infAngleMax; servoInfPosition += infPas) {  //side angles 13 positions.
      servoinf.write(servoInfPosition);
      delay(150);
      dist = distance();  //Measure the distance from the obstacle for each position
      Serial.println(dist);
      scanTableau[i] = dist;
      i = i + 1;
    }
    delay(300);
    Serial.println(i);
  }
  Serial.println();
  servoinf.write(65);
  servosup.write(80);
}

int Capteurdistance::scanSweep(Servo servoinf) {
  Serial.println(F("Processing scan test"));
  int i = 0;
  for (int servoInfPosition = infAngleMin; servoInfPosition <= infAngleMax; servoInfPosition += infPas) {  //side angles 13 positions.
    servoinf.write(servoInfPosition);
    delay(150);
    dist = distance();  //Measure the distance from the obstacle for each position
    Serial.print(i);
    Serial.print("  ");
    Serial.print(dist);
    scanTableau[i] = dist;
    Serial.print("  ");
    Serial.println(scanTableau[i]);
    i++;
  }

  for (int j = 0; j < lenghtScanTableau; j++) {
    Serial.print(F("La valeur de i vaut: "));
    Serial.println(j);
    Serial.print(F("La valeur de scanTableau vaut: "));
    Serial.println(scanTableau[j]);
    if (scanTableau[j] < min_v) {
      min_v = scanTableau[j];
      min_i = j;
    }
  }

  Serial.print("La valeur min est : ");
  Serial.println(min_v);
  Serial.print("Elle est en position ");
  Serial.println(min_i);
  Serial.println(F("Scan finished"));
  servoinf.write(65);
}

int Capteurdistance::continuousScan(Servo servoinf) {
  Serial.println(F("Processing continuousScan"));
  int i = 0;

  Serial.print("anglePosition vaut : ");
  Serial.println(anglePosition);

  while (i <= anglePosition) {
    servoInfPosition = infAngleMin + i * infPas;
    i++;
  }

  servoinf.write(servoInfPosition);
  dist = distance();
  Serial.println(dist);
  return (dist);
}

int Capteurdistance::angleIncrement() {
  int i = 0;

  if (sensScan = true) {
    anglePosition++;

    if (anglePosition > lenghtScanTableau) {
      sensScan = false;
      anglePosition = anglePosition - 1;
    }
  }
  
  else if (sensScan = false) {
    anglePosition--;

    if (anglePosition < -1) {
      sensScan = true;
      anglePosition = anglePosition + 1;
    }
  }  
}