#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/**
For the PWD, 255 means 98 rpm
so 128 is for 49 rpm
*/

void Mouvements::Forward(){
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, HIGH);
}

void Mouvements::Backward(){
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, LOW);
}

void Mouvements::Left(){
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 0);
  digitalWrite(DIRG, LOW);
}

void Mouvements::Right(){
  analogWrite(PWDD, 0);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, HIGH);
}
  


