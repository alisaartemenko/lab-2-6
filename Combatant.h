#ifndef UNTITLED1_COMBATANT_H
#define UNTITLED1_COMBATANT_H

#include <iostream>
#include <string>

using namespace std;

class Combatant {
protected:
    string name;
    int health;
public:
    Combatant(string n, int h);

    void takeDamage(int dmg);

    virtual void showStats() const;

    virtual ~Combatant();

};


#endif //UNTITLED1_COMBATANT_H