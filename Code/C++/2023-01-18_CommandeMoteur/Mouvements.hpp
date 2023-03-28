#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H
#include "Arduino.h"

/*

*/

class Mouvements{
  public:
    Mouvements();
    unsigned long InstantTime;      //unsigned long permet d'avoir des chiffre allant jusqu'à 2^32 - 1
    const int PWDD = 5;
    const int DIRD = 12;
    const int PWDG = 6;
    const int DIRG = 13;
    void Off();
    void Forward();
    void Backward();
    void Left();
    void Right();
    void AvanceForward(int temps);
    void AvanceBackward(int temps);
    void AvanceRight(int temps);
    void AvanceLeft(int temps);
};

#endif