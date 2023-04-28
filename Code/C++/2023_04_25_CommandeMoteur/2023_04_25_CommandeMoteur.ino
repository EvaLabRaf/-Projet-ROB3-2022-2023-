#include "Capteurdistance.hpp"
#include "Adafruit_VL53L0X.h"
#include "Servo.h"
#include "Gps.hpp"
#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "Mouvements.hpp"

//Servo
Servo servoinf;
//Moteurs Droit
int PWDD = 5;
int DIRD = 12;
//Moteurs Gauche
int PWDG = 6;
int DIRG = 13;
//Interupteur
int interupteur = 7;
//Library
Mouvements mvt = Mouvements();
Capteurdistance cd = Capteurdistance();
Gps gps = Gps();

unsigned long startTime = 0;
int positionMin = 0;
const int DEPLACEMENT_SERVO = 100;

static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Setup Started"));
  //Motors Setup
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);
  //Interupter Setup
  pinMode(interupteur, INPUT);
  //Arm servo-motors Setup
  servoinf.attach(9);
  servoinf.write(65);
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
  gps.begin();
  }



void loop() {

  mvt.forward();

  if (millis() - startTime > DEPLACEMENT_SERVO) {
    cd.continuousScan(servoinf);
    cd.angleIncrement();
    int distancelaser = cd.getDist();
    //Serial.print(F("dist vaut :"));
    //Serial.println(distancelaser);

    if (distancelaser < 200) {
      Serial.println(F("Object in range"));
      mvt.avanceBackward(1000);
      cd.scanSweep(servoinf);
      positionMin = cd.getMin();

      if (positionMin <= 4) {
        mvt.avanceLeft(1000);
      }

      else {
        mvt.avanceRight(1000);
      }

      cd.setAngle(4);
    }

    startTime = millis();
  }
}