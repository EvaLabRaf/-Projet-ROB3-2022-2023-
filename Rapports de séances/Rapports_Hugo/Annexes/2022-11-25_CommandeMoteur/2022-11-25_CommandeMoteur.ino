#include"Mouvements.hpp"
//#include"Capteurdistance.hpp"
#include "Adafruit_VL53L0X.h"

//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;
//Timer
unsigned long InstantTime;  //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

Mouvements mvt = Mouvements();
//Capteurdistance cd;

void setup() {
  Serial.begin(9600);
  Serial.println("test setup");
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);

  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 

  //cd = Capteurdistance();
}


void loop() {
  Serial.println("test loop");

  //Serial.println(cd.distance());
  VL53L0X_RangingMeasurementData_t measure;
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
  //while ()
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    mvt.Forward();
  }

  Serial.println(F("Backward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    mvt.Backward();
  }

  Serial.println(F("Left"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    mvt.Left();
  }

  Serial.println(F("Right"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    
    if (measure.RangeStatus != 4) { mvt.Backward();break  }
    mvt.Right();
}
