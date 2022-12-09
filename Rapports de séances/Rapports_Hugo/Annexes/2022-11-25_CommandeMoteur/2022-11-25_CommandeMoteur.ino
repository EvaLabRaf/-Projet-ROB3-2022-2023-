#include"Mouvements.hpp"
//Moteurs Droit
int PWDD = 10;
int DIRD = 6;
//Moteurs Gauche
int PWDG = 11;
int DIRG = 7;
int InstantTime;
Mouvements cl;

void setup() {
Serial.begin(9600);
pinMode(PWDD, OUTPUT);
pinMode(DIRD, OUTPUT);
pinMode(PWDG, OUTPUT);
pinMode(DIRG, OUTPUT);
}


void loop() {
  InstantTime=millis();
  while ((millis()-InstantTime)<3000) {
    cl.Forward();
  }
  InstantTime=millis();
  while ((millis()-InstantTime)<3000) {
    cl.Backward();
  }
  InstantTime=millis();
  while ((millis()-InstantTime)<3000) {
    cl.Left();
  }
  InstantTime=millis();
  while ((millis()-InstantTime)<3000) {
    cl.Right();
  }

}
