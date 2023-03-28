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

unsigned long startTime = 0;
int newAngle = 0;
int positionMin = 0;
const int MOUVEMENT_SERVO = 200;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Setup Started"));
  //Motors Setup
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);
  //Arm servo-motors Setup
  servoinf.attach(9);
  servosup.attach(10);
  servoinf.write(65);
  servosup.write(80);
  delay(100);
  //Serial Port Setup
  while (!Serial) { delay(1); }  //This part does a test on the communication channel and the lox function in the Adafruit library. The code waits the Serial channel to open, and if the lox function does not work, the code blocks itself.
  //Laser Captor VL53L0X Setup
  if (!cd.begin()) {
    Serial.println(F("Failed to boot Captor VL53L0X"));
    while (1)
      ;
  }
  int distancelaser;
  Serial.println(F("Succeeded to boot Captor VL530X"));
  Serial.println(F("Setup Finished"));
}



void loop() {

  mvt.Forward();

  if (millis() - startTime > MOUVEMENT_SERVO) {
    cd.continuousScan(servoinf);
    cd.angleIncrement();
    int distancelaser = cd.getDist();
    Serial.print(F("dist vaut :"));
    Serial.println(distancelaser);

    if (distancelaser < 150) {
      mvt.AvanceBackward(1000);
      cd.scanSweep(servoinf);
      positionMin = cd.getMin();

      if (positionMin <= 4) {
        mvt.AvanceLeft(1000);
      }

      else {
        mvt.AvanceRight(1000);
      }

      cd.setAngle(4);
    }

    startTime = millis();
  }
}