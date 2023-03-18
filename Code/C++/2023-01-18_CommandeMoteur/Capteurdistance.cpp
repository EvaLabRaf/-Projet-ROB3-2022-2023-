#include "Capteurdistance.hpp"

Capteurdistance::Capteurdistance(){};

/*
This library is used to manage the laser captor.
*/
int Capteurdistance::getAngle(){
  return anglePosition;
}

void Capteurdistance::setAngle(int angle){
  anglePosition = angle;
}

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
    for (int servoInfPosition = infAngleMin; servoInfPosition <= infAngleMax; servoInfPosition += infPas) {  //side angles 13 positions.
      servoinf.write(servoInfPosition);
      delay(150);
      Dist = distance();    //Measure the distance from the obstacle for each position 
      Serial.println(Dist);
      scanTableau[i]=Dist;
      i=i+1;
    }
    delay(300);
  Serial.println(i); 
  }
  Serial.println();
  servoinf.write(65);
  servosup.write(80);
}

int Capteurdistance::scantest(Servo servoinf, Servo servosup){
  Serial.println(F("Processing scan test"));
  int i = 0;
  for (int servoInfPosition = infAngleMin; servoInfPosition <= infAngleMax; servoInfPosition += infPas) {  //side angles 13 positions.
    servoinf.write(servoInfPosition);
    delay(500);
    Dist = distance();    //Measure the distance from the obstacle for each position 
    Serial.println(Dist);
    scanTableau[i]=Dist;
    i=i++;
  }
  delay(100);

	for (int i = 0; i < lenghtScanTableau; i++)
	{
		if ( scanTableau[i] < min_v )
		{
			min_v = scanTableau[i];
			min_i = i;
		}
  }
  Serial.print("La valeur min est : ");
  Serial.println(min_v);
  Serial.print("Elle est en position ");
  Serial.println(min_i);
  Serial.println(F("Scan finished"));
  servoinf.write(65);
  servosup.write(80);
}

int Capteurdistance::continuousScan(Servo servoinf){
  Serial.println(F("Processing continuousScan"));
  int i = 0;

  Serial.print("anglePosition vaut : "); Serial.println(anglePosition);

  if (anglePosition >= lenghtScanTableau)
    {
      anglePosition = 0;
      Serial.println("Test if");
    }

  
  while (i <= anglePosition)
    {
      servoInfPosition = infAngleMin + i * infPas;
      i++;
    }
  
  servoinf.write(servoInfPosition);
  Dist = distance();
  Serial.println(Dist);
}