#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H
#include "Arduino.h"

/*

*/

class Mouvements {
public:
  Mouvements();
  unsigned long InstantTime;  //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1
  const int PWDD = 5;
  const int DIRD = 12;
  const int PWDG = 6;
  const int DIRG = 13;
  void off();
  void forward();
  void backward();
  void left();
  void right();
  void avanceForward(int temps);
  void avanceBackward(int temps);
  void avanceRight(int temps);
  void avanceLeft(int temps);
};

#endif