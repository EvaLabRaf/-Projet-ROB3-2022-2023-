#include"Mouvements.hpp"
#include"Capteurdistance.hpp"
#include"Adafruit_VL53L0X.h"

//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;

//Timer
unsigned long InstantTime;  //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();

Mouvements mvt = Mouvements();
Capteurdistance cd = Capteurdistance();

void setup() {
  Serial.begin(9600);
  Serial.println("test setup");
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);
  int Dist;
/*
This part does a test on the communication channel and the lox function in the Adafruit library.
The code waits the Serial channel to open, and if the lox function does not work, the code blocks itself.
*/
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!cd.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println("Adafruit VL530X test passed");
}


void loop() {
  Serial.println("test loop");

  int Dist = cd.distance();
  Serial.println(Dist);
  mvt.AvanceForward();
  delay(1000); 

  //while ()

  /*
    if (measure.RangeStatus != 4) { mvt.Backward();break  }
    mvt.Right();
  */

  /*
  Serial.println(F("ForwardTest"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    mvt.Forward();
  }
  */
}
