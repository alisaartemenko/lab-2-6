#include "character.h"
#include <utility>
#include "Combatant.h"
#include <string>
#include "aSpellcaster.h"

using namespace std;

int Character::count = 0;

Character::Character(const Character& other)
    : Combatant(other),
    ranking(other.ranking),
    weapon(other.weapon){
    cout << "Copy constructor called for " << name << endl;
    count++;
}

Character::Character(Character&& other) noexcept
    : Combatant(move(other)),
    ranking(move(other.ranking)),
    weapon(std::move(other.weapon)) {

    count++;
    other.health = 0;
    other.ranking = "None";

    cout << "Move constructor called. Original object is now empty." << endl;
}

Character::Character(string n, int h, string r) : Combatant(n, h), ranking(r), weapon("Sword", 10) {
    cout << "Character " << name << " created" << endl;
    count++;
}

Character::Character(string n) : Character(n, 100, "Beginner") {}

Character::~Character() {
    count--;
    cout << "Character " << name << " deleted" << endl;
}


void Character::takeDamage(int damage) {
    health -= damage;
    cout<< "Ow! " << name << " got damage = " << damage << endl;
}

void Character::showStats() const {
    Combatant::showStats();
    cout << " | Rank: " << ranking << endl;
}

void Character::shoutBattleCry() {
    cout<< name << " shouts: 'The evil ones won't win!'" << endl;
}

void Character::updateStats(string name, int health) {
    this->name = name;
    this->health = health;

    cout << "Hero updated at memory address: " << this << endl;
}

void Character::uniqueTrait() {
    cout << name << " uses Special Skill: Divine Shield!" << endl;
}

void Character::castSpell() const {
    cout << name << " casts a Fireball spell!" << endl;
}

string Character::serialize() const {
    return "Character " + name + " " + to_string(health) + " " + ranking;
}

Character& Character::operator=(const Character& other) {
    if (this == &other) return *this;

    Combatant::operator=(other);
    this->ranking = other.ranking;
    this->weapon = other.weapon;

    cout << "Copy assignment operator called for " << name << endl;
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    cout << "Move assignment operator called for " << other.name << endl;
    if (this == &other) return *this;

    Combatant::operator=(std::move(other));

    this->ranking = std::move(other.ranking);
    this->weapon = std::move(other.weapon);

    return *this;
}