#include "Mouvements.hpp"
#include "Adafruit_VL53L0X.h"
#include "Capteurdistance.hpp"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();


//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;

Mouvements cl;

void setup() {
Serial.begin(9600);
pinMode(PWDD, OUTPUT);
pinMode(DIRD, OUTPUT);
pinMode(PWDG, OUTPUT);
pinMode(DIRG, OUTPUT);
// wait until serial port opens for native USB devices
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
}


void loop() {
  cl.Forward();
  cl.Backward();
  cl.Left();
  cl.Right();
}
