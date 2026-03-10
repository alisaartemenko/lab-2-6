#ifndef LAB_2_6_WEAPON_H
#define LAB_2_6_WEAPON_H

#include <iostream>
#include <string>

using namespace std;

class Weapon {
private:
    string title;
    int damage;
    int weight;
    bool isRare;
public:
    Weapon(string t, int d, int w, bool r);
    Weapon(string t, int d);

    ~Weapon();

    void upgradeWeapon (int addDamage);
};

#endif //LAB_2_6_WEAPON_H