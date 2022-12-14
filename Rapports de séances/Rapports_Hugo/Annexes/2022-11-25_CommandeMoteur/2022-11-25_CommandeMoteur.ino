#include"Mouvements.hpp"
#include"Capteurdistance.hpp"

//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;
//Timer
unsigned long InstantTime;  //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1

Mouvements mvt = Mouvements();
Capteurdistance cd;

void setup() {
  Serial.begin(9600);
  Serial.println("test setup");
  pinMode(PWDD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWDG, OUTPUT);
  pinMode(DIRG, OUTPUT);
  cd = Capteurdistance();
}


void loop() {
  
  Serial.println(cd.distance());

  //while ()
  Serial.println("Forward");
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<3000) {
    mvt.Forward();
  }

  Serial.println("Backward");
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<3000) {
    mvt.Backward();
  }

  Serial.println("Left");
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<3000) {
    mvt.Left();
  }

  Serial.println("Right");
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<3000) {
    mvt.Right();
  }
}
