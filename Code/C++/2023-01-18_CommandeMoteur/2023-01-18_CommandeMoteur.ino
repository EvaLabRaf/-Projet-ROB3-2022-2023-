#include "Mouvements.hpp"
#include "Capteurdistance.hpp"
#include "Adafruit_VL53L0X.h"
//#include "Servo.h"

//Servo
Servo servoinf;
Servo servosup;
//Moteurs Droit
int PWDD = 5;
int DIRD = 12;
//Moteurs Gauche
int PWDG = 6;
int DIRG = 13;
//Library
Mouvements mvt = Mouvements();
Capteurdistance cd = Capteurdistance();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Setup Started"));
  int Dist;
  //Motors Setup
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);
  //Arm servo-motors Setup
  servoinf.attach(9); servosup.attach(10);
  servoinf.write(75); servosup.write(90);
  //Serial Port Setup
  while (! Serial) {delay(1);}  //This part does a test on the communication channel and the lox function in the Adafruit library. The code waits the Serial channel to open, and if the lox function does not work, the code blocks itself.
  //Laser Captor VL53L0X Setup
  if (!cd.begin()) {Serial.println(F("Failed to boot Captor VL53L0X")); while(1);}

  Serial.println(F("Succeeded to boot Captor VL530X"));
  Serial.println(F("Setup Finished"));
}


void loop() {

  delay(100);
  int Dist = cd.distance();
  Serial.print(F("Distance Initial: ")); Serial.println(Dist);
  
  while (1) {
    int Dist = cd.distance();
    Serial.println(Dist);
    if (Dist >= 150){         //If nonobstacles are detected, the robot goes forward.
      mvt.Forward();
    }
    else if (Dist < 150){     //When an obstacle is detected by the laser, the robot take a step back and scan.
      mvt.AvanceBackward(1000);
      cd.scan(servoinf,servosup);
        //I than have to process the result of the scan to decide how to avoid the obstacle.
    }
   
  }
 
}
