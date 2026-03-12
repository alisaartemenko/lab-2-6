#ifndef LAB_2_6_ENEMY_H
#define LAB_2_6_ENEMY_H

#include <iostream>
#include <string>

using namespace std;

class Enemy {
private:
    string type;
    int damage;
    int hp;
public:
    Enemy(string t = "Goblin", int d = 50, int h = 100);

    ~Enemy();

    void attackEnemy (int damageDone);

    bool operator>(const Enemy& other) const;

    Enemy operator-() const;

    friend ostream& operator<<(ostream& os, const Enemy& e);
    friend istream& operator>>(istream& is, Enemy& e);
};

#endif //LAB_2_6_ENEMY_H