#include "Mouvements.hpp"

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
}


void loop() {
  cl.Forward();
  cl.Backward();
  cl.Left();
  cl.Right();
}
