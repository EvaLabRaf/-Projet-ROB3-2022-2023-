#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H
#include "Arduino.h"

/**

*/

class Mouvements{
  public:
    Mouvements();
    const int PWDD = 10;
    const int DIRD = 6;
    const int PWDG = 11;
    const int DIRG = 7;
    void Forward();
    void Backward();
    void Left();
    void Right();
};

#endif