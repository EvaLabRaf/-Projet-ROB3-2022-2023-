#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/**

*/

void Mouvements::Forward(){
  Serial.println("Forward");
  InstantTime=millis();
  while ((millis() - InstantTime) < 2000){
    digitalWrite(PWDD, HIGH);
    digitalWrite(DIRD, HIGH);
    digitalWrite(PWDG, HIGH);
    digitalWrite(DIRG, HIGH);
  }
  while((millis() - InstantTime) < 3000){
    digitalWrite(PWDD, LOW);
    digitalWrite(PWDG, LOW);
  }
}

void Mouvements::Backward(){
  Serial.println("Backward");
  InstantTime=millis();
  while ((millis() - InstantTime) < 2000){
    digitalWrite(PWDD, HIGH);
    digitalWrite(DIRD, LOW);
    digitalWrite(PWDG, HIGH);
    digitalWrite(DIRG, LOW);
  }
  while((millis() - InstantTime) < 3000){
    digitalWrite(PWDD, LOW);
    digitalWrite(PWDG, LOW);
  }
}

void Mouvements::Right(){
  Serial.println("Right");
  InstantTime=millis();
  while ((millis() - InstantTime) < 1000){
    digitalWrite(PWDD, LOW);
    digitalWrite(DIRD, LOW);
    digitalWrite(PWDG, HIGH);
    digitalWrite(DIRG, HIGH);
  }
  while((millis() - InstantTime) < 2000){
    digitalWrite(PWDD, LOW);
    digitalWrite(PWDG, LOW);
  }
}
  
void Mouvements::Left(){
  Serial.println("Left");
  InstantTime=millis();
  while ((millis() - InstantTime) < 1000){
    digitalWrite(PWDD, HIGH);
    digitalWrite(DIRD, HIGH);
    digitalWrite(PWDG, LOW);
    digitalWrite(DIRG, LOW);
  }
  while((millis() - InstantTime) < 2000){
    digitalWrite(PWDD, LOW);
    digitalWrite(PWDG, LOW);
  }
}