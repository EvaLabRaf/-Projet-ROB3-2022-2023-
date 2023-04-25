#include "Mouvements.hpp"

Mouvements::Mouvements(){};

/*
For the PWD, 255 means 98 rpm
so 128 is for 49 rpm
By activating or not DIR, we can change the direction of rotation.
*/

void Mouvements::off() {
  analogWrite(PWDD, 0);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 0);
  digitalWrite(DIRG, HIGH);
}

void Mouvements::forward() {
  analogWrite(PWDD, 32);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 32);
  digitalWrite(DIRG, LOW);
}

void Mouvements::backward() {
  analogWrite(PWDD, 32);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 32);
  digitalWrite(DIRG, HIGH);
}

void Mouvements::left() {
  analogWrite(PWDD, 128);
  digitalWrite(DIRD, HIGH);
  analogWrite(PWDG, 0);
  digitalWrite(DIRG, LOW);
}

void Mouvements::right() {
  analogWrite(PWDD, 0);
  digitalWrite(DIRD, LOW);
  analogWrite(PWDG, 128);
  digitalWrite(DIRG, LOW);
}

void Mouvements::avanceForward(int temps) {
  Serial.println(F("==> avanceForward"));
  InstantTime = millis();
  //Serial.println(InstantTime);
  while ((millis() - InstantTime) < temps) {
    forward();
  }
  off();
}

void Mouvements::avanceBackward(int temps) {
  Serial.println(F("==> avanceBackward"));
  InstantTime = millis();
  //Serial.println(InstantTime);
  while ((millis() - InstantTime) < temps) {
    backward();
  }
  off();
}

void Mouvements::avanceLeft(int temps) {
  Serial.println(F("==> avanceLeft"));
  InstantTime = millis();
  //Serial.println(InstantTime);
  while ((millis() - InstantTime) < temps) {
    left();
  }
  off();
}

void Mouvements::avanceRight(int temps) {
  Serial.println(F("==> avanceRight"));
  InstantTime = millis();
  //Serial.println(InstantTime);
  while ((millis() - InstantTime) < temps) {
    right();
  }
  off();
}