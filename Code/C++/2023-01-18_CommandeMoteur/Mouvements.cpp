#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/*
For the PWD, 255 means 98 rpm
so 128 is for 49 rpm
By activating or not DIR, we can change the direction of rotation.
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
  digitalWrite(DIRG, LOW);
}

void Mouvements::Backward(){
  analogWrite(PWDD, 64);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 64);
  digitalWrite(DIRG, HIGH);
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
  digitalWrite(DIRG, LOW);
}

void Mouvements::AvanceForward(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Forward();
  }
  Off();
}

void Mouvements::AvanceBackward(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Backward();
  }
  Off();
}

void Mouvements::AvanceLeft(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Left();
  }
  Off();
}

void Mouvements::AvanceRight(int temps){
  Serial.println(F("Forward"));
  InstantTime=millis();
  Serial.println(InstantTime);
  while ((millis()-InstantTime)<temps) {
    Right();
  }
  Off();
}