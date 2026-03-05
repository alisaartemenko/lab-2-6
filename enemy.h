
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
};

#endif //LAB_2_6_ENEMY_H