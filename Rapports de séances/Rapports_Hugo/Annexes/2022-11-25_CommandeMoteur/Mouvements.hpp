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
    void Forward();
    void Backward();
    void Left();
    void Right();
    void AvanceForward();
    void AvanceBackward();
    void AvanceRight();
    void AvanceLeft();
};

#endif