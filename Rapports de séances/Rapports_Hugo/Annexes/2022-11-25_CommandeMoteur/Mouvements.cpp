#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/**

*/

void Mouvements::Forward(){
  Serial.println("Forward");
  digitalWrite(PWDD, HIGH);
  digitalWrite(DIRD, HIGH);
  digitalWrite(PWDG, HIGH);
  digitalWrite(DIRG, HIGH);
}

void Mouvements::Backward(){
  Serial.println("Backward");
  digitalWrite(PWDD, HIGH);
  digitalWrite(DIRD, LOW);
  digitalWrite(PWDG, HIGH);
  digitalWrite(DIRG, LOW);
}

void Mouvements::Right(){
  Serial.println("Right");
  digitalWrite(PWDD, LOW);
  digitalWrite(DIRD, LOW);
  digitalWrite(PWDG, HIGH);
  digitalWrite(DIRG, HIGH);
}
  
void Mouvements::Left(){
  Serial.println("Left");
  digitalWrite(PWDD, HIGH);
  digitalWrite(DIRD, HIGH);
  digitalWrite(PWDG, LOW);
  digitalWrite(DIRG, LOW);
}