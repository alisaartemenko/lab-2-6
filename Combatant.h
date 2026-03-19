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

    Combatant(const Combatant& other) = default;
    Combatant(Combatant&& other) noexcept = default;

    Combatant& operator=(const Combatant& other) {
        if (this != &other) {
            name = other.name;
            health = other.health;
        }
        return *this;
    }

    Combatant& operator=(Combatant&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            health = other.health;
        }
        return *this;
    }



};


#endif //UNTITLED1_COMBATANT_H