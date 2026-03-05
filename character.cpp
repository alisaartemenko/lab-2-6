#include "Character.h"

Character::Character(string n, int h, string r) : name(n), health(h), ranking(r) {
    cout << "Character " << name << " created" << endl;
}

Character::Character(string n) : Character(n, 100, "Beginner") {}

Character::~Character() {
    cout << "Character " << name << " deleted" << endl;
}

void Character::takeDamage(int damage) {
    health -= damage;
}

void Character::showStats () {
    cout << "Health: " << health << endl;
}