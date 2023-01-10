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

void Mouvements::AvanceForward(){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    Forward();
  }
}

void Mouvements::Backward(){
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, LOW);
}

void Mouvements::AvanceBackward(){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    Backward();
  }
}


void Mouvements::Left(){
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 0);
  digitalWrite(DIRG, LOW);
}

void Mouvements::AvanceLeft(){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    Left();
  }
}

void Mouvements::Right(){
  analogWrite(PWDD, 0);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, HIGH);
}
  
void Mouvements::AvanceRight(){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<1000) {
    Right();
  }
}


