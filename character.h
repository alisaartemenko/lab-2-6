#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Combatant.h"
#include "weapon.h"
#include "aSpellcaster.h"

using namespace std;

class Character : public Combatant, public aSpellcaster {
private:
    string ranking;
    static int count;
    Weapon weapon;

public:

    Character(string n, int h, string r);
    Character(string n = "Traveler");

    Character(const Character& other);
    Character(Character&& other) noexcept;

    Character& operator=(const Character& other);
    Character& operator=(Character&& other) noexcept;

    ~Character() override;

    void takeDamage(int damage) override;
    void showStats() const override;
    void updateStats(string name, int health);
    static int getCount() {
        return count;
    }
    void shoutBattleCry() final;
    void uniqueTrait() override;
    void castSpell() const override;
};

#endif