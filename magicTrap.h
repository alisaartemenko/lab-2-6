#ifndef UNTITLED1_MAGICTRAP_H
#define UNTITLED1_MAGICTRAP_H

#include "aSpellcaster.h"
#include <iostream>

using namespace std;

class magicTrap : public aSpellcaster {
public:
    void castSpell() const override {
        cout << "The Ancient Trap triggers a Frost Nova!" << endl;
    }
};


#endif //UNTITLED1_MAGICTRAP_H