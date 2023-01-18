#include"Mouvements.hpp"
#include"Capteurdistance.hpp"
#include"Adafruit_VL53L0X.h"
#include"Servo.h"


//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;
//Timer
unsigned long InstantTime;  //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1
//Library
Mouvements mvt = Mouvements();
Capteurdistance cd = Capteurdistance();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Setup Started"));
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

  /*
  Adafruit VL53L0X test
  */
  if (!cd.begin()) {
    Serial.println(F("Failed to boot Captor VL53L0X"));
    while(1);
  }
  Serial.println(F("Succeeded to boot Captor VL530X"));

  Serial.println(F("Setup Finished"));
}


void loop() {

  int Dist = cd.distance();
  Serial.print(F("Distance Initial: ")); Serial.println(Dist);

  mvt.AvanceForward(2000);

  while (1) {
    //mvt.Forward();
    int Dist = cd.distance();
    Serial.println(Dist);
    if (Dist > 150){
      mvt.Forward();
    }
    else if (Dist < 150){
      mvt.AvanceBackward(2000);
    }
   
  }
  
  mvt.Off();

  

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
