#include "weapon.h"

Weapon::Weapon(string t, int d, int w, bool r) : title(t), damage(d), weight(w), isRare(r) {
    cout << "New basic weapon (" << title << ") was added to inventory." << endl;
}

Weapon::Weapon(string t, int d) : title(t), damage(d), weight(0), isRare(true) {
    cout << "New magical weapon (" << title << ") was added to inventory." << endl;
}

Weapon::~Weapon() {
    cout << "Weapon " << title << " was deleted." << endl;
}

void Weapon::upgradeWeapon (int addDamage) {
    if (addDamage <= 10) {
        damage += addDamage;
    }
    else {
        cout << "You don't have enough materials to upgrade!" << endl;
    }
}