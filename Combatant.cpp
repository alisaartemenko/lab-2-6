#include "Combatant.h"

Combatant::Combatant(string n, int h) : name(n), health(h) {
    cout << "[Combatant] " << name << " enters the battlefield." << endl;
}

Combatant::~Combatant() {
    cout << "[Combatant] " << name << " has been removed from memory." << endl;
}

void Combatant::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    cout << name << " took " << damage << " damage. Health now: " << health << endl;
}

void Combatant::showStats() const {
    cout << "Name: " << name << " | HP: " << health << endl;
}