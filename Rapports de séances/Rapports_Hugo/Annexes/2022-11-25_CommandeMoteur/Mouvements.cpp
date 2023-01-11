#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/**
For the PWD, 255 means 98 rpm
so 128 is for 49 rpm
*/
void Mouvements::Off(){
  analogWrite(PWDD, 0);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG,0);
  digitalWrite(DIRG,HIGH);
}

void Mouvements::Forward(){
  analogWrite(PWDD, 64);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 64);
  digitalWrite(DIRG, HIGH);
}

void Mouvements::Backward(){
  analogWrite(PWDD, 64);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 64);
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

void Mouvements::AvanceForward(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Forward();
  }
}

void Mouvements::AvanceBackward(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Backward();
  }
}

void Mouvements::AvanceLeft(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Left();
  }
}

void Mouvements::AvanceRight(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Right();
  }
}

//void Mouvements::Evitement