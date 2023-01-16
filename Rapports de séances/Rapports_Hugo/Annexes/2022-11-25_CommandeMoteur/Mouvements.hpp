#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H
#include "Arduino.h"

/**

*/

class Mouvements{
  public:
    Mouvements();
    unsigned long InstantTime;
    const int PWDD = 10;
    const int DIRD = 6;
    const int PWDG = 11;
    const int DIRG = 7;
    void Off();
    void Forward();
    void Backward();
    void Left();
    void Right();
    void AvanceForward(int temps);
    void AvanceBackward(int temps);
    void AvanceRight(int temps);
    void AvanceLeft(int temps);
    void Evitement();
};

#endif