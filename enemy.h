#ifndef LAB_2_6_ENEMY_H
#define LAB_2_6_ENEMY_H

#include <iostream>
#include <string>
#include "Combatant.h"

using namespace std;

class Enemy : public Combatant {
protected:
    string type;
    int damage;
public:
    Enemy(string t = "Goblin", int d = 50, int h = 100);

    virtual ~Enemy();

    void showStats() const override;
    void takeDamage (int damage) override;
    void shoutBattleCry() final;

    bool operator>(const Enemy& other) const;

    Enemy operator-() const;

    friend ostream& operator<<(ostream& os, const Enemy& e);
    friend istream& operator>>(istream& is, Enemy& e);
};

#endif //LAB_2_6_ENEMY_H