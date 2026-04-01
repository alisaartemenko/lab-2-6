#include "enemy.h"
#include "combatant.h"

Enemy::Enemy(string t, int d, int h) : Combatant(t, h), damage(d) {
    cout << "Enemy type: " << name << " is lurking nearby!" << endl;
}

Enemy::~Enemy () {
    cout << "Enemy " << name << " was deleted (from Enemy class)." << endl;
}

void Enemy::showStats() const {
    Combatant::showStats();
    cout << " | Damage: " << damage << endl;
}

void Enemy::takeDamage (int damage) {
    health -= damage;
    cout<< "Nice! " << name << " got damage = " << damage << endl;
}



void Enemy::shoutBattleCry() {
    cout<< name << " shouts: 'You are nothing but filth!'" << endl;
}

bool Enemy::operator>(const Enemy& other) const {
    return this->health > other.health;
}

Enemy Enemy::operator-() const {
    cout << "Curse applied to " << name << "! Damage halved!" << endl;
    return Enemy(this->type, this->damage / 2, this->health);
}

ostream& operator<<(ostream& os, const Enemy& e) {
    os << "ENEMY STATUS [" << e.name << " | HP: " << e.health << " | DMG: " << e.damage << "]";
    return os;
}

istream& operator>>(istream& is, Enemy& e) {
    cout << "Enter enemy type, damage and hp: ";
    is >> e.name >> e.damage >> e.health;
    return is;
}