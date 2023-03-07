#include "Mouvements.hpp"
#include "Capteurdistance.hpp"
#include "Adafruit_VL53L0X.h"
#include "Servo.h"

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

const int BACK_DURATION = 1000;       //Time will going back when detecting an obstacle.
bool goBack = false;                  //goBack indicate if the robot is going back.
unsigned long goBackStartTime = 0;

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
  servoinf.write(65); servosup.write(80);
  delay(100);
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
  

  Serial.println(Dist);                 //If no obstacles are detected and the robot is not going back, the robot goes forward.
  if (Dist >= 150 && !goBack){
    mvt.Forward();
  } 
  else if (Dist < 150 && !goBack){      //When an obstacle is detected by the laser and the robot is not going back, the robot take a starts going back.
    goBack = true;
    goBackStartTime = millis();
    mvt.Backward(); 
  } 
  else if(goBack){                      //When the robot is going back, he will stop himself after the time indicated by BACK_DURATION and process a scan                      
    if (millis() - goBackStartTime > BACK_DURATION){
      mvt.Off();
      goBack = false;
      cd.scantest(servoinf, servosup);      //I then have to process the result of the scan to decide how to avoid the obstacle.
      if (cd.scanTableau[0]>cd.scanTableau[8] || cd.scanTableau[0] == cd.scanTableau[8]){
      /*
      If the distance measured by the laser on the left side is superior to the right's one or if those distance are egale, 
      the robot will rotate at 90° on the right
      */        
        mvt.AvanceRight(1000);
      }
      else if(cd.scanTableau[2]>cd.scanTableau[0]){
        /*
        If the distance measured by the laser on the left side is inferior to the right's one, the robot will rotate at 90° on the left
        */
        mvt.AvanceLeft(1000);
      }
    }
  }
}