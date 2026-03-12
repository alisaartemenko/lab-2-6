#include "Character.h"
#include <utility>

using namespace std;

Character::Character(const Character& other)
    : name(other.name + " (Clone)"), health(other.health), ranking(other.ranking) {
    cout << "Copy constructor called for " << name << endl;
}

Character::Character(Character&& other) noexcept
    : name(move(other.name)), health(other.health), ranking(move(other.ranking)) {

    other.health = 0;
    other.ranking = "None";

    cout << "Move constructor called. Original object is now empty." << endl;
}

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
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
}

void Character::updateStats(string name, int health) {
    this->name = name;
    this->health = health;

    cout << "Hero updated at memory address: " << this << endl;
}