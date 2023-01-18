#include "Mouvements.hpp"
#include "Capteurdistance.hpp"
#include "Adafruit_VL53L0X.h"
#include "Servo.h"

//Servo
Servo servoinf;
Servo servosup;
//Moteurs Droit
int PWDD = 9;
int DIRD = 7;
//Moteurs Gauche
int PWDG = 10;
int DIRG = 8;
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

  //Booting Scanner
  servoinf.attach(5); servosup.attach(6);
  servoinf.write(75); servosup.write(90);
  int Dist;
 
  
  //This part does a test on the communication channel and the lox function in the Adafruit library. The code waits the Serial channel to open, and if the lox function does not work, the code blocks itself.
  while (! Serial) {delay(1);}
  
  //Booting Adafruit VL53L0X test
  if (!cd.begin()) {Serial.println(F("Failed to boot Captor VL53L0X")); while(1);}
  Serial.println(F("Succeeded to boot Captor VL530X"));

  Serial.println(F("Setup Finished"));
}


void loop() {

  delay(100);
  int Dist = cd.distance();
  Serial.print(F("Distance Initial: ")); Serial.println(Dist);

  mvt.AvanceForward(2000);
  delay(100);
  cd.scan(servoinf, servosup);
  /*
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
 
  /*
    if (measure.RangeStatus != 4) { mvt.Backward();break  }
    mvt.Right();
  */

}
